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

# Bitwise operators

* A **bitwise operator** is a tool in the C programming language that lets you **work directly with the bits** in numbers.
* Instead of looking at a number as a whole, these operators let you look at and change the individual bits.

### Why Use Bitwise Operators?

Bitwise operators are:

* **Fast** – they run in just one CPU instruction
* **Memory-efficient** – let you store and manipulate data using as little space as possible
* **Useful** – especially in system programming, device drivers, embedded systems, graphics, and games

## The Four Main Bitwise Operators

### 1. Bitwise AND `&`

**What it does:** Compares two numbers **bit by bit**, and keeps only the bits that are `1` in **both** numbers.

**Example:**

```c
int a = 12;   // in binary: 1100
int b = 10;   // in binary: 1010

int result = a & b; // result = 8 (binary: 1000)
```

### 2. Bitwise OR `|`

**What it does:** Compares two numbers **bit by bit**, and keeps a `1` if **either** number has a `1`.

**Example:**

```c
int a = 12;   // 1100
int b = 10;   // 1010

int result = a | b; // result = 14 (binary: 1110)
```

### 3. Bitwise XOR `^` (Exclusive OR)

**What it does:** Compares two numbers **bit by bit**, and sets a bit to `1` if the two bits are **different** and sets a bit to `0` if the two bits are the **same**.

**Example:**

```c
int a = 12;   // 1100
int b = 10;   // 1010

int result = a ^ b; // result = 6 (binary: 0110)
```

### 4. Bitwise NOT `~` (One's Complement)

**What it does:** Flips **all** the bits in the number.
All `0`s become `1`s, and all `1`s become `0`s.

**Example:**

```c
int a = 12;       // 0000000000001100 (in 16 bits)
int result = ~a;  // 1111111111110011 → -13 (in two's complement form)
```

## Real-World Applications

* **Performance-sensitive code:** Bitwise operations are extremely fast.
* **Embedded systems:** Directly control hardware by setting specific bits in control registers.
* **Graphics programming:** Manipulate color data or pixels efficiently.
* **Compression and encryption algorithms:** Work on data at the bit level to save space or hide information.