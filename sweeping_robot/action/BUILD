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
    name = "alert_action",
    hdrs = ["alert_action.h"],
    srcs = ["alert_action.cc"],    
    deps = [
        ":action_describing",
        "//sweeping_robot/out",
        "//sweeping_robot/core:point",
    ],
)

cc_library(
    name = "clean_action",
    hdrs = ["clean_action.h"],
    srcs = ["clean_action.cc"],    
    deps = [
        ":action_describing",
        "//sweeping_robot/out",
        "//sweeping_robot/core:point",
    ],
)

