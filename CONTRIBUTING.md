# Contributing

You may develop with both GNU's "GCC" and Microsoft's "MSVC" compilers.

## Testing With Valgrind To Assert There Are No Memory Leaks

Although, to build the project, you should mainly choose one of them.
Feel free to choose as you like, although, when dealing with memory allocations,
we require to test the library, with [Valgrind](https://valgrind.org/).
It allows us to check for memory leaks
> See [`config.sh`](config.sh) for modifying Valgrind settings.

### Test Your Code With Valgrind Locally

- **In case you choose to work with GCC**:

  - You probably own a *NIX machine, and thus you may test your code with Valgrind locally.
  
    To do so, please install Valgrind with:
    ```
    sudo apt install valgrind -y
    ```
    And make sure that in [`config.sh`](config.sh), the variable `RUN_WITH_VALGRIND` is set to `true`.

  - In case you don't want to test your code with Valgrind locally, then in
    [`config.sh`](config.sh), set the variable `RUN_WITH_VALGRIND` to `false`.
  
- **In case you choose to work with MSVC**:

  Unfortunately, you cannot test your code with Valgrind locally.

### Test Your Code With Valgrind Remotely

**Either compiler you choose (especially with MSVC), when you push your commits to GitHub,
watch the ["Build & Test" GitHub Action](https://github.com/taljacob2/oop/actions/workflows/build.yml) and verify that "Run With Valgrind" Step is finishing successfully without any memory leaks. The ["Build & Test" GitHub Action](https://github.com/taljacob2/oop/actions/workflows/build.yml)
is triggered on every commit push. So feel free to test your code for memory leaks.**

## Build & Run

## Build `oop.a` (When Developing `oop.a`)

Build [oop.a](src/lib/oop/oop.a) library (which is composed from all its sub-libraries)
by executing the following script:
```
./build-lib.sh
```

## Main

### Build Your Own Program With Linking `oop.a` To It (Mainly For Testing `oop.a`)

Build your own program ([main.c](src/main/main.c) for example) while linking the
`oop.a` library to it.
```
./build-main.sh
```

### Run [main.c](src/main/main.c)

```
./run-main.sh
```

## Test (For automated tests)

### Build Your Own Program With Linking `oop.a` To It (Mainly For Testing `oop.a`)

Build your own program ([test.c](src/test/main.c) for example) while linking the
`oop.a` library to it.
```
./build-test.sh
```

### Run [main.c](src/test/main.c)

```
./run-test.sh
```

## About [`config.sh`](config.sh)

This file bundles variables that are used by other `.sh` files.

Under the `# --------- Edit to you liking: ---------` comment, you are
allowed to change the values of the variables to you liking.

## Run Settings

### Valgrind

Valgrind allows us to check for memory leaks.

You can set `RUN_WITH_VALGRIND` to `true` or `false`, to set the run of the
program with or without Valgrind.

## Building & Pushing A New Release

See [Release.md](docs/Release.md)
