licenses(["notice"])  # Apache 2.0
  
exports_files(["LICENSE"])

cc_library(
    name = "sweeping_robot",
    hdrs = [
        "command.h",        
        "direction.h",
        "point.h",
        "position.h",
        "sweeping_robot.h",        
    ],
    srcs = [
        "command.cc",
        "direction.cc",
        "point.cc",
        "position.cc",
        "sweeping_robot.cc",
    ],
    deps = [
        "@github_com_horanceliu_cub//cub/base:comparator",
        "@github_com_horanceliu_cub//cub/algo:range",        
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
