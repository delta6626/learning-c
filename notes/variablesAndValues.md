# C Language Data Types, Input/Output, and Strings

## 1. Programming is Fundamentally About Input and Output

Programming is the process of receiving input, performing computation or modification, and producing output. In the C language, this process is explicit. Data is input by the user or read from a file, manipulated using variables and operations, and then output to the screen or elsewhere.

## 2. The Four Basic Data Types in C

C provides four fundamental built-in data types that describe what kind of information can be stored and manipulated in a program.

### `char`

Stores a single character or a single byte of data. Used for character-based input and output. It typically occupies 1 byte of memory. Characters are stored as ASCII values, so `'A'` is actually stored as the integer 65. The `char` type can be signed or unsigned, depending on the compiler. Use single quotes when assigning values to a `char` variable.

### `int`

Stores integer (whole number) values. This is the most common type used for counters, loop indexes, and general-purpose numeric data. Typically occupies 4 bytes on most modern systems. It is signed by default.

### `float`

Stores real numbers (decimal numbers) using **single precision**, which is accurate to about 7 or 8 decimal digits. Typically used when approximate values are acceptable and memory efficiency is needed. Usually occupies 4 bytes.

### `double`

Also stores real numbers, but with **double precision**. Accurate to about 15 or 16 decimal digits. Preferred when higher precision is required. Typically occupies 8 bytes.

## 3. Additional Integer Types: `short` and `long`

C provides two additional modifiers for integer types that change their size and range.

### `short`

Represents a smaller integer than `int`. Typically occupies 2 bytes. Useful for saving memory in cases where the full range of `int` is not needed.

Example:

```c
short int a = 1000;
```

### `long`

Represents a larger integer than `int`. On 32-bit systems, `long` is usually 4 bytes (same as `int`). On 64-bit systems, it is often 8 bytes.

Example:

```c
long int b = 1000000000;
```

You can also use `long long` for even larger values.

## 4. Type Qualifiers: Signed and Unsigned

C supports type qualifiers that refine the range and interpretation of numeric data.

### `signed` (default)

Allows a variable to hold both positive and negative values. This is the default for most integer types, such as `int`, `char`, `short`, and `long`.

### `unsigned`

Allows a variable to hold only non-negative values (zero and positive values), effectively doubling the upper limit of the value range. Commonly used when negative numbers are not needed, such as for counters or bit manipulation.

Example:

```c
unsigned int x = 300;
```

## 5. Reading and Writing Data: scanf and printf

### `scanf`

Used to read input from the user. Requires a format specifier (such as `%d`, `%f`, `%c`, `%s`) and a reference to the memory location where the input will be stored.

Syntax:

```c
scanf("%d", &i);
```

This reads an integer and stores it in variable `i`.

### `printf`

Used to output data to the screen. Requires a format string with placeholders and the variables to display.

Syntax:

```c
printf("Value: %d", i);
```

Note: For `scanf`, you must pass the **address** of the variable using the `&` operator. `printf` only needs the value.

## 6. The `void` Data Type

The `void` type is a special data type that represents the absence of any value.

* Used for functions that do not return any value:

  ```c
  void printMessage() { ... }
  ```
* Used for functions that take no parameters:

  ```c
  int main(void)
  ```
* Used for generic pointers that can point to any type:

  ```c
  void *ptr;
  ```
* Used in memory allocation functions:

  ```c
  void *malloc(size_t size);
  ```

The `void` type is not used to store values; it serves only as a type indicator in specific contexts.

## 7. Strings in C

C does not have a built-in `string` type like many other programming languages. Instead, strings are represented as arrays of `char` terminated by a null character (`\0`). Use double quotes for strings.

To store a string, a `char` array is declared:

```c
char name[] = "John";
char buffer[32];
```

This creates an array capable of storing up to 31 characters plus the null terminator.

### Reading Strings with `fgets`

`fgets` is the recommended method to read strings from input because it prevents buffer overflows by limiting the number of characters read.

Syntax:

```c
fgets(buffer, 32, stdin);
```

* `buffer` is the array where the input string will be stored.
* `32` is the maximum number of characters to read, including the null terminator.
* `stdin` indicates input should come from standard input (keyboard).

Unlike `scanf`, `fgets` allows for reading strings with spaces and is safer because it enforces a maximum character limit.

After reading the string, `printf` can be used to display it:

