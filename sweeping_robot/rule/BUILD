package(
    default_visibility = [
        "//sweeping_robot:internal"
    ],
)

cc_library(
    name = "rule",
    hdrs = ["rule.h"],
    srcs = ["rule.cc"],
    deps = [
        "@github_com_horanceliu_cub//cub/base:keywords",
    ],
)

cc_library(
    name = "default_rule",
    hdrs = ["default_rule.h"],
    srcs = ["default_rule.cc"],
    deps = [
        ":rule",
        "//sweeping_robot/listener",
        "//sweeping_robot/core:position",        
    ],
)

