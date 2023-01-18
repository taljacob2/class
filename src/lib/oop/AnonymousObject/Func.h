#ifndef FUNC_H
#define FUNC_H

// See https://stackoverflow.com/a/69935570/14427765

// Creates a lambda.
// Usage:
//     LAMBDA(return_type)(params)(body)
// Example:
//     ptr = LAMBDA(int)(int x, int y)(return x + y;);
#define LAMBDA LAM_LAMBDA

// Defines a function.
// Usage:
//     FUNC(return_type)(name)(params)(body)
// Example:
//     FUNC(int)(foo)(int x, int y)(return x + y;)
//     some_func(foo);
#define FUNC LAM_FUNC

// Any time a `LAMBDA` or `FUNC` appears inside of parentheses,
//   those parentheses must be preceeded by this macro.
// For example, this is wrong:
//     foo(LAMBDA(int)()(return 42;));
// While this works:
//     foo L_(LAMBDA(int)()(return 42;));
#define L_ LAM_NEST

// `LAMBDA` and `FUNC` only work inside `ENABLE_LAMBDAS(...)`.
// `ENABLE_LAMBDAS(...)` expands to `...`, preceeded by function definitions for all the lambdas.
#define ENABLE_LAMBDAS LAM_ENABLE_LAMBDAS

// Lambda names are composed of this prefix and a numeric ID.
#ifndef LAM_PREFIX
#define LAM_PREFIX LambdaFunc_
#endif

// Implementation details:

// Returns nothing.
#define LAM_NULL(...)
// Identity macro.
#define LAM_IDENTITY(...) __VA_ARGS__
// Concats two arguments.
#define LAM_CAT(x, y) LAM_CAT_(x, y)
#define LAM_CAT_(x, y) x##y
// Given `(x)y`, returns `x`.
#define LAM_PAR(...) LAM_PAR_ __VA_ARGS__ )
#define LAM_PAR_(...) __VA_ARGS__ LAM_NULL(
// Given `(x)y`, returns `y`.
#define LAM_NO_PAR(...) LAM_NULL __VA_ARGS__
// Expands `...` and concats it with `_END`.
#define LAM_END(...) LAM_END_(__VA_ARGS__)
#define LAM_END_(...) __VA_ARGS__##_END

// A generic macro to define functions and lambdas.
// Usage: `LAM_DEFINE(wrap, ret)(name)(params)(body)`.
// In the encloding code, expands to `wrap(name)`.
#define LAM_DEFINE(wrap, ...) )(l,wrap,(__VA_ARGS__),LAM_DEFINE_0
#define LAM_DEFINE_0(name) name,LAM_DEFINE_1
#define LAM_DEFINE_1(...) (__VA_ARGS__),LAM_DEFINE_2
#define LAM_DEFINE_2(...) __VA_ARGS__)(c,

// Creates a lambda.
// Usage: `LAM_LAMBDA(ret)(params)(body)`.
#define LAM_LAMBDA(...) LAM_DEFINE(LAM_IDENTITY, __VA_ARGS__)(LAM_CAT(LAM_PREFIX, __COUNTER__))
// Defines a function.
// Usage: `LAM_FUNC(ret)(name)(params)(body)`.
#define LAM_FUNC(...) LAM_DEFINE(LAM_NULL, __VA_ARGS__)

// `LAM_LAMBDA` and `LAM_FUNC` only work inside of this macro.
#define LAM_ENABLE_LAMBDAS(...) \
    LAM_END( LAM_GEN_LAMBDAS_A (c,__VA_ARGS__) ) \
    LAM_END( LAM_GEN_CODE_A (c,__VA_ARGS__) )

// Processes lambdas and functions in the following parentheses.
#define LAM_NEST(...) )(open,)(c,__VA_ARGS__)(close,)(c,

// A loop. Returns the original code, with lambdas replaced with corresponding function names.
#define LAM_GEN_CODE_A(...) LAM_GEN_CODE_BODY(__VA_ARGS__) LAM_GEN_CODE_B
#define LAM_GEN_CODE_B(...) LAM_GEN_CODE_BODY(__VA_ARGS__) LAM_GEN_CODE_A
#define LAM_GEN_CODE_A_END
#define LAM_GEN_CODE_B_END
#define LAM_GEN_CODE_BODY(type, ...) LAM_CAT(LAM_GEN_CODE_BODY_, type)(__VA_ARGS__)
#define LAM_GEN_CODE_BODY_c(...) __VA_ARGS__
#define LAM_GEN_CODE_BODY_l(wrap, ret, name, ...) wrap(name)
#define LAM_GEN_CODE_BODY_open() (
#define LAM_GEN_CODE_BODY_close() )

// A loop. Generates lambda definitions, discarding all other code.
#define LAM_GEN_LAMBDAS_A(...) LAM_GEN_LAMBDAS_BODY(__VA_ARGS__) LAM_GEN_LAMBDAS_B
#define LAM_GEN_LAMBDAS_B(...) LAM_GEN_LAMBDAS_BODY(__VA_ARGS__) LAM_GEN_LAMBDAS_A
#define LAM_GEN_LAMBDAS_A_END
#define LAM_GEN_LAMBDAS_B_END
#define LAM_GEN_LAMBDAS_BODY(type, ...) LAM_CAT(LAM_GEN_LAMBDAS_BODY_, type)(__VA_ARGS__)
#define LAM_GEN_LAMBDAS_BODY_c(...)
#define LAM_GEN_LAMBDAS_BODY_l(wrap, ret, name, par, ...) static LAM_IDENTITY ret name par { __VA_ARGS__ }
#define LAM_GEN_LAMBDAS_BODY_open()
#define LAM_GEN_LAMBDAS_BODY_close()

#endif //FUNC_H
