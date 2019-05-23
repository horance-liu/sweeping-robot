workspace(name = "sweeping_robot")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "github_com_horanceliu_cub",
    sha256 = "f365f72b50dc41650b19ed3fea9ecd09abb711ef03a30fba6e807a183c88825d",
    strip_prefix = "cub-release-1.0",                                               
    urls = [
        "https://github.com/horance-liu/cub/archive/release-1.0.tar.gz",
    ],      
)

http_archive(
    name = "github_com_horanceliu_cut",
    sha256 = "ade2831913d5be97edaa87c3f7d047262a59e266c30ff0a5f2d3edac08b4480e",
    strip_prefix = "cut-release-v1.0",
    urls = [ 
        "https://github.com/horance-liu/cut/archive/release-v1.0.tar.gz",
    ],  
)

