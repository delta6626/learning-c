# Ternary operator

* condition ? expression_if_true : expression_if_false;

  ```c
  int a = 5;
  int b = 10;
  int c = (a > b) ? a : b;
  printf("%d\n", c); // 10
  ```

# Switch statements

* The switch-case structure in C uses the keywords switch, case, default, and break to control program flow /based on the value of an expression.

* Unlike if statements, the switch statement evaluates an expression that results in a single value, which is then compared against the values specified in each case statement.

* The break keyword is used to exit the switch-case block, preventing fall-through to subsequent cases. If break is omitted, execution continues to the next case.

  ```c
  char x = 'A';
  switch(x){
    case 'A':
    case 'a':
      puts("First letter of the alphabet");
      break;
    case 'B':
    case 'b':
      puts("The second letter!");
      break;
  }
  ```

* The default case handles any values that do not match any of the specified cases, ensuring all possible inputs are accounted for

# For loops

**Structure of a `for` loop**
A `for` loop in C consists of three parts: initialization, condition, and increment/decrement. These are placed within parentheses and separated by semicolons.

**Syntax:**

```c
for (initialization; condition; increment/decrement) {
    // loop body
}
```

**Example:**

```c
for (int i = 0; i < 5; i++) {
    printf("%d\n", i);
}
```

**Loop execution**

* The initialization runs once at the start of the loop.
* The condition is evaluated before each iteration.
* If the condition is true, the loop body executes.
* After each iteration, the increment/decrement part is executed.
* The loop stops when the condition becomes false.

**Multiple expressions in a for loop**
You can use multiple expressions in the initialization and increment/decrement sections by separating them with commas.

**Example:**

```c
for (int i = 0, j = 10; i < j; i++, j--) {
    printf("i = %d, j = %d\n", i, j);
}
```

**Endless loops**
If you omit the condition, the loop will run indefinitely. It continues until it is manually broken with a `break` statement or program termination.

**Example:**

```c
for (;;) {
    // infinite loop
    printf("Running...\n");
}
```