
# Contributing

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
