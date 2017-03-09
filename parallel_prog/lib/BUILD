package(default_visibility = ["//visibility:public"])

cc_library(
		name = "pagerank",
		srcs = ["pagerank.cc"],
		hdrs = ["pagerank.h"],
		deps = [
				":page",
				":math",
		],
)

cc_library(
		name = "io",
		srcs = ["io.cc"],
		hdrs = ["io.h"],
		deps = [
				":page",
		],
)

cc_library(
		name = "logging",
		srcs = ["logging.cc"],
		hdrs = ["logging.h"],
		deps = [
				":utils",
		]
)

cc_library(
		name = "math",
		srcs = ["math.cc"],
		hdrs = ["math.h"],
)

cc_library(
		name = "utils",
		srcs = ["utils.cc"],
		hdrs = ["utils.h"],
)

cc_library(
		name = "page",
		srcs = ["page.cc"],
		hdrs = ["page.h"],
)

cc_library(
		name = "benchmark",
		srcs = ["benchmark.cc"],
		hdrs = ["benchmark.h"],
)
