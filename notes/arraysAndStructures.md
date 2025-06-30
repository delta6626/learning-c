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

## Passing array to functions

* Passing Individual Elements vs. Whole Array: Arrays can be passed to functions either as individual elements or as a whole. Individual elements are passed by specifying the element, while the whole array is passed by its name.
    
* Modification of Arrays: When an entire array is passed to a function, the function can modify the array's contents. This modification affects the original array as well.
    
* Returning Arrays: Returning arrays directly from functions in C is not possible. Instead, pointers should be used to handle the return of array-like data.