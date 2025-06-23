# C History

- Created by Brian Kernighan and Dennis Ritchie - Developers of the UNIX O.S.
- Based on the B language.
- Is a Mid-Level language.
- Is a procedural language (doesn't support classes and objects)
- Designed as an improvement over assembly for writing efficient, portable code.
- Code written in C can run on different platforms with minimal changes.

Here's the same content, reformatted without horizontal rules:

# Basic Structure and Readability of C Code

## Code Appearance and Purpose

* Computer code in C has a specific, recognizable format
* This structure ensures readability and understanding for other programmers
* C code executes in a **top-down** manner

## Comments in C

* Comments are enclosed between `/*` and `*/` (multiline) or `//` (single line)

## Preprocessor Directives

* Example: `#include <stdio.h>`
* This is a **preprocessor directive** that tells the compiler to include the contents of the standard I/O header file
* These directives must be on their **own line**

## The `main` Function

* All C programs start with the `main` function
* It returns an **int** (integer) and is declared as `int main()`

## Function Body and Braces

* Functions contain **statements** enclosed in **curly braces `{}`**
* Braces are used to group multiple statements into a **block**
* Braces are also used in:

  * Loop structures (`for`, `while`)
  * Decision structures (`if`, `else`, `switch`)

## Statements in C

* A **statement** is a command or expression in C (e.g., assignment, function call, math operation)
* All statements **end with a semicolon `;`**
* Exceptions:
  * Control structures like `for` or `if` don’t have a semicolon if followed by a block

## Whitespace

* Items like **tabs**, **spaces**, and **blank lines** are collectively called **whitespace**
* Whitespace improves **readability**, but is **ignored by the compiler**
* Removing whitespace does not change the code’s behavior
* However, preprocessor directives must remain on **separate lines**
* For example, all statements of `main()` can appear on a single line and still work