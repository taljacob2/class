# OOP For C Language

`oop` is a static library, that allows the use of OOP in C language.

## Download The Latest Release Of `oop` [Here](https://github.com/taljacob2/oop/releases/)

- For compiling with GNU's GCC, download `oop-gcc.tar.gz`
- For compiling with Microsoft's MSVC, download `oop-msvc.zip`

## Introduction

- For GNU's GCC see [GCC Introducion](docs/GCCIntroduction.md)
- For Microsoft's MSVC see [MSVC Introducion](docs/MSVCIntroduction.md)

### Polymorphism

When creating a new class with the `DEFINE_CLASS_H` macro keyword, you actually polymorph the new class with the [`Object`](src/lib//oop/Object/Object.r) class.

Thus, every class you create, is polymorphed with [`Object`](src/lib//oop/Object/Object.r).

> ##### NOTE 1 FOR DEVELOPERS ONLY
> Every object is polymorphed with [`Legacy_Object`](src/lib/oop/Object/Legacy_Object.r)
  (it is the **most polymorhpic object in the library**).

### Dynamic Allocation

Do not worry again about dynamic allocation (eg. malloc, calloc...).

> ##### NOTE 2 FOR DEVELOPERS ONLY
> Every [`Object`](src/lib//oop/Object/Object.r) is composed of [`AutoDestructable`](src/lib/oop/Object/AutoDestructable.r), which handles the object to **automatically be destructed after the `main`** (see
> [`Legacy_AllocationTableList`](/src/lib/oop/Object/Legacy_AllocationTableList.r)).

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md)
