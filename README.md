# Sweeping Robot 

## Requirement

- [bazel](https://www.bazel.build)
- compiler: should support c++14 or above

## Docker

build develop image.

```bash
$ sudo docker build -t sweeping-robot-devel:1.0 -f tools/Dockerfile.devel .
```

start develop container.

```bash
$ sudo docker run -v `pwd`:/sweeping_robot -it  --name sweeping_robot sweeping-robot-devel:1.0
```

## Test 

```bash
$ bazel test //sweeping_robot/...
```

## Format

clang-format is not friendly for cut test cases. 

```bash
$ tools/clang-format.sh
```
