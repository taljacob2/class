# OOP For C Language

[oop.a](src/oop/oop.a) is a static library in C, that allows the use of OOP.

## Build & Use

Build [oop.a](src/oop/oop.a) library (which is composed from all its sub-libraries)
```
./src/oop/build-library.sh
```

Build [main.c](src/main.c) (while linking the "oop" library to it)
```
./build.sh
```

Run [main.c](src/main.c)
```
./a.out
```

## Introducion

- Use the [Object](src/oop/Object/Object.r) object to implement your own
 objects.

- Every object is polymorphed with [Legacy_Object](src/oop/Object/Legacy_Object.r) (it is the most polymorhpic object).

### Dynamic Allocation

Do not worry again about dynamic allocation (eg. malloc, calloc...).

Because every object that is composed of [AutoDestructable](src/oop/Object/AutoDestructable.r) is being handled automatically to be destructed. (see
 [Legacy_AllocationTableList](/src/oop/Object/Legacy_AllocationTableList.r))

To do so, make sure you inject an implementation of [Destructable](src/oop/Object/Destructable.r) to your object's [Legacy_Object](src/oop/Object/Legacy_Object.r).

