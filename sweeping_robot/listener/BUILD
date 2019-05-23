package(
    default_visibility = [
        "//sweeping_robot:internal"
    ],
)

cc_library(
    name = "action_describing",
    hdrs = ["action_describing.h"],
    deps = [
        "@github_com_horanceliu_cub//cub/base:keywords",
    ],
)

cc_library(
    name = "listener",
    hdrs = ["listener.h"],
    srcs = ["listener.cc"],
    deps = [
        ":action_describing",
        "//sweeping_robot/out",
        "//sweeping_robot/core:point",
    ],
)
