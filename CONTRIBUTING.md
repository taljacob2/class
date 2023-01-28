# Contributing

You may develop with following compilers:

- GNU's "GCC".
- Microsoft's "MSVC".

You may choose either one of them for developing & building the project.

## Developing

- When [developing with GCC](docs/GCCDeveloping.md).
- When [developing with MSVC](docs/MSVCDeveloping.md).

## Testing With Valgrind To Assert There Are No Memory Leaks

Either compiler you choose, when dealing with memory allocations,
we require to test the library, with [Valgrind](https://valgrind.org/).
It allows us to check for memory leaks

### (**OPTIONAL**) Test Your Code With Valgrind Locally

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

### (**MANDATORY**) Test Your Code With Valgrind Remotely

**Either compiler you choose (especially with MSVC), when you push your commits to GitHub,
watch the ["Build & Test" GitHub Action](https://github.com/taljacob2/oop/actions/workflows/build.yml) and verify that the "Run With Valgrind" step is finishing successfully without any memory leaks. The ["Build & Test" GitHub Action](https://github.com/taljacob2/oop/actions/workflows/build.yml)
is triggered on every commit push. So feel free to test your code for memory leaks.**

For example:

![image](https://user-images.githubusercontent.com/70590583/215257406-ce0645ce-5f09-4ef2-aed3-a2eb5f8d5edd.png)

## Building & Pushing A New Release

See [Release.md](docs/Release.md).
