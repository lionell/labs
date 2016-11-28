<nav>
	<ul class="nav nav-tabs nav-justified">
		<li <?php if ($active_menu_item == "index") echo "class='active'"; ?>>
			<a href="index.php">Queries</a>
		</li>
		<li <?php if ($active_menu_item == "departments") echo "class='active'"; ?>>
			<a href="show.php?table=departments">Departments</a>
		</li>
		<li <?php if ($active_menu_item == "dept_emp") echo "class='active'"; ?>>
			<a href="show.php?table=dept_emp">Dept. employees</a>
		</li>
		<li <?php if ($active_menu_item == "dept_manager") echo "class='active'"; ?>>
			<a href="show.php?table=dept_manager">Dept. manager</a>
		</li>
		<li <?php if ($active_menu_item == "employees") echo "class='active'"; ?>>
			<a href="show.php?table=employees">Employees</a>
		</li>
		<li <?php if ($active_menu_item == "salaries") echo "class='active'"; ?>>
			<a href="show.php?table=salaries">Salaries</a>
		</li>
		<li <?php if ($active_menu_item == "titles") echo "class='active'"; ?>>
			<a href="show.php?table=titles">Titles</a>
		</li>
	</ul>
</nav>

