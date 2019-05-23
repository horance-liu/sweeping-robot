package(
    default_visibility = [
        "//sweeping_robot:internal"
    ],
)

cc_library(
    name = "cmd",
    hdrs = ["command.h"],
    srcs = ["command.cc"],
    deps = [
        "//sweeping_robot/rule",
        "//sweeping_robot/core:position",
        "@github_com_horanceliu_cub//cub/algo:range",
    ],
)
