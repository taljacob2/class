# Developing - Compiling With GNU's GCC

## Setting The Environment Variables At [`config.sh`](../config.sh)

This file bundles variables that are used by other `.sh` files.

Between the `--------- START: Edit to you liking ---------` and 
`--------- END: Edit to you liking -----------` comments, you are
allowed to change the values of the variables to you liking.

For example:

- **Valgrind**

  You can set `RUN_WITH_VALGRIND` to `true` or `false`, to set the run of the
program with or without Valgrind.

---

## Developing

Execute the following commands with *bash*.

### Build `oop` (Specifically developing the `oop.a` static library)

Build `oop.a` library (which is composed from all its sub-libraries)
by executing the following script:
```
./build-lib.sh
```

### Build & Run `main`

#### Build Your Own Program With Linking `oop.a` To It (Mainly For Testing `oop.a`)

Build your own program ([main.c](../src/main/main.c) for example) while linking the
`oop.a` library to it.
```
./build-main.sh
```

#### Run [main.c](../src/main/main.c)

```
./run-main.sh
```

> ### Build & Run `test` (For automated tests)
> 
> #### Build Your Own Program With Linking `oop.a` To It (Mainly For Testing `oop.a`)
> 
> Build your own program ([test.c](../src/test/main.c) for example) while linking the
> `oop.a` library to it.
> ```
> ./build-test.sh
> ```
> 
> #### Run [main.c](../src/test/main.c)
> 
> ```
> ./run-test.sh
> ```
