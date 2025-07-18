# C History

* Created by Brian Kernighan and Dennis Ritchie - Developers of the UNIX O.S.
* Based on the B language.
* Is a Mid-Level language.
* Is a procedural language (doesn't support classes and objects)
* Designed as an improvement over assembly for writing efficient, portable code.
* Code written in C can run on different platforms with minimal changes.

Here's the same content, reformatted without horizontal rules:

# Basic Structure and Readability of C Code

## Code Appearance and Purpose

* Computer code in C has a specific, recognizable format
* This structure ensures readability and understanding for other programmers
* C code executes in a **top-down** manner

## Comments in C

* Comments are enclosed between `/*` and `*/` (multiline) or `//` (single line)
* C language uses two styles of comments: traditional C comments (/* ... */) and C++ style comments (//).

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

Here are the notes based on the transcript, formatted in Markdown with no emojis and no horizontal rules:

# C Language Development Cycle

## Three Main Steps

1. **Write the source code**
2. **Compile and link**
3. **Test run the program**

## Step 1: Write the Source Code

* Use a **text editor** to write C programs
* C source code is **plain text**, no special formatting or fonts
* Code runs **top-down**, just like reading text
* Save the file with a `.c` extension (e.g., `program.c`)
* A **skeleton source code file** is often used to start new projects
* Text editors are often part of an **IDE (Integrated Development Environment)**

## Step 2: Compile and Link

* The **compiler** translates source code into **object code**
* The **linker** combines object code with **C libraries** to create the final executable program
* In modern IDEs, **compiling and linking** are combined into a single action: **build**

### Object Code

* When you compile your C source code (.c file), the compiler translates the human-readable instructions into a lower-level form called object code.

* Object code is not yet a full program; it’s like a partially completed puzzle piece. It contains machine instructions, but these are not yet fully connected into a runnable program.

* The object code includes tokens and shortcuts:

* Tokens are the basic units of meaning (like keywords, operators, and identifiers) transformed into 
machine-understandable form.

* Shortcuts mean the compiler leaves some parts unresolved, especially calls to external functions (like printf) or variables defined elsewhere.

* The file extension for object code is usually .o (or .obj on Windows). For example, if your source file is program.c, compiling creates program.o.

* The reason for creating object code instead of jumping straight to an executable is to support modular programming: Large programs are often split into multiple .c files. Each .c file is compiled separately into its own .o object file. This way, you only need to recompile changed files instead of the entire program every time.

### Linking

* After the compiler creates one or more object code files, the linker takes over.

* The linker's job is to combine all the object files plus the necessary library code into a single executable program.

* Library functions are pre-written code routines (like those in stdio.h for input/output) that your program uses but you didn’t write yourself. These are provided by the system or compiler.

* The linker resolves references:

* For example, your code calls printf, but printf is defined in a system library, not your source code. The linker finds the compiled printf code inside a C standard library file and connects it to your program.

* Linking also resolves references between your own object files if you have multiple source files calling functions in each other.

* The output of the linker is a complete executable program that can run on your computer or target platform.

## Step 3: Test Run

* Just run the damn thing!

# C Pre-Processor Directives

* The C pre-processor is a tool that prepares a source code file before it is compiled. It handles special instructions called pre-processor directives. These are not part of the C language itself but are processed   before actual compilation. They allow tasks such as file inclusion, code substitution, and macro definition.

## Key Features

Pre-processor directives:

* Begin with a hash (`#`) symbol at the start of a line.
* Are followed by the directive name, a space, and any arguments.
* Do **not** end with a semicolon.
* Are usually placed at the beginning of the source file but can appear anywhere.
* Can be disabled by enclosing them in comments.

## Common Directives

### `#include`

This directive inserts the contents of another file into the source code at the point where it appears.

* Syntax:

  * `#include <filename>`: Searches for the file in standard system directories.
  * `#include "filename"`: Searches for the file relative to the current source file's directory.

On Linux, standard header files are located in `/usr/include` or `/usr/local/include`. On Windows, they are found in directories relative to the compiler's installation.

### `#define`

Used to define symbolic constants and macros.

* Example: `#define COUNT 10`
  Every instance of `COUNT` in the code is replaced by `10` during preprocessing. This improves maintainability since changing the value in one place updates all usages.

* Constants are usually written in all uppercase letters for clarity.

* String literal example:
  `#define GREETING "Howdy do"`
  This expands to the string including the quotes and can be used in functions like `puts(GREETING)`.

* Macro example:
  `#define charout(A) putc(A)`
  This replaces `charout('H')` with `putc('H')` at compile time, allowing for reusable code snippets.

# Header files vs Libraries

* In C programming, header files and libraries serve distinct purposes in the build process. Header files are used during the compilation phase, while libraries are used during the linking phase. 

## Header files

* Header files typically contain function prototypes, macro definitions, constants, and other pre-processor directives. These files are written in C and reside in directories like /usr/include on Unix systems. They tell the compiler what functions are available, their argument types, and their return types to perform type checking.

* Typically found in /usr/include or /usr/local/include on Unix systems. On Windows, the location is relative to the compiler’s installation directory.

## Libraries

* Libraries, on the other hand, are collections of pre-compiled object code that provide the actual implementation of functions declared in header files. 

* Some libraries, like the math library (libm), must be linked manually. When using functions such as sqrt or sin, you must include the header file math.h and also link the math library using the -lm flag (specific to math library) in the compiler command. If you omit the header, the compiler issues a warning. If you forget to link the library, the linker will produce an error due to unresolved references.

* Typically found in /usr/lib on Unix systems. On Windows, the location is relative to the compiler’s installation directory.

## Man pages

* Use the man command followed by a function name to find which header file and library is needed for that specific function and how to link the library.