```c
printf("%s", buffer);
```

# Declaring variables

* Variable Declaration: Variables must be declared before use, specifying a data type and a name.

* Naming Conventions: Variable names should start with a letter, can include numbers and underscores, and should be descriptive and concise.
    
* Initialization: Variables can be initialized when declared or later in the code, but they must be assigned a value before use to avoid errors and potential security risks.

```c
// 1. Basic declaration without initialization
int a;
char ch;
float temperature;

// 2. Declaration with initialization
int x = 10;
char grade = 'A';
float pi = 3.14;

// 3. Multiple declarations in a single line
int m, n, o = 5;
float alpha = 1.2, beta;

// 4. Using type modifiers
unsigned int count = 100;
short int si = -32768;
long int li = 1000000;
unsigned char uc = 255;

// 5. Global variable (declared outside any function)
int globalCounter = 0;

// 6. Constant variable
const float gravity = 9.8;
```

* More ways exist. Will be discussed later.

# C `printf` Function 

## Purpose of `printf`

* The `printf` function is used to produce **formatted output** in C.
* It originated in the C language and is now used in many others.
* Its power comes from the ability to control exactly how data is displayed.

## Syntax

```c
printf("format string", arg1, arg2, ...);
```

* The **first argument** is always a **format string**.
* This format string may include **plain text** and **conversion specifications** (placeholders).
* Each **placeholder** corresponds to a specific argument following the format string.
* If the **number of placeholders** and **arguments do not match**, or if **data types are mismatched**, the compiler generates a warning.

## Example

```c
int a = 42;
printf("Value is %d\n", a);
```

* `%d` is a placeholder for an `int`.
* `\n` adds a new line. `printf` does **not** automatically add a new line like `puts()`.

## Common Conversion Specifiers

Each specifier starts with `%` and ends with a **conversion character**. Between these two, optional flags and width/precision controls may appear.

| Specifier   | Data Type         | Description                                       |
| ----------- | ----------------- | ------------------------------------------------- |
| `%d` / `%i` | `int`             | Signed decimal integer                            |
| `%u`        | `unsigned int`    | Unsigned decimal integer                          |
| `%f`        | `float`, `double` | Floating-point decimal format                     |
| `%e` / `%E` | `float`, `double` | Scientific notation (e.g., `1.23e+02`)            |
| `%g` / `%G` | `float`, `double` | Automatically chooses `%f` or `%e` based on value |
| `%c`        | `char`            | Single character                                  |
| `%s`        | `char[]`          | String (null-terminated character array)          |
| `%x` / `%X` | `int`             | Hexadecimal integer (lowercase or uppercase)      |
| `%o`        | `int`             | Octal (base-8) integer                            |
| `%p`        | pointer           | Memory address (in hexadecimal format)            |
| `%%`        | -                 | Prints a literal `%` character                    |

| Format Specifier | Data Type           | Description                              |
| ---------------- | ------------------- | ---------------------------------------- |
| `%c`             | `char`              | Character input/output                   |
| `%d` or `%i`     | `int`               | Signed integer                           |
| `%u`             | `unsigned int`      | Unsigned integer                         |
| `%hd`            | `short`             | Short integer                            |
| `%ld`            | `long`              | Long integer                             |
| `%lld`           | `long long`         | Long long integer                        |
| `%f`             | `float` or `double` | Floating-point number (printf)           |
| `%lf`            | `double`            | Floating-point (scanf)                   |
| `%s`             | `char[]`            | String (null-terminated character array) |

## Format Modifiers

Format specifiers can be **customized** using modifiers for precision, width, and alignment.

### Width

Sets the minimum number of characters to print.

```c
printf("%5d", 42); // outputs: '   42'
```

### Precision

For floating-point values, precision controls the number of digits after the decimal point.

```c
printf("%.2f", 3.14159); // outputs: 3.14
printf("%.4f", 3.14159); // outputs: 3.1416
```

### Example with multiple specifiers

```c
char ch = 'A';
unsigned int x = 150;
float pi = 3.14159;

printf("Char: %c, Unsigned: %u, Pi: %.2f\n", ch, x, pi);
```

Output:

```
Char: A, Unsigned: 150, Pi: 3.14
```

## Editor Highlighting and Debugging

