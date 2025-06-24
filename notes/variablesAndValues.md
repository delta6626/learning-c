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

### Common Format Specifiers

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