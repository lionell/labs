package(default_visibility = ["//visibility:public"])

java_binary(
    name = "lab1",
    srcs = ["Runner.java"],
    main_class = "io.github.lionell.lab1.Runner",
    deps = [
        ":cliques_finder",
        ":frequency_sorter",
        "//java/io/github/lionell/lab1/io",
        "//third_party:guava",
    ],
)

java_library(
    name = "frequency_sorter",
    srcs = ["FrequencySorter.java"],
    deps = [
        "//third_party:guava",
    ],
)

java_library(
    name = "cliques_finder",
    srcs = ["CliquesFinder.java"],
    deps = [
        "//java/io/github/lionell/lab1/util:iterator",
        "//java/io/github/lionell/lab1/util:sets",
        "//third_party:guava",
    ],
)
