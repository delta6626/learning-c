# **Running External Programs**

In some situations, a program might need to run another external program—for example, to execute a system command or use an existing utility instead of rewriting its functionality. C provides mechanisms to facilitate this through the `system()` and `popen()` functions.

## **1. The `system()` Function**

### **Purpose:**

* Used to execute an external system command.
* Control is temporarily passed to the operating system to run the command.
* Once the command is executed, control returns to the program.

### **Header File:**

```c
#include <stdlib.h>
```

### **Syntax:**

```c
int system(const char *command);
```

### **Usage Example:**

```c
system("clear"); // Clears the terminal screen (on Unix-like systems)
```

### **Behavior:**

* The command is passed as a string to the operating system.
* The program does **not** receive or interact with the output of the command.
* The return value typically indicates the command’s exit status.

### **Limitations:**

* No access to the output of the executed command.
* Security risks if untrusted input is passed into `system()`.

## **2. The `popen()` Function**

### **Purpose:**

* Opens a process by creating a pipe, for either reading from or writing to the process.
* Allows the program to **capture the output** of an external command.

### **Header File:**

```c
#include <stdio.h>
```

### **Syntax:**

```c
FILE *popen(const char *command, const char *mode);
```

* `command`: the shell command to execute.
* `mode`: `"r"` for reading output from the process, `"w"` for writing input to it.

### **Usage Example:**

```c
FILE *p;
p = popen("uname", "r");
```

* This opens a process that executes the `uname` command and allows the program to read its output.

### **Reading Output from the Process:**

```c
int c;
while ((c = fgetc(p)) != EOF) {
    putchar(c);
}
```

* Reads each character from the output stream of the command and prints it to the standard output.

### **Closing the Process:**

```c
pclose(p);
```

* Terminates the process and closes the associated pipe.
* Analogous to `fclose()` for files.

## **Key Differences: `system()` vs `popen()`**

| Feature         | `system()`                       | `popen()`                             |
| --------------- | -------------------------------- | ------------------------------------- |
| Returns output? | No                               | Yes                                   |
| Interactivity   | Not suitable for interactive I/O | Not suitable for interactive I/O      |
| Complexity      | Simple to use                    | Slightly more complex, file-like API  |
| Control         | One-way execution                | Two-way (read/write) with the process |

## **Common Use Cases**

* **`system()`**

  * Simple tasks like clearing the screen, listing files, or restarting a service.
* **`popen()`**

  * Capturing output from utilities (e.g., system info, network status).
  * Analyzing or processing command output within a C program.
  * Creating custom wrappers for shell utilities.

# **Math Functions**

The C language provides basic arithmetic operators (`+`, `-`, `*`, `/`, `%`), but for more advanced operations like exponentiation, square roots, trigonometry, and logarithms, you must use **functions from the `math.h` library**.

## **1. Using the Math Library in C**

### **Header File:**

```c
#include <math.h>
```

* This allows access to the declarations (prototypes) of math functions like `pow()`, `sqrt()`, `sin()`, etc.

### **Linking the Library:**

Unlike other standard headers like `string.h` or `stdio.h`, you must **manually link** the math library when compiling:

```bash
gcc myfile.c -lm
```

or

```bash
clang myfile.c -lm
```

### **Why Manual Linking Is Needed for `math.h`**

| Header     | Auto Linked? | Requires `-l` Flag? | Notes                                                                                                                      |
| ---------- | ------------ | ------------------- | -------------------------------------------------------------------------------------------------------------------------- |
| `stdio.h`  | ✅ Yes        | ❌ No                | Part of the core standard library                                                                                          |
| `string.h` | ✅ Yes        | ❌ No                | Part of the core standard library                                                                                          |
| `math.h`   | ❌ No         | ✅ Yes (`-lm`)       | Functions live in a **separate math library (`libm`)**, not included by default to reduce executable size and compile time |

> Including `math.h` gives you the **function declarations**, but the actual function definitions (binary code) are in `libm`. You must link this in manually on the command line with `-lm`.

## **2. Common Math Functions in `math.h`**

### **a. `pow()` – Exponentiation**

```c
double pow(double base, double exponent);
```

**Example:**

```c
printf("2^3 = %.0f\n", pow(2.0, 3.0)); // Outputs 8
```

* Raises a number to a given power.
* Arguments and return value are of type `double`.
* Used commonly in loops for powers of a base.

### **b. `sqrt()` – Square Root**

```c
double sqrt(double x);
```

**Example:**

```c
double a = 16.0;
printf("sqrt(%.1f) = %.1f\n", a, sqrt(a)); // Outputs 4.0
```

* Computes the square root of a value.
* Returns NaN if given a negative number.

### **c. Trigonometric Functions (Radians-Based)**

Functions include:

* `sin(x)`
* `cos(x)`
* `tan(x)`
* `asin(x)`, `acos(x)`, `atan(x)`

**Important:** Arguments must be in **radians**, not degrees.

#### **Conversion:**

* Degrees → Radians: `radians = degrees * (π / 180)`
* Radians → Degrees: `degrees = radians * (180 / π)`

**1 radian ≈ 57.2958 degrees**

### **d. Logarithmic Functions**

| Function   | Description                  |
| ---------- | ---------------------------- |
| `log(x)`   | Natural logarithm (base *e*) |
| `log10(x)` | Base-10 logarithm            |

### **e. Rounding Functions**

| Function   | Description                    |
| ---------- | ------------------------------ |
| `ceil(x)`  | Rounds up to nearest integer   |
| `floor(x)` | Rounds down to nearest integer |
| `round(x)` | Rounds to nearest integer      |

## **3. Constants in `math.h`**

Some math-related constants are defined in C99 or later:

| Constant  | Meaning            | Approximate Value |
| --------- | ------------------ | ----------------- |
| `M_PI`    | π (pi)             | 3.14159           |
| `M_E`     | Euler’s number (e) | 2.71828           |
| `M_SQRT2` | √2                 | 1.41421           |

> Note: On some systems, you may need to define `_USE_MATH_DEFINES` before including `math.h` to access these constants.

## **4. Compiling Math Code (Command-Line Example)**

```bash
clang mymath.c -lm
./a.out
```

* `-lm`: Links in the math library (`libm`)
* `./a.out`: Runs the compiled output

> In some IDEs (like Visual Studio or Code::Blocks), linking is handled automatically. On Unix-based command lines, it's your responsibility to add `-lm`.

## **5. Exploring More Math Functions**

If you're on a Unix/Linux system, you can view all math functions with:

```bash
man math
```

This opens the manual pages for `math.h`, listing all available functions, constants, and usage tips.