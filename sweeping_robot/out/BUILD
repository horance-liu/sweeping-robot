package(
    default_visibility = [
        "//sweeping_robot:internal"
    ],
)

cc_library(
    name = "out",
    hdrs = ["output.h"],
    srcs = ["output.cc"],
    deps = [
        "//sweeping_robot/core:point",
        "//sweeping_robot/listener:action_describing",
        "@github_com_horanceliu_cub//cub/string:str_printf",
    ],
)
