# Work like a DB :)
This is site based on test DB, to run some example SQL queries.

## Run in Docker LAMP container
```
docker run -p 8000:80 -p 2200:22 -p 3306:3306 -v /path/to/project/root:/var/www/html:rw dockie/lamp
```

See Dockerfile here: https://github.com/RobLoach/Dockie/tree/master/lamp

## Example queries

**NOTE!** All the queries as parametrized with date window `[from_date, to_date]`

1. Select (men/women) and their salaries

	```
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
	LIMIT 20;";
	```
2. Departments with their managers at particular date window.
	SELECT dept_name, first_name, last_name
	FROM departments
		JOIN dept_manager
			ON departments.dept_no = dept_manager.dept_no
		JOIN employees
			ON dept_manager.emp_no = employees.emp_no
	WHERE dept_manager.from_date BETWEEN '1985-01-01' AND '1991-10-01'
	ORDER BY dept_name;
3. Average salary by title at particular date window.
	SELECT title, AVG(avg_salary) AS average_salary
	FROM titles
		JOIN (
				SELECT emp_no, AVG(salary) AS avg_salary
				FROM salaries
				WHERE from_date > '1986-06-26' and to_date < '2002-06-22'
				GROUP BY emp_no
			) AS emp_avg
			ON titles.emp_no = emp_avg.emp_no
	GROUP BY title
	ORDER BY title;
4. Employees with their minimal salary at particular date window.
	SELECT first_name, last_name, min_salary
	FROM employees
		JOIN (
				SELECT emp_no, MIN(salary) AS min_salary
				FROM salaries
				WHERE from_date > '1986-06-26' and to_date < '2002-06-22'
				GROUP BY emp_no
			) AS emp_min_salary
			ON employees.emp_no = emp_min_salary.emp_no
	ORDER BY min_salary;
5. Number of employees by department at particular date window.
	SELECT dept_name, COUNT(emp_no) AS emp_number
	FROM departments
		JOIN dept_emp
			ON departments.dept_no = dept_emp.dept_no
	WHERE from_date > '1986-06-26' and to_date < '2002-06-22'
	GROUP BY dept_name
	ORDER BY emp_number DESC;
7. Select employees with the same titles as employee with specified No.
	SELECT titles.emp_no, first_name, last_name
	FROM employees
		JOIN titles
			ON employees.emp_no = titles.emp_no
	WHERE title 
		IN (SELECT title
			FROM titles
			WHERE from_date >= '1900-01-01' AND to_date <= '2100-01-01' 
				AND emp_no = '10009'
		);
8.
	SELECT emp_no
	FROM dept_emp
	WHERE from_date >= '1900-01-01' AND to_date <= '2100-01-01'
		AND dept_no IN
		(SELECT dept_no
		FROM dept_emp
		WHERE from_date >= '1900-01-01' AND to_date <= '2100-01-01'
			AND emp_no = '108044')
9. Select employees who was managers at the same departments as me
	SELECT emp_no
	FROM dept_manager
	WHERE from_date >= '1900-01-01' AND to_date <= '2100-01-01'
		(SELECT dept_no
		FROM dept_emp
		WHERE from_date >= '1900-01-01' AND to_date <= '2100-01-01'
			AND emp_no = '108044')
