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