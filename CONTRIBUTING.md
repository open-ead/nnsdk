# Contribution Guidelines

## Development

For running commands please install [task](https://taskfile.dev), CMake, Ninja and Clang/LLVM.
The Clang/LLVM toolchain version should match the [image used in the PR](https://github.com/open-ead/containers/blob/main/ubuntu-builder/Dockerfile)

Run `task pr` to run the same checks that the PR runs. Run `task fix` to fix the clang-format issues.

## File structure
