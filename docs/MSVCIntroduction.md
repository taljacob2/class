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

Use the [Object](src/lib/oop/Object/Object.r) object to implement your own objects.

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

  Circle *CircleConstructor();

  #endif /* CIRCLE_H */
  ```

- Create a new file named `Circle.c` with the following content:
  ```c
  #include "Circle.h"

  Circle *CircleConstructor() {
      Object *instance = ObjectConstructor("Circle");  

      instance->addIntegerRValueMember(instance, PUBLIC, FIELD, "name",
                                      (IntegerRValue) "smallCircle");
      printf("%s\n", (const char *) instance->getIntegerRValueMember(
                          instance, PUBLIC, FIELD, "name"));
      
      instance->addDoubleRValueMember(instance, PUBLIC, FIELD, "radius", 2.34);
      printf("%f\n", (double) instance->getDoubleRValueMember(instance,  PUBLIC,
                                                              FIELD,  "radius"));
      
      return (Circle *) instance;
  }
  ``` 
 
## Use Your Newly Defined Object

### Create Your Program

- Create a file named `main.c`.

- Use `Circle` in `main.c`.
  ```c

  /* For 64bit compilation */
  #pragma comment(lib, "oop/oop.lib")

  /* For 32bit compilation */
  /* #pragma comment(lib, "oop/oop32.lib") */

  #include "oop/oop.h"

  int main() {
      Circle *circle = CircleConstructor();

      /* 
       * `circle` is automatically freed, thus invoking `DESTRUCT_OBJECT` is not
       * required, but optional in case you want to destruct the object manually.
       */

      /* DESTRUCT_OBJECT(circle); */

      return 0;
  }
  ```

### Build & Execute

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
