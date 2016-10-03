package(default_visibility = ["//visibility:public"])

java_binary(
    name = "lab2",
    srcs = ["Runner.java"],
    main_class = "io.github.lionell.lab2.Runner",
    deps = [
        ":checker",
        ":nfa",
    ],
)

java_library(
    name = "checker",
    srcs = ["Checker.java"],
    deps = [
        ":nfa",
        "//java/io/github/lionell/lab2/util",
    ],
)

java_library(
    name = "nfa",
    srcs = ["NFA.java"],
    deps = [
        "//third_party:guava",
    ],
)
