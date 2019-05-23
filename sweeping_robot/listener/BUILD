package(
    default_visibility = [
        "//sweeping_robot:internal"
    ],
)

cc_library(
    name = "listener",
    hdrs = ["listener.h"],
    deps = [
        "@github_com_horanceliu_cub//cub/base:keywords",
    ],
)


cc_library(
    name = "staying_listener",
    hdrs = ["staying_listener.h"],
    srcs = ["staying_listener.cc"],    
    deps = [
        ":listener",
        "//sweeping_robot/core:point",
        "//sweeping_robot/action:alert_action",
    ],
)

cc_library(
    name = "path_listener",
    hdrs = ["path_listener.h"],
    srcs = ["path_listener.cc"],    
    deps = [
        ":listener",
        "//sweeping_robot/core:point",
        "//sweeping_robot/action:clean_action",
    ],
)
