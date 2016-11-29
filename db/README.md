# Work like a DB :)
This is site based on test DB, to run some example SQL queries.

## Run in Docker LAMP container
```
docker run -p 8000:80 -p 2200:22 -p 3306:3306 -v /path/to/project/root:/var/www/html:rw dockie/lamp
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

4. Minimal salary of employee with `{$emp_no}`
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
