cc_binary(
		name = "random",
		srcs = ["random.cc"],
		deps = [
				":benchmark",
				":io",
		],
		copts = [
				"-fopenmp",
		],
		linkopts = [
				"-fopenmp",
				"-lgflags",
				"-lglog",
		],
)

cc_library(
		name = "benchmark",
		hdrs = ["benchmark.h"],
)

cc_library(
		name = "io",
		hdrs = ["io.h"],
)

py_binary(
		name = "concat",
		srcs = ["concat.py"],
)
