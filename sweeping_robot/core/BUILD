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
