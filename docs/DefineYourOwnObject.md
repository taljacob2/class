# Define Your Own Object

Use the [Object](../src/lib/oop/Object/Object.r) object to implement your own objects.

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
  #include "oop/oop.h"

  #include "Circle.h"

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