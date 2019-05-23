package(
    default_visibility = [
        "//sweeping_robot:internal"
    ],
)

licenses(["notice"])  # Apache 2.0

exports_files(["LICENSE"])

package_group(
    name = "internal",
    packages = [
        "//sweeping_robot/...",
    ],
)

cc_library(
    name = "sweeping_robot",
    hdrs = ["sweeping_robot.h"],
    srcs = ["sweeping_robot.cc"],
    deps = [
        "//sweeping_robot/cmd",
        "//sweeping_robot/rule",
        "//sweeping_robot/core:position",
    ],
)

cc_test(                 
    name = "sweeping_robot_test", 
    srcs = ["sweeping_robot_test.cc"], 
    deps = [       
        ":sweeping_robot",   
        "@github_com_horanceliu_cut//:cut",       
        "@github_com_horanceliu_cut//:cut_main",        
    ],
)