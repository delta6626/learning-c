# ++ & --

* Prefix vs. Postfix: The position of increment/decrement operators (prefix or postfix) affects when the operation takes place. Prefix (++a) modifies the value before it's used, while postfix (a++) modifies it after.

* Example:

```c
#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;

    printf("The value of a and b is %d and %d\n", a, b);     // 5 and 10
    printf("The value of a and b is %d and %d\n", a++, b--); // 5 and 10
    printf("The value of a and b is %d and %d\n", a, b);     // 6 and 9
    printf("The value of a and b is %d and %d\n", ++a, --b); // 7 and 8

    return 0;
}
```

# Truthy and Falsy Values in C

* In C, the integer `0` is considered *false*, and any non-zero value is considered *true* when used in a conditional expression like `if`, `while`, or `for`.
* This applies to all scalar types: `int`, `char`, `float`, pointers, etc.
* Using an assignment in a conditional expression (e.g., `if (x = 5)`) assigns the value and then evaluates the result. If the assigned value is zero, the condition is false; otherwise, it's true.

```c
#include <stdio.h>

int main() {
    int x = 0;
    if(x){
        puts("Hey");
    }
    else{
        puts("Hello"); // output: Hello
    }

    const char a = 'A';
    if(a){
        puts("Hi"); // output: Hi
    }
    else{
        puts("Hola"); 
    }

    return 0;
}
```