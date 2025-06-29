# Arrays

* Arrays store multiple values of the same data type under one variable name.
* They are more efficient than declaring multiple separate variables for similar data.
* Array declaration syntax:
  `data_type array_name[number_of_elements];`
  Example: `float highscore[5];`
* Arrays can be initialized at the time of declaration using curly braces `{}` with comma-separated values.
* If values are provided during initialization, the size can be omitted:
  `float highscore[] = {98.5, 87.0, 92.3, 76.4, 88.1};`
* Array elements are accessed using zero-based indexing.
  First element: index 0, last element: index (size - 1).
* Index values can be literals, variables, or expressions.
* Arrays in C have a fixed size once declared; they are not dynamically resizable.
* To create resizable data structures, dynamic memory (with pointers) is used.
* C does not automatically check array bounds.
  Accessing invalid indices can lead to bugs or crashes.
* Always track array size to avoid errors and maintain program stability.
