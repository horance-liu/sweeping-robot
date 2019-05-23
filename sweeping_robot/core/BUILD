package(
    default_visibility = [
        "//sweeping_robot:internal"
    ],
)

cc_library(
    name = "point",
    hdrs = ["point.h"],
    srcs = ["point.cc"],
    deps = [
        "@github_com_horanceliu_cub//cub/base:comparator",
    ],
)

cc_library(
    name = "direction",
    hdrs = ["direction.h"],
    srcs = ["direction.cc"],
    deps = [
        ":point",
        "@github_com_horanceliu_cub//cub/base:comparator",
    ],
)

cc_library(
    name = "position",
    hdrs = ["position.h"],
    srcs = ["position.cc"],
    deps = [
        ":direction",
        ":point",        
    ],
)

cc_library(
    name = "sweeping_robot",
    hdrs = ["sweeping_robot.h"],
    srcs = ["sweeping_robot.cc"],
    deps = [
        ":position",
        "//sweeping_robot/cmd",
        "//sweeping_robot/rule",
    ],
)

cc_test(                 
    name = "sweeping_robot_test", 
    srcs = ["sweeping_robot_test.cc"], 
    deps = [
        ":sweeping_robot",
        "//sweeping_robot/rule:default_rule",
        "//sweeping_robot/listener:staying_listener",
        "//sweeping_robot/listener:path_listener",
        "//sweeping_robot/out:text_output",
        "//sweeping_robot/out:json_output",
        "@github_com_horanceliu_cub//cub/string:str_printf",        
        "@github_com_horanceliu_cut//:cut",
        "@github_com_horanceliu_cut//:cut_main",
    ],
)
