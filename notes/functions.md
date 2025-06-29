# C Functions

* C does not enforce when to write functions, but it's good practice to use them for repeated tasks or specific operations.
* Use functions to:

  * Avoid code repetition.
  * Handle specific tasks (e.g., complex calculations).
  * Improve code readability and maintainability.

### Function Declaration and Definition

* Syntax:

  ```c
  return_type function_name(argument_list) {
      // statements
  }
  ```
* If no value is returned: use `void`.
* If no arguments are needed: list `void` inside the parentheses.

### Function Naming

* Use the same rules as for naming variables.
* Descriptive names help self-document the code.

### Function Return

* Functions that return values must use the `return` statement to send the value back to the caller.

### Function Prototyping

* Functions must be introduced to the compiler before use.
* Two options:

  1. **Define the function before `main()`** – no prototype needed.
  2. **Declare a prototype** above `main()` – ends with a semicolon.

     ```c
     int sum(int, int);  // prototype
     ```

### Function Order in Code

* Even though `main()` is the entry point, functions used in it must be defined or prototyped earlier in the file.
* Example:

  ```c
  // Option 1: Prototype
  int sum(int, int);

  int main() {
      int result = sum(2, 3);
  }

  int sum(int a, int b) {
      return a + b;
  }
  ```

  or

  ```c
  // Option 2: Function defined before main
  int sum(int a, int b) {
      return a + b;
  }

  int main() {
      int result = sum(2, 3);
  }
  ```

### Standard Library Function Prototypes

* Functions like `printf` and `puts` are prototyped in header files (e.g., `stdio.h`).
* Always include necessary headers at the top of your code.

### Example of Function for Repetition

* Repeating lines like:

  ```c
  printf("Press any key to continue: ");
  getchar();
  ```

  can be replaced with a custom function:

  ```c
  void pressAny() {
      printf("Press any key to continue: ");
      getchar();
  }

  // Usage in main
  pressAny();
  ```

* Benefit: reduces redundancy and improves readability.

### Summary

* Use functions to reduce redundancy, isolate logic, and clarify purpose.
* Always introduce functions to the compiler before their use via prototypes or by defining them earlier.
* Even short or one-line repetitive actions can benefit from being placed into functions.

# return statement

* Return Keyword: Functions use the return keyword to send a value back to the calling function. The returned value must match the function's data type.
    
* Single Return Value: Functions in C can only return a single value. To return multiple values, you can use pointers or structures.
    
* Void Functions: Even functions that do not return a value (void functions) can use the return keyword to exit early.

Got it. Here's the cleaned-up version of your notes, following your formatting preference.

---

# Command-Line Arguments in C

* Programs are launched using command-line instructions, even on graphical operating systems. In C, command-line arguments are accessed through the main function.

* Main function with arguments

```c
int main(int argc, char *argv[])
```

Parameters
argc

* Argument count
* Represents the number of items passed via the command line (including the program name itself)

argv

* Argument vector
* An array of strings (character pointers)
* Each argument is a separate string
* argv\[0] is always the program's name
* argv\[1] to argv\[argc - 1] are the actual arguments

Example
Command:

```
./my-c-program file.txt "hello world" 123
```

Values:

```
argc == 4
argv[0] -> "./program"
argv[1] -> "file.txt"
argv[2] -> "hello world"
argv[3] -> "123"
```

Note
Arguments with spaces must be enclosed in quotes. Otherwise, each word is treated as a separate argument.

Usage
You can use argc to check if any arguments were passed:

```c
if (argc > 1) {
    // process arguments
}
```

You can use argv strings in expressions, comparisons, or for file operations. They behave like regular string pointers.

If you don’t need arguments, you can leave the parentheses in main empty. Do not use `void` inside the parentheses in that case.

# Static Variables in C Functions

When a function ends, all variables declared inside it are normally discarded. This is because their **storage class** is automatic by default (`auto`), which means they are **created when the function starts** and **destroyed when it ends**.

### Local Variables Are Isolated

* Variables with the same name in different functions are separate.
* Changing a variable in one function does not affect a variable of the same name in another function.

### Example Problem

* A function declares a local variable `a = 0`, then increases it by 16.
* The function is called multiple times.
* Expectation: the value keeps increasing with each call.
* Reality: the value resets to 0 each time because the variable is re-declared and re-initialized on every call.

### Solution: Use `static`

* Declaring the variable as `static` inside the function allows it to **retain its value between calls**.
* Static variables are initialized only once, when the function is first called.
* The variable is not re-created or re-initialized on later calls.

```c
int funct() {
    static int a = 0;  // Initialized only once
    a += 16;
    printf("%d\n", a);
    return a;
}
```

* When the function runs multiple times, `a` continues increasing: 16, 32, 48, etc.

### Important Detail

* If you write:

```c
static int a;  // declared without initialization
a = 0;         // assigned in the function body
```

Then `a = 0` runs **every time**, so the value resets on each call. This defeats the purpose of `static`.

* Best practice: **initialize static variables at the point of declaration**, not later.

### Use Cases for `static` in Functions

* Counters
* Buffers
* Accumulators
* State that must persist across function calls

### Summary

* Local variables are normally temporary.
* Use `static` when a local variable needs to keep its value between function calls.
* Initialize `static` variables as they are declared.
