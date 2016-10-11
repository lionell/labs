package(default_visibility = ["//visibility:public"])

java_binary(
    name = "server1",
    srcs = ["Runner1.java"],
    main_class = "io.github.lionell.lab4.Runner1",
    deps = [
        ":server",
    ],
)

java_binary(
    name = "server2",
    srcs = ["Runner2.java"],
    main_class = "io.github.lionell.lab4.Runner2",
    deps = [
        ":server",
    ],
)

java_binary(
    name = "lab4",
    srcs = ["Main.java"],
    main_class = "io.github.lionell.lab4.Main",
    deps = [
        ":client",
    ],
)

java_library(
    name = "server",
    srcs = ["Server.java"],
    deps = [
    ],
)

java_library(
    name = "client",
    srcs = ["Client.java"],
    deps = [
    ],
)
