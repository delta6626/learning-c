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

# Overview of Multidimensional Arrays

Multidimensional arrays extend the concept of single-dimensional arrays. The most common form is the two-dimensional array, which functions like a grid or table with rows and columns. For instance, a 3x3 array represents 3 rows and 3 columns. Arrays can go further into three or more dimensions, forming structures like cubes. Each element is accessed using multiple indices, one for each dimension.

## Element Access

To reference a value, each index must be specified in the correct order. In a 2D array, the first index typically represents the row, and the second represents the column. A 3D array requires three indices, usually interpreted as depth (or layer), row, and column. The structure of the code often reflects this hierarchy through nested loops.

## Initialization of Multidimensional Arrays

Arrays can be initialized at the time of declaration. For 2D arrays, initialization is typically done with nested braces, one for each row. For example, a 3x3 array can be initialized with three sets of three values. The values are stored in row-major order, meaning the compiler fills rows one by one.

It is also possible to initialize arrays using a flattened list of values. The compiler maps them into the multidimensional structure based on the row-major rule. If the array is only partially initialized, the missing values are automatically set to zero.

In 3D arrays, each 2D slice is enclosed in its own brace block. This structure continues recursively for higher dimensions. A 3D array can also be initialized with a flat list, which the compiler interprets correctly using internal offsets.

## Uneven Dimensions and Compiler View

Each dimension in a multidimensional array does not need to have the same size. For example, a 2x3 array is valid and does not require a square structure. Despite the syntactic appearance, the compiler treats all arrays as one-dimensional in memory. Multidimensional notation is primarily for readability and logical organization.

## Manual Flattening

A programmer can simulate a multidimensional array using a single-dimensional array by manually computing the index using formulas. For a 2D array with `n` columns, the element at row `r` and column `c` is located at `r * n + c`. This technique mirrors how the compiler internally flattens array memory and allows for more flexible dynamic memory management, though it requires more care from the programmer.

  ```c
  #include <stdio.h>

  int main() {
      // Initialize a 3x3 matrix
      int matrix[3][3] = {
          {1, 2, 3},
          {4, 5, 6},
          {7, 8, 9}
      };

      // Print the matrix
      printf("2D Matrix:\n");
      for (int row = 0; row < 3; row++) {
          for (int col = 0; col < 3; col++) {
              printf("%d ", matrix[row][col]);
          }
          printf("\n");
      }

      return 0;
  }

  ```

# Structures

A **structure** is a user-defined data type that allows grouping variables of different types under one name. It's useful when modeling a complex entity such as a point, pixel, student, or employee, where different kinds of data describe a single unit.


## Declaring a Structure

A structure is defined using the `struct` keyword, followed by a name and a list of members.

```c
struct Pixel {
    int horz;
    int vert;
    char color;
};
```

This defines a structure named `Pixel` with two integers and one character as members. Each member is declared like a normal variable, and the entire structure ends with a semicolon.

## Declaring Structure Variables

You can declare a variable of this structure type after the definition:

```c
struct Pixel center;
```

Alternatively, you can define the structure and declare one or more variables in the same statement:

```c
struct Pixel {
    int horz;
    int vert;
    char color;
} center, top, bottom;
```

Now `center`, `top`, and `bottom` are all variables of type `struct Pixel`.

## Accessing Structure Members

Use the **dot operator** to access individual members of a structure:

```c
center.horz = 10;
center.vert = 15;
center.color = 'R';
```

Members behave like normal variables and can be used in expressions, printed, or passed to functions:

```c
printf("Center: (%d, %d) Color: %c\n", center.horz, center.vert, center.color);
```

## Initializing a Structure at Declaration

You can initialize a structure variable directly at the time of declaration using a brace-enclosed list.
Each value in the initializer must match the order and data type of the structure members:

```c
struct Pixel bottom = {20, 30, 'B'};
```

These are equivalent to:

```c
bottom.horz = 20;
bottom.vert = 30;
bottom.color = 'B';
```

## Full Example

```c
#include <stdio.h>

struct Pixel {
    int horz;
    int vert;
    char color;
} center, bottom = {20, 30, 'B'};

int main() {
    // Assign values to center

    struct Pixel top = {0, 0, 'G'};

    center.horz = 10;
    center.vert = 15;
    center.color = 'R';

    // Print all pixels
    printf("Center: (%d, %d) Color: %c\n", center.horz, center.vert, center.color);
    printf("Top:    (%d, %d) Color: %c\n", top.horz, top.vert, top.color);
    printf("Bottom: (%d, %d) Color: %c\n", bottom.horz, bottom.vert, bottom.color);

    return 0;
}
```

# Nesting Structures

A **nested structure** is a structure that contains another structure as one of its members. This allows modeling more complex data hierarchies where one structure logically "belongs to" another. It's useful when one field of a structure is itself a group of related fields.

## Declaring Nested Structures

```c
struct Point {
    int x;
    int y;
};

struct Pixel {
    struct Point position;
    char color;
};
```

Here, `Pixel` contains a `Point` as its member named `position`.

## Initializing Nested Structures

When initializing a nested structure, use nested braces to match the structure layout:

```c
struct Pixel p = { {10, 20}, 'R' };
```

or do this instead:

```c
struct Pixel p;
p.position.x = 10;
p.position.y = 20;
p.color = 'R';
```

This matches:

* `{10, 20}` for the nested `position` structure
* `'R'` for the color field

## Full Example

```c
#include <stdio.h>

// Define the inner structure
struct Point {
    int x;
    int y;
};

// Define the outer structure with the inner structure as a member
struct Pixel {
    struct Point position;
    char color;
};

int main() {
    // Declare and initialize the structure
    struct Pixel center = {{100, 200}, 'G'};
    struct Pixel origin;
    top.position.x = 0;
    top.position.y = 0;
    top.color = 'B';

    // Access members
    printf("Position: (%d, %d)\n", center.position.x, center.position.y);
    printf("Position: (%d, %d)\n", origin.position.x, origin.position.y);
    printf("Color: %c\n", center.color);
    printf("Color: %c\n", origin.color);

    return 0;
}
```