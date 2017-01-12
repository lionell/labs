<?php
	function db_connect() {
		require "config.php";
		$db = new mysqli($mysql_server_name, $mysql_username, $mysql_password, $mysql_db_name);
		if ($db->connect_error) {
			die("Connection to MySQL failed: " . $db->connect_error);
		}
		return $db;
	}
	function db_get_fields($db, $table) {
		$sql = "DESCRIBE {$table}";
		$result = $db->query($sql);
		$fields = array();
		if ($result->num_rows > 0) {
			while ($row = $result->fetch_assoc()) {
				$fields[] = $row["Field"];
			}
		} else {
			die("Table not found");
		}
		return $fields;
	}
	function db_insert($db, $table, $fields, $values) {
		$sql = "INSERT INTO {$table} (". join(", ", $fields) .") VALUES ('". join("', '", $values) ."')";
		if (!$db->query($sql)) {
			die("SQL: {$sql}. Error: {$db->error}");
		}
	}
	function db_update($db, $table, $key_field, $key_value, $fields, $values) {
		$field_value = array();
		for ($i = 0; $i < count($fields); $i++) {
			$field_value[] = "{$fields[$i]}='{$values[$i]}'";
		}
		$sql = "UPDATE {$table} SET ". join(", ", $field_value) ." WHERE {$key_field}='{$key_value}'";
		if (!$db->query($sql)) {
			die("SQL: {$sql}. Error: {$db->error}");
		}
	}
	function db_delete($db, $table, $key_field, $key_value) {
		$sql = "DELETE FROM {$table} WHERE {$key_field}='{$key_value}'";
		if (!$db->query($sql)) {
			die("SQL: {$sql}. Error: {$db->error}");
		}
	}

	// Select (men/women) with their salaries at some period of time
	function db_example1($db, $gender, $from_date, $to_date) {
		$sql = "SELECT first_name, last_name, gender, average_salary
				FROM employees
					JOIN (SELECT emp_no, AVG(salary) AS average_salary
							FROM salaries
							WHERE from_date >= '{$from_date}' AND to_date <= '{$to_date}'
							GROUP BY emp_no
						) AS emp_salary
						ON employees.emp_no = emp_salary.emp_no
				WHERE gender = '{$gender}'
				ORDER BY average_salary DESC
				LIMIT 20;";
		$result = $db->query($sql);
		return $result;
	}

	// Departments and managers at some period of time
	function db_example2($db, $from_date, $to_date) {
		$sql = "SELECT dept_name, first_name, last_name, from_date, to_date
				FROM departments
					JOIN dept_manager
						ON departments.dept_no = dept_manager.dept_no
					JOIN employees
						ON dept_manager.emp_no = employees.emp_no
				WHERE from_date >= '{$from_date}' AND to_date <= '{$to_date}'
				ORDER BY dept_name
				LIMIT 20;";
		$result = $db->query($sql);
		return $result;
	}

	// Average salary by title at some period of time
	function db_example3($db, $from_date, $to_date) {
		$sql = "SELECT title, AVG(avg_salary) AS average_salary
				FROM titles
					JOIN (SELECT emp_no, AVG(salary) AS avg_salary
							FROM salaries
							WHERE from_date >= '{$from_date}' AND to_date <= '{$to_date}'
							GROUP BY emp_no
						) AS emp_avg
						ON titles.emp_no = emp_avg.emp_no
				GROUP BY title
				ORDER BY average_salary DESC
				LIMIT 20;";
		$result = $db->query($sql);
		return $result;
	}

	// Minimal salary of employee at some period of time
	function db_example4($db, $from_date, $to_date) {
		$sql = "SELECT first_name, last_name, min_salary
				FROM employees
					JOIN (SELECT emp_no, MIN(salary) AS min_salary
							FROM salaries
							WHERE from_date >= '{$from_date}' AND to_date <= '{$to_date}'
							GROUP BY emp_no
						) AS emp_min_salary
						ON employees.emp_no = emp_min_salary.emp_no
				ORDER BY min_salary
				LIMIT 20;";
		$result = $db->query($sql);
		return $result;
	}

	// Number of employees with given title by department at some period of time
	function db_example5($db, $title, $from_date, $to_date) {
		$sql = "SELECT dept_name, COUNT(dept_emp.emp_no) AS emp_number
				FROM departments
					JOIN dept_emp
						ON departments.dept_no = dept_emp.dept_no
					JOIN titles
						ON titles.emp_no = dept_emp.emp_no
				WHERE dept_emp.from_date >= '{$from_date}' AND dept_emp.to_date <= '{$to_date}'
						AND titles.from_date >= '{$from_date}' AND titles.to_date <= '{$to_date}'
						AND title = '{$title}'
				GROUP BY dept_name
				ORDER BY emp_number DESC
				LIMIT 20;";
		$result = $db->query($sql);
		return $result;
	}

	// All the titles of particular employee
	function db_example6($db, $emp_no, $from_date, $to_date) {
		$sql = "SELECT title, from_date, to_date
				FROM titles
				WHERE from_date >= '{$from_date}' AND to_date <= '{$to_date}'
					AND emp_no = '{$emp_no}'
				ORDER BY from_date DESC
				LIMIT 20;";
		$result = $db->query($sql);
		return $result;
	}

	// Employees with some of my titles
	function db_example7($db, $emp_no, $from_date, $to_date) {
		$sql = "SELECT emp_no, first_name, last_name
			FROM employees AS e
			WHERE NOT EXISTS (
				SELECT *
				FROM titles
				WHERE emp_no = e.emp_no AND from_date >= '{$from_date}' AND to_date <= '{$to_date}' AND title NOT IN (
					SELECT title
					FROM titles
					WHERE emp_no = {$emp_no} AND from_date >= '{$from_date}' AND to_date <= '{$to_date}'
				)
			)
			ORDER BY emp_no
			LIMIT 20;";
		$result = $db->query($sql);
		return $result;
	}

	// Employees at the same department as me
	function db_example8($db, $emp_no, $from_date, $to_date) {
		$sql = "SELECT e.emp_no, first_name, last_name
				FROM dept_emp as e
					JOIN employees
						ON e.emp_no = employees.emp_no
				WHERE from_date >= '{$from_date}' AND to_date <= '{$to_date}'
					AND NOT EXISTS (
						SELECT *
						FROM dept_emp
						WHERE emp_no = {$emp_no} AND from_date >= '{$from_date}' AND to_date <= '{$to_date}' AND dept_no NOT IN (
							SELECT dept_no
							FROM dept_emp
							WHERE emp_no = e.emp_no AND from_date >= '{$from_date}' AND to_date <= '{$to_date}'
						)
					) AND NOT EXISTS (
						SELECT *
						FROM dept_emp
						WHERE emp_no = e.emp_no AND from_date >= '{$from_date}' AND to_date <= '{$to_date}' AND dept_no NOT IN (
							SELECT dept_no
							FROM dept_emp
							WHERE emp_no = {$emp_no} AND from_date >= '{$from_date}' AND to_date <= '{$to_date}'
						)
					)
				ORDER BY e.emp_no
				LIMIT 20;";
		$result = $db->query($sql);
		return $result;
	}

	// Find employees managed by some of my managers
	function db_example9($db, $emp_no, $from_date, $to_date) {
		$sql = "SELECT e.emp_no, first_name, last_name, dept_no
			FROM dept_manager AS e
				JOIN employees
					ON e.emp_no = employees.emp_no
			WHERE NOT EXISTS (
				SELECT *
				FROM dept_manager
				WHERE emp_no = '{$emp_no}' AND from_date >= '{$from_date}' AND to_date <= '{$to_date}' AND dept_no NOT IN (
					SELECT dept_no
					FROM dept_manager
					WHERE emp_no = e.emp_no AND from_date >= '{$from_date}' AND to_date <= '{$to_date}'
				)
			)
			ORDER BY emp_no
			LIMIT 20;";
		$result = $db->query($sql);
		return $result;
	}

	// Find employees whose salaries are superset of mein
	function db_example10($db, $emp_no, $from_date, $to_date) {
		$sql = "SELECT emp_no, first_name, last_name
			FROM employees AS e
			WHERE NOT EXISTS (
				SELECT *
				FROM salaries
				WHERE emp_no = '{$emp_no}' AND from_date >= '{$from_date}' AND to_date <= '{$to_date}' AND salary NOT IN (
					SELECT salary
					FROM salaries
					WHERE emp_no = e.emp_no AND from_date >= '{$from_date}' AND to_date <= '{$to_date}'
				)
			)
			ORDER BY emp_no
			LIMIT 20;";
		$result = $db->query($sql);
		return $result;
	}
?>
