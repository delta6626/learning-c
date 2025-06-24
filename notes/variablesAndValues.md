# C Language Data Types, Input/Output, and Strings

## 1. Programming is Fundamentally About Input and Output

Programming is the process of receiving input, performing computation or modification, and producing output. In the C language, this process is explicit. Data is input by the user or read from a file, manipulated using variables and operations, and then output to the screen or elsewhere.

## 2. The Four Basic Data Types in C

C provides four fundamental built-in data types that describe what kind of information can be stored and manipulated in a program.

### `char`

Stores a single character or a single byte of data. Used for character-based input and output. It typically occupies 1 byte of memory. Characters are stored as ASCII values, so `'A'` is actually stored as the integer 65. The `char` type can be signed or unsigned, depending on the compiler.

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

C does not have a built-in `string` type like many other programming languages. Instead, strings are represented as arrays of `char` terminated by a null character (`\0`).

To store a string, a `char` array is declared:

```c
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