* Many modern editors highlight the format specifiers inside strings, which helps in visually verifying their placement and ensuring they match the arguments.
* If the number of placeholders and arguments does not match, the compiler typically emits a warning.
* Type mismatches can lead to undefined behavior or incorrect output.

## Documentation

* For a complete list of formatting options and advanced usage, consult the **manual page for section 3 (library functions)**:

```bash
man 3 printf
```

This will display detailed information about all format specifiers, flags, width and precision options, and behavior across data types.

# More about the Null terminator

* The **null terminator** is a special character in C, written as `'\0'`, that marks the **end of a string**.


### What It Is

* It's a **single byte** with the value `0`.
* It is automatically **appended at the end** of every string literal in C.

### Why It's Important

C does **not** store the length of strings explicitly.
Instead, C relies on the **null terminator** to know where the string ends.

So when you write:

```c
char name[32];
```

You're saying:

> “Reserve space for **31 visible characters** and **1 extra byte** for the null terminator.”

### Example

```c
char name[] = "Hassan";
```

Memory layout:

| Index | Value  |
| ----- | ------ |
| 0     | 'H'    |
| 1     | 'a'    |
| 2     | 's'    |
| 3     | 's'    |
| 4     | 'a'    |
| 5     | 'n'    |
| 6     | `'\0'` |

So, `"Hassan"` takes **7 bytes** — 6 letters + 1 null terminator.

### Why You Need to Be Careful

If you write:

```c
char word[6] = "Hassan";  // Error or undefined behavior!
```

You’re trying to fit 7 bytes into 6 — that overflows the array and breaks the string.

Always allocate **at least one extra byte** for the null terminator when creating strings manually.

# Constants in C

* Constants vs. Variables: Constants are values that never change, unlike variables. They can be declared using the const keyword or the define pre-processor directive.
    
* Literal Constants: These are values directly written in the code, such as numbers or characters.
    
* Constant Declarations: Using the const keyword, you can declare a constant that must be initialized at the time of declaration and cannot be changed later. Example:

  ```c
  #include <stdio.h>

  int main(){

    const int x = 10; // Cannot be reassigned/changed from here on.

    printf("Value of x is %d\n", x);
    printf("Value of x - 1 is %d\n", x - 1);

    return 0;
  }
  ```
    
* Pre-processor Directives: The define directive can be used to create constants that are accessible across multiple functions in a source code file. The preprocessor then replaces all the occurence of the constant with its real value.

  ```c

  #define MAX 20;

  #include <stdio.h>

  int main(){

    const int x = 10; // Cannot be reassigned/changed from here on.

    printf("Value of MAX is %d\n", MAX); // Changed to 20 before compilation by the preprocessor.
    printf("Value of MAX - 1 is %d\n", MAX - 1);

    return 0;
  }
  ```

Certainly — here's the same content formatted as **Markdown notes** with **no horizontal rules** and no emojis:

# C Storage Classes Overview

A **storage class** in C defines a variable's **scope** and **lifetime** — that is, where it can be accessed and how long it persists.

## Types of Storage Classes

### 1. `auto` (Automatic)

* The **default** storage class for local variables.
* Automatically applies to variables declared inside functions, even without using the `auto` keyword.
* Variables exist **only while the function runs**.
* The value is **discarded** when the function ends.
* Example:

  ```c
  auto int a = 5;  // same as just `int a = 5;`
  ```

### 2. `static`

* Also local to the function in which it's defined.
* Variable is not discarded after the function ends.
* Variable persists for the **entire lifetime of the program**.
* Example:

  ```c
  static int count = 0;
  ```

### 3. `extern` (External / Global)

* Declares a variable that is defined **outside any function**.
* Accessible to **all functions** in the file (and even other files with proper declaration).
* Used for **global variables**, but should be avoided unless absolutely necessary.
* If variables `A` and `B` are defined at the top of a file, outside of any function:

  ```c
  int A = 5;
  int B = 10;
  ```

You can use them inside functions by declaring them with `extern`:

  ```c
  void sum() {
      extern int A, B;
      int result = A + B;
  }
  ```

* This tells the compiler that the variables exist globally. While this works, it's generally better to limit global state for better code structure and maintainability.


### Important note

* In a function, variables `A` and `B` declared using `auto` are local and discarded after the function finishes.
* If `static` is used instead, the variables **keep their values** between calls.

A function like this:

