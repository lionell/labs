# Work like a DB :)
This is site based on test DB, to run some example SQL queries.

## Run in Docker LAMP container
```sh
$ docker run -p 8000:80 -p 2200:22 -p 3306:3306 -v /path/to/project/root:/var/www/html:rw dockie/lamp
```

See Dockerfile here: https://github.com/RobLoach/Dockie/tree/master/lamp

## Example queries

**NOTE!** All the queries as parametrized with date window `[from_date, to_date]`.

1. Select employees of `{$gender}` and their salaries.

	```sql
	SELECT first_name, last_name, gender, average_salary
	FROM employees
		JOIN (SELECT emp_no, AVG(salary) AS average_salary
				FROM salaries
				WHERE from_date >= '{$from_date}' AND to_date <= '{$to_date}'
				GROUP BY emp_no
			) AS emp_salary
			ON employees.emp_no = emp_salary.emp_no
	WHERE gender = '{$gender}'
	ORDER BY average_salary DESC
	LIMIT 20;
	```

2. Select managers by department.

	```sql
	SELECT dept_name, first_name, last_name, from_date, to_date
	FROM departments
		JOIN dept_manager
			ON departments.dept_no = dept_manager.dept_no
		JOIN employees
			ON dept_manager.emp_no = employees.emp_no
	WHERE from_date >= '{$from_date}' AND to_date <= '{$to_date}'
	ORDER BY dept_name
	LIMIT 20;
	```

3. Get average salary per title.

	```sql
	SELECT title, AVG(avg_salary) AS average_salary
	FROM titles
		JOIN (SELECT emp_no, AVG(salary) AS avg_salary
				FROM salaries
				WHERE from_date >= '{$from_date}' AND to_date <= '{$to_date}'
				GROUP BY emp_no
			) AS emp_avg
			ON titles.emp_no = emp_avg.emp_no
	GROUP BY title
	ORDER BY average_salary DESC
	LIMIT 20;
	```

4. Minimal salary of employee with `{$emp_no}`.

	```sql
	SELECT first_name, last_name, min_salary
	FROM employees
		JOIN (SELECT emp_no, MIN(salary) AS min_salary
				FROM salaries
				WHERE from_date >= '{$from_date}' AND to_date <= '{$to_date}'
				GROUP BY emp_no
			) AS emp_min_salary
			ON employees.emp_no = emp_min_salary.emp_no
	ORDER BY min_salary
	LIMIT 20;
	```

5. Number of employees with `{$title}` per department.

	```sql
	SELECT dept_name, COUNT(dept_emp.emp_no) AS emp_number
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
	LIMIT 20;
	```
6. List titles of particular employee with `{$emp_no}`.

	```sql
	SELECT title, from_date, to_date
	FROM titles
	WHERE from_date >= '{$from_date}' AND to_date <= '{$to_date}'
		AND emp_no = '{$emp_no}'
	ORDER BY from_date DESC
	LIMIT 20;
	```

## Set comparisons

7. Employees with some titles of `{$emp_no}`.

	```sql
	SELECT titles.emp_no, first_name, last_name, title, from_date, to_date
	FROM employees
		JOIN titles
			ON employees.emp_no = titles.emp_no
	WHERE from_date >= '{$from_date}' AND to_date <= '{$to_date}'
		AND title
		IN (SELECT title
			FROM titles
			WHERE from_date >= '{$from_date}' AND to_date <= '{$to_date}'
				AND emp_no = '{$emp_no}'
		)
	ORDER BY titles.emp_no
	LIMIT 20;
	```

8. Employees working at the same department as `{$emp_no}`.

	```sql
	SELECT dept_emp.emp_no, first_name, last_name, dept_emp.dept_no, from_date, to_date
	FROM dept_emp
		JOIN employees
			ON dept_emp.emp_no = employees.emp_no
	WHERE from_date >= '{$from_date}' AND to_date <= '{$to_date}'
		AND dept_no 
		IN (SELECT dept_no
			FROM dept_emp
			WHERE from_date >= '{$from_date}' AND to_date <= '{$to_date}'
				AND emp_no = '{$emp_no}'
		)
	ORDER BY dept_emp.emp_no
	LIMIT 20;
	```

9. Find employees managed by some of managers of `{$emp_no}`.

	```sql
	SELECT dept_manager.emp_no, first_name, last_name, dept_manager.dept_no, from_date, to_date
	FROM dept_manager
		JOIN employees
			ON dept_manager.emp_no = employees.emp_no
	WHERE from_date >= '{$from_date}' AND to_date <= '{$to_date}'
		AND dept_no 
		IN (SELECT dept_no
			FROM dept_manager
			WHERE from_date >= '{$from_date}' AND to_date <= '{$to_date}'
				AND emp_no = '{$emp_no}'
		)
	ORDER BY dept_manager.emp_no
	LIMIT 20;
	```
