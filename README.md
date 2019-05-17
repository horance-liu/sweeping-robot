# Sweeping Robot 

## Requirement

- [bazel](https://www.bazel.build)
- compiler: should support c++14 or above

## Test 

```bash
$ bazel test //sweeping_robot/...
```

## Format

clang-format is not friendly for cut test cases. 

```bash
$ tools/clang-format.sh
```
