workspace(name = "sweeping_robot")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# curl -L https://github.com/horance-liu/cub/archive/release-1.0.tar.gz | sha256sum
http_archive(
    name = "github_com_horanceliu_cub",
    sha256 = "f365f72b50dc41650b19ed3fea9ecd09abb711ef03a30fba6e807a183c88825d",
    strip_prefix = "cub-release-1.0",                                               
    urls = [
        "https://github.com/horance-liu/cub/archive/release-1.0.tar.gz",
    ],      
)

# using cut for xunit test framework.
# curl -L https://github.com/horance-liu/cut/archive/release-1.0.tar.gz | sha256sum
http_archive(
    name = "github_com_horanceliu_cut",
    sha256 = "ade2831913d5be97edaa87c3f7d047262a59e266c30ff0a5f2d3edac08b4480e",
    strip_prefix = "cut-release-v1.0",
    urls = [ 
        "https://github.com/horance-liu/cut/archive/release-v1.0.tar.gz",
    ],  
)

http_archive(
    name = "github_com_nlohmann_json",
    sha256 = "69cc88207ce91347ea530b227ff0776db82dcb8de6704e1a3d74f4841bc651cf",
    urls = [ 
        "https://github.com/nlohmann/json/releases/download/v3.6.1/include.zip",
    ],
    build_file = "//third_party:nlohmann_json.BUILD",
)
