package(default_visibility = ["//visibility:public"])

java_binary(
    name = "lab4",
    srcs = ["Main.java"],
    main_class = "io.github.lionell.lab4.Main",
    deps = [
    ],
)

java_binary(
    name = "server1",
    srcs = ["Server1.java"],
    main_class = "io.github.lionell.lab4.Server1",
    deps = [
        ":server",
    ],
)

java_binary(
    name = "server2",
    srcs = ["Server2.java"],
    main_class = "io.github.lionell.lab4.Server2",
    deps = [
        ":server",
    ],
)

java_library(
    name = "server",
    srcs = ["Server.java"],
    deps = [
    ],
)
