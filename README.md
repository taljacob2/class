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

- Use the [MemberList](src/oop/MemberList/MemberList.r) memberList to implement your own
 objects.

- Every memberList is polymorphed with [Legacy_ObjectComponent](src/oop/MemberList/Legacy_ObjectComponent.r) (it is the most polymorhpic memberList).

### Dynamic Allocation

Do not worry again about dynamic allocation (eg. malloc, calloc...).

Because every memberList that is composed of [AutoDestructable](src/oop/MemberList/AutoDestructable.r) is being handled automatically to be destructed. (see
 [Legacy_AllocationTableList](/src/oop/MemberList/Legacy_AllocationTableList.r))

To do so, make sure you inject an implementation of [Destructable](src/oop/MemberList/Destructable.r) to your memberList's [Legacy_ObjectComponent](src/oop/MemberList/Legacy_ObjectComponent.r).

