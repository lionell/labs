package(default_visibility = ["//visibility:public"])

py_binary(
		name = "generate_dataset",
		srcs = ["generate_dataset.py"],
)

py_binary(
		name = "evaluate_norm",
		srcs = ["evaluate_norm.py"],
)

cc_binary(
		name = "generate_dataset_cc",
		srcs = ["generate_dataset.cc"],
		deps = [
				"//lib:benchmark",
				"//proto:chunk_cc_proto",
				"//proto:metadata_cc_proto",
		],
		linkopts = [
				"-lgflags",
				"-lglog",
		],
)
