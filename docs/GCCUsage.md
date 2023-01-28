# Usage - Compiling With GNU's GCC

## Import `oop` To Your Program

In your project's root path, create an empty file named `main.c`.

Once you have downloaded the latest [release](https://github.com/taljacob2/oop/releases) of `oop-gcc.tar.gz`,

Extract the archive, and place the `oop` directory at your project's root path.
```
.
├── main.c
└── oop
    ├── AnonymousObject
    │   ├── AnonymousObject.h
    │   ├── AnonymousObject.r
    │   └── BitDefines.r
    ├── Atomic
    │   ├── Atomic.h
    │   ├── AtomicDoubleRValue.h
    │   ├── AtomicInteger.h
    │   ├── AtomicIntegerRValue.h
    │   ├── AtomicLValue.h
    │   ├── Func.h
    │   ├── LValueDefines.h
    │   ├── RValueDefines.h
    │   └── Random.r
    ├── Object
    │   ├── AnonymousPointer.r
    │   ├── AutoDestructable.r
    │   ├── Bool.h
    │   ├── Concat.h
    │   ├── Destructable.r
    │   ├── InvocationStatus.r
    │   ├── Legacy_AllocationTable.r
    │   ├── Legacy_AllocationTableList.r
    │   ├── Legacy_AtomicFreer.r
    │   ├── Legacy_List.r
    │   ├── Legacy_MemberList.r
    │   ├── Legacy_Node.r
    │   ├── Legacy_Object.r
    │   ├── Legacy_ObjectComponent.r
    │   ├── Legacy_StringObjectContainerEntry.r
    │   ├── Object.h
    │   ├── Object.r
    │   ├── ObjectDefines.r
    │   └── Quote.h    
    ├── oop.h
    ├── oop.a
    └── oop32.a
```

## Define Your Own New Object

See [Define Your Own Object](DefineYourOwnObject.md).

## Build & Execute

- Build your program with `gcc`:

  ```
  gcc main.c Circle.c -L. oop/oop.a
  ```

- Run the program:

  ```
  ./a.out
  ```