```c
char* myname() {
    char me[] = "John";  // auto by default
    return me;           // returns pointer to a local variable
}
```

is problematic. The `me` array is local to the function and its memory is discarded after the function returns. Attempting to use the returned pointer in `main()` or elsewhere can lead to undefined behavior.
If the pointer points to a local (automatic) variable inside the function, you cannot return it. Because local variables live on the stack and are destroyed when the function returns, the pointer will become a dangling pointer (points to invalid memory).

To fix this, use `static`:

```c
char* myname() {
    static char me[] = "John";
    return me;
}
```

Now the string is retained in memory and safely returned.

### Best Practices

* Avoid excessive use of `extern` or global variables.
* Prefer local variables and pass data through function parameters when possible.
* Use `static` only when a variable truly needs to retain its value between calls.
* Avoid using `auto` explicitly, as it's the default and mostly unnecessary in modern C code.

# Defining custom data types with typedef

* typedef: The typedef keyword is used to create new data types in C. 
* It allows for defining a new name for existing data types, making code more readable and maintainable.
* Generally, a typedef is defined in a header file or at the top of a source file.

## Example with Custom Typedef

* You can create your own typedefs:

```c
typedef float radius;
radius a;
```

* This lets you use radius as an alias for float, improving code readability.
* printf can output the value of radius variables normally.
* Any non-standard data type you encounter, like time_t, was likely created using typedef.
* To understand these types fully, check documentation or header files.
* Documentation usually also indicates the correct printf format specifier to use with these types.

## Portability 

* Typedefs like time_t are defined by the system in standard headers (e.g., <time.h>).
* They abstract the underlying data type (e.g., long, int) to ensure code portability across systems.
* You don’t choose the exact type for system typedefs; the system/compiler does.
* You only define your own typedefs when creating custom types in your code.
* Using typedefs lets your code work consistently on different platforms without changes.

# Specifying characters and strings

### Character Literals in C

* Use **single quotes** for single characters: `'A'`, `'3'`, `'.'`
* Some special characters like **newline** or **tab** require **escape sequences**:

  * Newline: `'\n'`
  * Tab: `'\t'`
  * Single quote: `'\''`
  * Double quote (inside strings): `\"`
  * Hex value: `'\x41'` (which is `'A'`)
  * Null character / terminator: `\0`

* Escape sequences represent a **single character**, even if multiple symbols are used.

### Character Arrays and Strings

* C has **no built-in string type** — strings are just **character arrays**.
* Strings are created using **double quotes**: `"Hello"`
* All string literals are automatically **null-terminated** (`'\0'` at the end).
* You must handle the **null character** when working with strings manually.
* A character array can be initialized with a string literal:

  ```c
  char greeting[] = "Hello\n";
  ```

  * Here, the compiler sets array size automatically.
  * `\n` is a newline; `\0` is added automatically at the end.

# Numeric Literals and Data Types in C

### Integer and Real Number Types

* C has two main categories of numeric types:

  * `int`: for **integers** (whole numbers)
  * `float` and `double`: for **real numbers** (decimals, large/small values)

```c
int age = 30;
float pi = 3.14f;
double gravity = 9.80665;
```

### Integer Literals

* Written **without commas**: `100000000` (not `100,000,000`)
* Commas are invalid and lead to incorrect input or parsing

```c
int population = 100000000;    // valid
int invalid = 100,000,000;     // invalid — commas not allowed
```

### Real Number Literals

* Always include a **decimal point**:

  * `0.25`, `1.0`, or `.5`
* Adding `.0` or `0.` helps the compiler treat the value as a float/double
* Example:

```c
float rate = 0.25;
double one_billion = 1000000000.0;
float half = .5;
```

### Input Handling

* Use `fgets()` to read a number as a string
* Convert the string to a number using `strtol()` for integers
* `strtol()` does **not support commas**, so users should avoid typing them

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char buffer[20];
    printf("Enter a number: ");
    fgets(buffer, 20, stdin);
    /*
    strtol is used to parse number from strings. 
    NULL is used to indicate that we're not interested in knowing when the parsing stopped.
    10 is the base (decimal)
    */
    long value = strtol(buffer, NULL, 10);
    printf("You entered: %ld\n", value);
    return 0;
}
```

### Scientific Notation (E-notation)

* Use `E` or `e` for exponential form:

  * `2.5e6` means 2.5 × 10⁶
  * `2.5e-6` means 2.5 × 10⁻⁶
* Floating-point rounding may affect very small numbers

```c
#include <stdio.h>

