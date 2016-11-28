<?php
	require "config.php";
	require "db.php";
	$db = db_connect();
	if (!isset($_GET["table"])) {
		die("No table specified");
	}
	$active_menu_item = $_GET["table"];
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
						<h3>Actions</h3>
						<ul class="nav nav-pills nav-stacked">
							<li class="active"><a data-toggle="pill" href="#view">View</a></li>
							<li><a data-toggle="pill" href="#modify">Modify</a></li>
						</ul>
					</nav>
				</div>
				<div class="col-md-10">
					<div class="tab-content">
						<div id="view" class="tab-pane fade in active">
							<h2 class="text-center">View</h2>
							<?php
								$sql = "SELECT * FROM {$_GET["table"]} LIMIT {$default_select_limit}";
								$result = $db->query($sql);
								if ($result->num_rows > 0) {
								echo "<div class='table-responsive'>
									<table class='table table-hover'>
									<thead><tr>";
									$row = $result->fetch_assoc();
									$fields = array_keys($row);
									foreach ($fields as $field) {
										echo "<th>{$field}</th>";
									}
									$key = $fields[0];
									echo "<th><span class='glyphicon glyphicon-trash' aria-hidden='true'></span></th>";
									echo "</tr></thead>\n";
									echo "<tbody>\n";
									do {
										echo "<tr>";
										foreach ($fields as $field) {
											echo "<td>{$row[$field]}</td>";
										}
										echo "<td><a href='modify.php?type=delete&table={$_GET["table"]}&{$key}={$row[$key]}'>
												<span class='glyphicon glyphicon-remove' aria-hidden='true'></span></a></td>";
										echo "</tr>\n";
									} while ($row = $result->fetch_assoc());
									echo "</tbody>
										</table>
										</div>\n";
								} else {
									echo "No flights found :(";
								}
							?>
						</div>
						<div id="modify" class="tab-pane fade">
							<h2 class="text-center">Modify</h2>
							<form action="modify.php" method="get">
								<?php
									foreach ($fields as $field) {
										echo "<div class='form-group'>
											<label for='{$field}'>${field}</label>
											<input type='text' class='form-control' id='{$field}' name='{$field}' size='20'>
											</div>";
									}
								?>
								<input type="hidden" name="table" value="<?php echo $_GET["table"]; ?>">
								<input type="hidden" name="type" id="type" value="insert">
								<script language="javascript">
									function insert_click() {
										e = document.getElementById('type');
										e.value = 'insert';
									}
									function update_click() {
										e = document.getElementById('type');
										e.value = 'update';
									}
								</script>
								<button type="submit" class="btn btn-primary" onclick="insert_click();">Insert</button>
								<button type="submit" class="btn btn-primary" onclick="update_click();">Update</button>
							</form>
						</div>
					</div>
				</div>
			</main>
			<?php include "parts/footer.php" ?>
		</div>
	</body>
</html>
