<?php
	$active_menu_item = "index";
?>
<!doctype html>
<html lang="en">
	<?php include "parts/head.php"; ?>
	<body>
		<?php
			include "parts/header.php";
			include "parts/nav.php";
		?>
		<main class="container">
			<div class="row">
				<div class="col-md-2">
					<nav>
						<h3>Simple</h3>
						<ul class="nav nav-pills nav-stacked">
							<li class="active"><a data-toggle="pill" href="#example1">Example 1</a></li>
							<li><a data-toggle="pill" href="#example2">Example 2</a></li>
							<li><a data-toggle="pill" href="#example3">Example 3</a></li>
							<li><a data-toggle="pill" href="#example4">Example 4</a></li>
							<li><a data-toggle="pill" href="#example5">Example 5</a></li>
							<li><a data-toggle="pill" href="#example6">Example 6</a></li>
						</ul>
						<h3>Set queries</h3>
						<ul class="nav nav-pills nav-stacked">
							<li><a data-toggle="pill" href="#example7">Example 7</a></li>
							<li><a data-toggle="pill" href="#example8">Example 8</a></li>
							<li><a data-toggle="pill" href="#example9">Example 9</a></li>
						</ul>
					</nav>
				</div>
				<div class="col-md-10">
					<div class="tab-content">
						<div id="example1" class="tab-pane fade in active">
							<h3>Employees and their salaries</h3>
							<form action="run.php" method="get">
								<div class="form-group">
									<label for="gender">Gender:</label>
									<select class="form-control" id="gender" name="gender">
										<option>M</option>
										<option>F</option>
									</select>
								</div>
								<div class="form-group">
									<label for="from_date">From date: </label>
									<input type="date" class="form-control" id="from_date" name="from_date" value="1985-02-10">
								</div>
								<div class="form-group">
									<label for="to_date">To date: </label>
									<input type="date" class="form-control" id="to_date" name="to_date" value="1996-06-16">
								</div>
								<input type="hidden" name="example" value="1">
								<button type="submit" class="btn btn-primary">Submit</button>
							</form>
						</div>
						<div id="example2" class="tab-pane fade">
							<h3>Managers per department</h3>
							<form action="run.php" method="get">
								<div class="form-group">
									<label for="from_date">From date: </label>
									<input type="date" class="form-control" id="from_date" name="from_date" value="1985-09-12">
								</div>
								<div class="form-group">
									<label for="to_date">To date: </label>
									<input type="date" class="form-control" id="to_date" name="to_date" value="1996-06-16">
								</div>
								<input type="hidden" name="example" value="2">
								<button type="submit" class="btn btn-primary">Submit</button>
							</form>
						</div>
						<div id="example3" class="tab-pane fade">
							<h3>Average salary per title</h3>
							<form action="run.php" method="get">
								<div class="form-group">
									<label for="from_date">From date: </label>
									<input type="date" class="form-control" id="from_date" name="from_date" value="1985-02-10">
								</div>
								<div class="form-group">
									<label for="to_date">To date: </label>
									<input type="date" class="form-control" id="to_date" name="to_date" value="1996-06-16">
								</div>
								<input type="hidden" name="example" value="3">
								<button type="submit" class="btn btn-primary">Submit</button>
							</form>
						</div>
						<div id="example4" class="tab-pane fade">
							<h3>Employee's minimal salary</h3>
							<form action="run.php" method="get">
								<div class="form-group">
									<label for="from_date">From date: </label>
									<input type="date" class="form-control" id="from_date" name="from_date" value="1985-02-10">
								</div>
								<div class="form-group">
									<label for="to_date">To date: </label>
									<input type="date" class="form-control" id="to_date" name="to_date" value="1996-06-16">
								</div>
								<input type="hidden" name="example" value="4">
								<button type="submit" class="btn btn-primary">Submit</button>
							</form>
						</div>
						<div id="example5" class="tab-pane fade">
							<h3>Number of employees with title</h3>
							<form action="run.php" method="get">
								<div class="form-group">
									<label for="gender">Title:</label>
									<select class="form-control" id="title" name="title">
										<option>Assistant Engineer</option>
										<option>Engineer</option>
										<option>Manager</option>
										<option>Senior Engineer</option>
										<option>Senior Staff</option>
										<option>Staff</option>
										<option>Technique Leader</option>
									</select>
								</div>
								<div class="form-group">
									<label for="from_date">From date: </label>
									<input type="date" class="form-control" id="from_date" name="from_date" value="1985-02-10">
								</div>
								<div class="form-group">
									<label for="to_date">To date: </label>
									<input type="date" class="form-control" id="to_date" name="to_date" value="1996-06-16">
								</div>
								<input type="hidden" name="example" value="5">
								<button type="submit" class="btn btn-primary">Submit</button>
							</form>
						</div>
						<div id="example6" class="tab-pane fade">
							<h3>Employee's titles</h3>
							<form action="run.php" method="get">
								<div class="form-group">
									<label for="emp_no">Employee No: </label>
									<input type="number" class="form-control" id="emp_no" name="emp_no" value="10009">
								</div>
								<div class="form-group">
									<label for="from_date">From date: </label>
									<input type="date" class="form-control" id="from_date" name="from_date" value="1985-02-10">
								</div>
								<div class="form-group">
									<label for="to_date">To date: </label>
									<input type="date" class="form-control" id="to_date" name="to_date" value="1996-06-16">
								</div>
								<input type="hidden" name="example" value="6">
								<button type="submit" class="btn btn-primary">Submit</button>
							</form>
						</div>
						<div id="example7" class="tab-pane fade">
							<h3>Employees with some of my titles</h3>
							<form action="run.php" method="get">
								<div class="form-group">
									<label for="emp_no">Employee No: </label>
									<input type="number" class="form-control" id="emp_no" name="emp_no" value="10009">
								</div>
								<div class="form-group">
									<label for="from_date">From date: </label>
									<input type="date" class="form-control" id="from_date" name="from_date" value="1985-02-10">
								</div>
								<div class="form-group">
									<label for="to_date">To date: </label>
									<input type="date" class="form-control" id="to_date" name="to_date" value="1996-06-16">
								</div>
								<input type="hidden" name="example" value="7">
								<button type="submit" class="btn btn-primary">Submit</button>
							</form>
						</div>
						<div id="example8" class="tab-pane fade">
							<h3>My coworkers</h3>
							<form action="run.php" method="get">
								<div class="form-group">
									<label for="emp_no">Employee No: </label>
									<input type="number" class="form-control" id="emp_no" name="emp_no" value="108044">
								</div>
								<div class="form-group">
									<label for="from_date">From date: </label>
									<input type="date" class="form-control" id="from_date" name="from_date" value="1985-02-10">
								</div>
								<div class="form-group">
									<label for="to_date">To date: </label>
									<input type="date" class="form-control" id="to_date" name="to_date" value="2016-06-16">
								</div>
								<input type="hidden" name="example" value="8">
								<button type="submit" class="btn btn-primary">Submit</button>
							</form>
						</div>
						<div id="example9" class="tab-pane fade">
							<h3>Managers as me</h3>
							<form action="run.php" method="get">
								<div class="form-group">
									<label for="emp_no">Employee No: </label>
									<input type="number" class="form-control" id="emp_no" name="emp_no" value="111692">
								</div>
								<div class="form-group">
									<label for="from_date">From date: </label>
									<input type="date" class="form-control" id="from_date" name="from_date" value="1985-01-01">
								</div>
								<div class="form-group">
									<label for="to_date">To date: </label>
									<input type="date" class="form-control" id="to_date" name="to_date" value="2016-06-16">
								</div>
								<input type="hidden" name="example" value="9">
								<button type="submit" class="btn btn-primary">Submit</button>
							</form>
						</div>
					</div>
				</div>
			</main>
			<?php include "parts/footer.php" ?>
		</div>
	</body>
</html>
