# OOP For C Language

`oop` is a static library, that allows the use of OOP in C language.

## Download The Latest Release Of `oop` [Here](https://github.com/taljacob2/oop/releases/)

- For compiling with GNU's GCC, download `oop-gcc.tar.gz`
- For compiling with Microsoft's MSVC, download `oop-msvc.zip`

## Introduction

- For GNU's GCC see [GCC Introducion](docs/GCCIntroduction.md)
- For Microsoft's MSVC see [MSVC Introducion](docs/MSVCIntroduction.md)

> ##### NOTE 1 FOR DEVELOPERS ONLY
> Every object is polymorphed with [Legacy_Object](src/lib/oop/Object/Legacy_Object.r)
  (it is the most polymorhpic object).

### Dynamic Allocation

Do not worry again about dynamic allocation (eg. malloc, calloc...).

> ##### NOTE 2 FOR DEVELOPERS ONLY
> As said in [NOTE 1 FOR DEVELOPERS ONLY](#NOTE-1-FOR-DEVELOPERS-ONLY),
> 
> Because every object that is composed of [AutoDestructable](src/lib/oop/Object/AutoDestructable.r)
> is being handled automatically to be destructed (see
> [Legacy_AllocationTableList](/src/lib/oop/Object/Legacy_AllocationTableList.r)).
> 
> To do so, make sure you inject an implementation of
> [Destructable](src/lib/oop/Object/Destructable.r) to your object's
> [Legacy_ObjectComponent](src/lib/oop/Object/Legacy_ObjectComponent.r).

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md)
