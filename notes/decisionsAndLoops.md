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