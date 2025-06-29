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
