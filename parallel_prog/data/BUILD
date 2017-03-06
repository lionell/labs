package(default_visibility = ["//visibility:public"])

filegroup(
		name = "data",
		srcs = [
				":test",
				":full",
				":generated",
		],
)

filegroup(
		name = "test",
		srcs = glob(["test/*"]),
)

filegroup(
		name = "full",
		srcs = glob(["full/*"]),
)

filegroup(
		name = "generated",
		srcs = glob(["generated/*"]),
)