int main() {
    float big = 2.5e6;
    float small = 2.5e-6;
    printf("Big: %e\n", big);
    printf("Small: %e\n", small);
    return 0;
}
```

### Hexadecimal and Octal

* **Hexadecimal (base 16)**:

  * Prefix: `0x`
  * Example: `0x1` to `0x10` (decimal 1 to 16)

* **Octal (base 8)**:

  * Prefix: leading `0`
  * Example: `01` to `010` (decimal 1 to 8)

```c
#include <stdio.h>

int main() {
    for (int x = 0x1; x <= 0x10; x++) {
        printf("Hex: 0x%X = %d\n", x, x);
    }

    for (int o = 01; o <= 010; o++) {
        printf("Oct: 0%o = %d\n", o, o);
    }

    return 0;
}
```

### Type Suffixes

* Suffixes clarify or enforce data type of literals:

  * `L` or `l`: long
  * `U` or `u`: unsigned
  * `F` or `f`: float (decimal point still required)
  * Combinations like `UL` or `lu` are valid

```c
long bigNumber = 1000000L;
unsigned int count = 500U;
float taxRate = 7.5F;
unsigned long long huge = 18446744073709551615ULL;
```

# Typecasting

* Typecasting allows you to temporarily change the data type of a variable for a specific operation.
* It helps in getting the correct result when performing operations like division, by treating integers as floating-point numbers.
* Typecasting does not change the variable's underlying data type; it only affects the specific expression where the cast is used.
* It can prevent potential errors or ensure the program generates the desired result, especially in cases where the proper data type is not used initially.
* It is done by specifying the type in brackets before an expression. Example: (float) or (int).

```c
#include <stdio.h>

int main(){

  int a = 100;
  int b = 7;

  /*
  Will not give the expected output because the format specifier for the result is set to `d` (decimal integer)
  */
  printf("The answer of %d/%d is %d\n", a, b, a/b);
  
  /*
  Will not give the expected output because the the format specifier is set to `f` (float), but the answer a/b is an integer
  */
  printf("The answer of %d/%d is %f\n", a, b, a/b);

  printf("The answer of %d/%d is %f\n", a, b, (float) a/b); // Typecast the answer a/b to a float. Correct output.

  return 0;
}
```

# Bitwise Shift Operators in C and C++ with Code Examples

Bitwise operators let you manipulate data at the bit level. This is a very low-level, fast, and efficient form of computation.

The two main shift operators are:

* `<<` Left Shift
* `>>` Right Shift

## Example 1: Left Shift — Doubling a Value

**Description**: Shifting bits to the left by 1 position is equivalent to multiplying the value by 2.

```c
#include <stdio.h>

int main() {
    int A = 1;
    int i = 0;
    while (i < 16) {
        printf("A = %d\n", A);
        A = A << 1;  // shift left by 1, same as A *= 2
        i++;
    }
    return 0;
}
```

**Explanation**:

* Starts with `A = 1`
* Each loop iteration shifts `A` left by 1 bit (multiplies by 2)
* After 16 iterations, `A` becomes a very large number

## Modified Example: Left Shift by 2 Positions — Faster Growth

**Description**: Shifting by 2 bits at once multiplies the value by 4.

```c
#include <stdio.h>

int main() {
    int A = 1;
    while (A <= 33000) {
        printf("A = %d\n", A);
        A = A << 2;  // shift left by 2, same as A *= 4
    }
    return 0;
}
```

**Explanation**:

* Much faster growth than shifting by 1
* Demonstrates exponential growth with bit shifts

## Example 2: Right Shift — Halving a Value

**Description**: Shifting bits to the right by 1 position is like dividing by 2 (integer division).

```c
#include <stdio.h>

