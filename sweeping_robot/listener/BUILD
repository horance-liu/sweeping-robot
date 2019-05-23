package(
    default_visibility = [
        "//sweeping_robot:internal"
    ],
)

cc_library(
    name = "listener",
    hdrs = ["listener.h"],
    srcs = ["listener.cc"],
    deps = [
        "//sweeping_robot/core:point",
        "//sweeping_robot/action:alert_action",
        "//sweeping_robot/action:clean_action",
        "@github_com_horanceliu_cub//cub/base:keywords",
    ],
)
