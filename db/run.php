<?php
	require "db.php";
	$db = db_connect();
	if (!isset($_GET["example"])) {
		die("No example specified");
	}
	switch ($_GET["example"]) {
	case 1:
		$result = db_example1($db, $_GET["gender"], $_GET["from_date"], $_GET["to_date"]);
		break;
	case 2:
		$result = db_example2($db, $_GET["from_date"], $_GET["to_date"]);
		break;
	case 3:
		$result = db_example3($db, $_GET["from_date"], $_GET["to_date"]);
		break;
	case 4:
		$result = db_example4($db, $_GET["from_date"], $_GET["to_date"]);
		break;
	case 5:
		$result = db_example5($db, $_GET["title"], $_GET["from_date"], $_GET["to_date"]);
		break;
	case 6:
		$result = db_example6($db, $_GET["emp_no"], $_GET["from_date"], $_GET["to_date"]);
		break;
	case 7:
		$result = db_example7($db, $_GET["emp_no"], $_GET["from_date"], $_GET["to_date"]);
		break;
	case 8:
		$result = db_example8($db, $_GET["emp_no"], $_GET["from_date"], $_GET["to_date"]);
		break;
	case 9:
		$result = db_example9($db, $_GET["emp_no"], $_GET["from_date"], $_GET["to_date"]);
		break;
	}
	$active_menu_item = "none";
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
			<h2 class="text-center">Example <?php echo $_GET["example"]; ?></h2>
			<?php
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
					echo "</tr></thead>\n";
					echo "<tbody>\n";
					do {
						echo "<tr>";
						foreach ($fields as $field) {
							echo "<td>{$row[$field]}</td>";
						}
						echo "</tr>\n";
					} while ($row = $result->fetch_assoc());
					echo "</tbody>
						</table>
						</div>\n";
				} else {
					echo "Result have no rows :(";
				}
			?>
		</main>
		<?php include "parts/footer.php" ?>
	</body>
</html>