int main() {
    int A = 15625;
    while (A > 0) {
        printf("A = %d\n", A);
        A = A >> 1;  // shift right by 1, same as A /= 2
    }
    return 0;
}
```

**Explanation**:

* Starts from 15,625
* Each iteration cuts the value in half
* Note: decimal parts are dropped (e.g., 15 / 2 = 7)

## Assignment Operator Equivalents

You can use shorthand versions of shift operations with assignment:

```c
A <<= 1;  // same as A = A << 1
A >>= 1;  // same as A = A >> 1
```
# Unary Operators in C – Explained with Examples

Unary operators act on **a single operand** (variable or value).
The term *"unary"* comes from Latin *unes*, meaning **one**.

## List of Common Unary Operators in C

1. `+` Unary plus
2. `-` Unary minus (negation)
3. `!` Logical NOT
4. `sizeof` Size-of operator

## 1. `sizeof` Operator

* Returns the number of **bytes** a variable or data type takes in memory.
* The return type is `size_t` (defined in `stdio.h` or `stddef.h`).
* Very useful in **memory allocation**, pointer arithmetic, and type introspection.

**Example:**

```c
#include <stdio.h>

int main() {
    char c;
    int i;
    float f;
    double d;
    char str[] = "Hello";
    int nums[10];

    printf("char: %zu bytes\n", sizeof(c));
    printf("int: %zu bytes\n", sizeof(i));
    printf("float: %zu bytes\n", sizeof(f));
    printf("double: %zu bytes\n", sizeof(d));
    printf("char array: %zu bytes\n", sizeof(str));
    printf("int array (10 elements): %zu bytes\n", sizeof(nums));

    return 0;
}
```

> Note: `%zu` is the correct format specifier for `size_t`. Output values can vary across systems.

## 2. `!` Logical NOT Operator

* Reverses a boolean expression.
* Returns `1` if the expression is false (0), and `0` if it’s true (non-zero).

**Important Note:** Always use **parentheses** when applying `!` to an expression — `!(a < 10)` — or it will only affect the variable directly after it.

**Example:**

```c
#include <stdio.h>

int main() {
    int a = 5;

    if (a < 10) {
        printf("*\n");  // Prints *
    }

    if (!(a < 10)) {
        printf("!\n");  // This will not print since a < 10 is true, but negated
    }

    return 0;
}
```

## 3. `+` Unary Plus and `-` Unary Minus

* `+a` means "positive a" (does nothing really).
* `-a` gives the **negative** of the value.
* Often used to flip signs or reinforce clarity in code.

**Example:**

```c
#include <stdio.h>

int main() {
    int a = 5;
    int b = -3;

    printf("+a = %d\n", +a);   // Just a = 5
    printf("-a = %d\n", -a);   // -5
    printf("+b = %d\n", +b);   // -3
    printf("-b = %d\n", -b);   // 3

    return 0;
}
```

> Although `+a` looks redundant, it’s still valid — and sometimes helps with clarity when paired with `-a`.

## Operator Precedence Note

Unary operators have **higher precedence** than arithmetic or logical operators, which is why `-a + b` works as expected. But be careful with parentheses when mixing with logical operators like `!`.

# Enums

An **enum** (short for *enumeration*) is a user-defined data type in C that allows a programmer to assign names to a set of integer constants, improving code readability and manageability.

### Syntax

```c
enum enum_name {
    constant1,
    constant2,
    constant3,
    ...
};
```

You can also declare variables when defining:

```c
enum enum_name {
    constant1,
    constant2
} variable_name;
```

### Example

```c
#include <stdio.h>

enum Days { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };

int main() {
    enum Days today = WEDNESDAY;
    printf("Day: %d\n", today); // Output: 3
    return 0;
}
```

### Default Values

* By default, the first name in an enum has the value `0`, the next `1`, and so on.
* Example:

  ```c
  enum Colors { RED, GREEN, BLUE };
  // RED = 0, GREEN = 1, BLUE = 2
  ```

### Custom Values

* You can explicitly assign values to enum constants:

  ```c
  enum Level { LOW = 1, MEDIUM = 5, HIGH = 10 };
  ```
* If a value is not specified, it is automatically incremented from the previous one:

  ```c
  enum Example { A = 1, B, C = 5, D };
  // A = 1, B = 2, C = 5, D = 6
  ```

### Typedef with Enum

To simplify usage:

```c
typedef enum { OFF, ON } SwitchState;
SwitchState s1 = ON;
```

### Uses of Enum

* Improves code readability.
* Makes it easier to manage sets of related constants.
* Reduces the chances of assigning invalid values (compared to `#define`).

### Notes

* Enum constants are essentially integers.
* Enums do **not** provide strict type safety in C (unlike in C++).
* You can use enums in `switch` statements for cleaner logic handling.