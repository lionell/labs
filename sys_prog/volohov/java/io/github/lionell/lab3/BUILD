package(default_visibility = ["//visibility:public"])

java_binary(
    name = "lab3",
    srcs = ["Runner.java"],
    main_class = "io.github.lionell.lab3.Runner",
    deps = [
        ":highlighter",
        "//third_party:guava",
    ],
)

java_library(
    name = "highlighter",
    srcs = ["Highlighter.java"],
    deps = [
        ":lexeme",
    ],
)

java_library(
    name = "lexeme",
    srcs = ["Lexeme.java"],
    deps = [
        "//java/io/github/lionell/lab3/io",
        "//third_party:guava",
    ],
)
