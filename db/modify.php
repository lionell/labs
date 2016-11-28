<?php
	require "db.php";
	if (!isset($_GET["type"])) {
		die("No operation type specified");
	}
	if (!isset($_GET["table"])) {
		die("No table specified");
	}

	$db = db_connect();
	$fields = db_get_fields($db, $_GET["table"]);
	$key = $fields[0];

	switch ($_GET["type"]) {
	case "insert":
		$values = array();
		foreach ($fields as $field) {
			$values[] = $_GET[$field];
		}
		db_insert($db, $_GET["table"], $fields, $values);
		break;
	case "update":
		$values = array();
		foreach ($fields as $field) {
			$values[] = $_GET[$field];
		}
		db_update($db, $_GET["table"], $key, $_GET[$key], $fields, $values);
		break;
	case "delete":
		db_delete($db, $_GET["table"], $key, $_GET[$key]);
		break;
	default:
		die("Unknown opeartion type");
	}
	header("Location: {$_SERVER["HTTP_REFERER"]}");
	die();
?>
