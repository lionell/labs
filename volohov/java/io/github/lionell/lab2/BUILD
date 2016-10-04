package(default_visibility = ["//visibility:public"])

java_binary(
    name = "lab2",
    srcs = ["Runner.java"],
    main_class = "io.github.lionell.lab2.Runner",
    deps = [
        ":nfa",
    ],
)

java_library(
    name = "nfa",
    srcs = ["NFA.java"],
    deps = [
        "//java/io/github/lionell/lab2/util",
        "//third_party:guava",
    ],
)
