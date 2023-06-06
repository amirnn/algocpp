# Algorithms Course

## Dependencies

I am going to use conan for dependency management.

```shell
# Execute following commands in the terminal.
cd conan
conan install . --build=missing --profile=profiles/brew-llvm -s build_type=Debug
# For Release
conan install . --build=missing --profile=profiles/brew-llvm -s build_type=Release
```

## Build

I am using cmake.

```shell
# Execute following commands in the terminal.
$ mkdir build
$ cd build
$ cmake ..
$ make -j8
```

## Tests

To run tests. (TODO)

## Week 1
