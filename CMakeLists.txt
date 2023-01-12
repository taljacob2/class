cmake_minimum_required(VERSION 3.16)
project(class C)

set(CMAKE_C_STANDARD 99)

add_executable(class src/main/main.c src/lib/oop/Object/AutoDestructable.r
        src/lib/oop/Object/Legacy_AllocationTable.r src/lib/oop/Object/Legacy_List.r src/lib/oop/Object/Legacy_Node.r
        src/lib/oop/Object/Legacy_AllocationTableList.r src/lib/oop/Object/Bool.h
        src/lib/oop/Object/Destructable.r src/lib/oop/Object/AutoDestructable.c
        src/lib/oop/Object/Legacy_Node.c src/lib/oop/Object/Legacy_List.c
        src/lib/oop/Object/Legacy_AllocationTable.c src/lib/oop/Object/Legacy_AllocationTableList.c
        src/lib/oop/Object/Legacy_ObjectComponent.c
        src/main/Circle.h
        src/lib/oop/Object/InvocationStatus.r src/main/Circle.c src/lib/oop/Object/Legacy_ObjectComponent.r
        src/lib/oop/Object/Legacy_MemberList.r src/lib/oop/Object/Legacy_StringObjectContainerEntry.r
        src/lib/oop/Object/Legacy_StringObjectContainerEntry.c
        src/lib/oop/Object/Legacy_MemberList.c src/main/CircleV2.h src/main/CircleV2.c src/lib/oop/Object/Legacy_AtomicFreer.r
        src/lib/oop/Object/Legacy_AtomicFreer.c
        src/lib/oop/Object/Object.r src/lib/oop/Atomic/AtomicInteger.h
        src/lib/oop/oop.h src/lib/oop/Atomic/AtomicInteger.c
        src/lib/oop/Atomic/Atomic.h
        src/lib/oop/Object/Object.c src/main/CircleV3.h src/lib/oop/Object/ObjectDefines.r
        src/lib/oop/Object/AnonymousPointer.r src/main/CircleV3.c src/main/CircleV4.h src/lib/oop/Object/Quote.h
        src/main/CircleV4.c src/main/CircleV5.h src/main/CircleV5.c src/lib/oop/Object/Concat.h
        src/lib/oop/Object/AnonymousPointer.c src/lib/oop/Object/Concat.c
        src/lib/oop/Atomic/Random.r src/lib/oop/Atomic/Random.c
        src/lib/oop/AnonymousObject/AnonymousObject.h
        src/lib/oop/AnonymousObject/AnonymousObject.h
        src/lib/oop/AnonymousObject/AnonymousObject.r src/lib/oop/AnonymousObject/AnonymousObject.c src/lib/oop/AnonymousObject/BitDefines.r
        src/main/CircleV6.h src/main/CircleV6.c src/lib/oop/Atomic/AtomicLValue.h src/lib/oop/Atomic/AtomicLValue.c src/lib/oop/Atomic/Func.h src/lib/oop/Atomic/AtomicRValue.h src/lib/oop/Atomic/AtomicRValue.c)