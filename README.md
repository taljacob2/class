# OOP For C Language

[oop.a](src/oop/oop.a) is a static library in C, that allows the use of OOP.

## Introduction

### Import `oop.a` To Your Program

In your project's path, create an empty file named `main.c`.

#### Download The Latest Release Of `oop.a` [Here](https://github.com/taljacob2/oop/releases/)

Place the "oop" directory in your project's path.
```
.
├── main.c
└── oop
    ├── Atomic
    │   ├── Atomic.h
    │   ├── AtomicInteger.h
    ├── Object
    │   ├── AnonymousPointer.h
    │   ├── AutoDestructable.r
    │   ├── Bool.h
    │   ├── Concat.h
    │   ├── Constructable.r
    │   ├── Destructable.r
    │   ├── InvocationStatus.r
    │   ├── Legacy_AllocationTable.r
    │   ├── Legacy_AllocationTableList.r
    │   ├── Legacy_AtomicFreer.r
    │   ├── Legacy_List.r
    │   ├── Legacy_MemberList.r
    │   ├── Legacy_Node.r
    │   ├── Legacy_Object.r
    │   ├── Legacy_ObjectComponent.r
    │   ├── Legacy_StringObjectContainerEntry.r
    │   ├── MemberList.r
    │   ├── Object.a
    │   ├── Object.h
    │   ├── Object.r
    │   ├── ObjectDefines.r
    │   ├── Quote.h
    ├── oop.a
    └── oop.h
```

### Define Your Own New Object

Use the [Object](src/oop/Object/Object.r) object to implement your own objects.

To do so, you need to create 2 files.
- One with `.h` extension.
- One with `.c` extension.

Use the following template to implement your object.
For example, you wish to define a new object with the "class name" of `Circle`:

- Create a new file named `Circle.h` with the following content:
  ```c
  #ifndef CIRCLE_H
  #define CIRCLE_H

  #include "oop/oop.h"

  DEFINE_CLASS_H(Circle)

  #endif /* CIRCLE_H */
  ```

- Create a new file named `Circle.c` with the following content:
  ```c
  #include "Circle.h"

  DEFINE_CLASS_C(Circle)
  ``` 
 
### Use Your Newly Defined Object

### Create Your Program

- Create a file named `main.c`.

- Use `Circle` in `main.c`.
  ```c
  #include "oop/oop.h"

  int main() {
      Circle *circle = CircleConstructor();

      /* `circle` is automatically freed */

      return 0;
  }
  ```

#### Build & Execute

- Build your program with `gcc`:
  ```
  gcc main.c Circle.c -L. oop/oop.a
  ```

- Execute the program:
  ```
  ./a.out
  ```

> ##### NOTE 1 FOR DEVELOPERS ONLY
> Every object is polymorphed with [Legacy_Object](src/oop/Object/Legacy_Object.r)
  (it is the most polymorhpic object).

### Dynamic Allocation

Do not worry again about dynamic allocation (eg. malloc, calloc...).

> ##### NOTE 2 FOR DEVELOPERS ONLY
> As said in [NOTE 1 FOR DEVELOPERS ONLY](#NOTE-1-FOR-DEVELOPERS-ONLY),
> 
> Because every object that is composed of [AutoDestructable](src/oop/Object/AutoDestructable.r)
> is being handled automatically to be destructed (see
> [Legacy_AllocationTableList](/src/oop/Object/Legacy_AllocationTableList.r)).
> 
> To do so, make sure you inject an implementation of
> [Destructable](src/oop/Object/Destructable.r) to your object's
> [Legacy_ObjectComponent](src/oop/Object/Legacy_ObjectComponent.r).


## Contributing

### Build `oop.a` (When Developing `oop.a`)

Build [oop.a](src/oop/oop.a) library (which is composed from all its sub-libraries)
by executing the following script:
```
./src/oop/build-library.sh
```

### Build Your Own Program With Linking `oop.a` To It (Maily For Testing `oop.a`)

Build your own program ([main.c](src/main.c) for example) while linking the
`oop.a` library to it.
```
./build.sh
```

### Execute [main.c](src/main.c) With Valgrind

Valgrind allows us to check for memory leaks.
```
valgrind --leak-check=full --show-leak-kinds=all ./a.out
```
