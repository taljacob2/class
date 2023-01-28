# Introduction - Compiling With Microsoft's MSVC

## Import `oop` To Your Program

In your project's root path, create an empty file named `main.c`.

Once you have downloaded the latest release of `oop-msvc.zip`,

Extract the archive, and place the `oop` directory at your project's root path.
```
oop-windows-test
├── Debug
│   └── .
├── Release
├── oop-windows-test
│   ├── Debug
│   │   .
│   │   
│   ├── Release
│   │   .
│   │   
│   ├── main.c
│   ├── oop
│   │   ├── AnonymousObject
│   │   │   ├── AnonymousObject.h
│   │   │   ├── AnonymousObject.r
│   │   │   └── BitDefines.r
│   │   ├── Atomic
│   │   │   ├── Atomic.h
│   │   │   ├── AtomicDoubleRValue.h
│   │   │   ├── AtomicInteger.h
│   │   │   ├── AtomicIntegerRValue.h
│   │   │   ├── AtomicLValue.h
│   │   │   ├── Func.h
│   │   │   ├── LValueDefines.h
│   │   │   ├── RValueDefines.h
│   │   │   └── Random.r
│   │   ├── Object
│   │   │   ├── AnonymousPointer.r
│   │   │   ├── AutoDestructable.r
│   │   │   ├── Bool.h
│   │   │   ├── Concat.h
│   │   │   ├── Destructable.r
│   │   │   ├── InvocationStatus.r
│   │   │   ├── Legacy_AllocationTable.r
│   │   │   ├── Legacy_AllocationTableList.r
│   │   │   ├── Legacy_AtomicFreer.r
│   │   │   ├── Legacy_List.r
│   │   │   ├── Legacy_MemberList.r
│   │   │   ├── Legacy_Node.r
│   │   │   ├── Legacy_Object.r
│   │   │   ├── Legacy_ObjectComponent.r
│   │   │   ├── Legacy_StringObjectContainerEntry.r
│   │   │   ├── Object.h
│   │   │   ├── Object.r
│   │   │   ├── ObjectDefines.r
│   │   │   └── Quote.h
│   │   ├── oop.h
│   │   ├── oop.lib
│   │   └── oop32.lib
│   ├── oop-windows-test.vcxproj
│   ├── oop-windows-test.vcxproj.filters
│   ├── oop-windows-test.vcxproj.user
│   └── x64
│       ├── Debug
│       │   .
│       │   
│       └── Release
│           .
│           
├── oop-windows-test.sln
└── x64
    ├ .
    .
```

## Define Your Own New Object

See [Define Your Own Object](DefineYourOwnObject.md)

## Build & Execute

- Via Visual Studio (Recommended):

  - Build & Execute At Once: <kbd>CTRL + F5</kbd>
  - Build Without Executing: <kbd>CTRL + B</kbd>

- Manually (Not Recommended):

  - Build your program with `msvc`:

    ```
    cl.exe main.c Circle.c oop/oop.lib
    ```

  - Run the program:
    
    ```
    main.exe
    ```
