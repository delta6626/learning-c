# **Pointers in C**

* A **pointer** is a **variable that holds a memory location**.
* More specifically, it **stores the address** of another variable in memory.
* It **does not "point at" a variable** in the abstract sense; it **holds** the address of that variable.

## **1. Background: Variables and Memory**

### **Variables in C**

From this declaration:

```c
int alpha = 27;
```

We can observe:

* **Data type**: `int`
* **Variable name**: `alpha`
* **Assigned value**: `27`

### **Memory Details**

* Use `sizeof` to get the size of the variable (in bytes):

  ```c
  printf("Size: %zu bytes\n", sizeof(alpha));  // Typically 4 bytes
  ```
* Use the **ampersand (`&`) operator** to get its address:

  ```c
  printf("Address: %p\n", &alpha);
  ```

These concepts lay the foundation for understanding **pointers**.

## **2. Pointer Basics**

### **Definition**

> A pointer is a **variable** that **holds the memory address** of another variable or buffer.

### **Declaration**

```c
int *ptr;
```

* `int`: the data type of the variable the pointer will point to.
* `*ptr`: declares `ptr` as a pointer to an `int`.
* The `*` is **not multiplication here** — it’s part of the **declaration syntax** for a pointer.

### **Important Note**

* A pointer is **still just a variable**, but its **value is an address**, not data.

## **3. Pointer Initialization**

### **The Right Way**

* You must **initialize** a pointer before using it. An uninitialized pointer can cause **undefined behavior**.
* Initialize using the **address-of operator (`&`)**:

  ```c
  int alpha = 27;
  int *ptr = &alpha;
  ```

### **Common Misuse**

* Declaring a pointer without initialization:

  ```c
  int *ptr;  // ❌ unsafe if used before initialization
  ```

## **4. Using a Pointer: Two Personalities**

### **Pointer Used By Itself**

```c
printf("%p\n", ptr);
```

* This prints the **address** stored in the pointer.

### **Dereferencing a Pointer**

```c
printf("%d\n", *ptr);
```

* This accesses the **value at the memory location** the pointer holds.
* `*ptr` dereferences the pointer — i.e., it gives you the **data** at the address.

### **Summary of Roles**

| Expression | Meaning                           |
| ---------- | --------------------------------- |
| `ptr`      | The **address** the pointer holds |
| `*ptr`     | The **value** at that address     |

## **5. Pointer and Variable Type Matching**

* Pointer type must match the variable type it points to:

  ```c
  int *iptr;     // points to int
  char *cptr;    // points to char
  float *fptr;   // points to float
  ```

* Mismatched types lead to **compiler warnings or logic errors**.

## **6. Pointers and scanf()**

* `&` is used in `scanf()` to **pass the address** of a variable:

  ```c
  int alpha = 20;
  int *ptr = &alpha;

  // both are equivalent

  scanf("%d", &alpha);  
  scanf("%d", ptr);
  ```

## **8. Why Pointers Matter**

* Enable **dynamic memory** management.
* Essential for **function argument passing** by reference.
* Required for handling **arrays**, **strings**, and **data structures** like linked lists.
* Allow low-level **memory manipulation**.

# Pointer math

### **Pointer Arithmetic – Adding 1 to a Pointer**

```c
printf("%p\n", pa);     // prints address of alpha
printf("%p\n", pa + 1); // prints address + 1
```

* Adding 1 to a pointer increases the address by the **size of the data type** the pointer points to.

* For `int *`, the increment is typically **4 bytes**.
* This means:

  * If `pa = 0x1000`, then `pa + 1 = 0x1004` (assuming `sizeof(int) == 4 (bytes)`).

### **Unsafe vs Safe Pointer Arithmetic**

* **Unsafe**: Doing pointer arithmetic that points outside the valid memory bounds (e.g., `pa + 1` when `pa` doesn’t point to an array) results in referencing unknown or invalid memory.
* **Safe**: When operating within an array, pointer arithmetic can safely traverse the array elements.
* Pointer arithmetic is safe only when you're working within the bounds of an array.

### **Pointers and Arrays**

```c
int twos[] = {2, 4, 6, 8, 10};
int *pt = twos;
```

* No ampersand is needed in `pt = twos;` because the array name (`twos`) decays to a pointer to its first element.
* `pt` points to the first element of the array.
* `pt + 1` points to the second element of the array.
* Address difference:

  * `pt` vs `pt + 1` shows a 4-byte difference (again, due to `int` size).

### **Pointer Arithmetic and Data Type Size**

Pointer arithmetic is directly affected by the data type the pointer points to:

| Data Type | Size (Bytes) | Pointer Increment (`ptr + 1`) |
| --------- | ------------ | ----------------------------- |
| `char`    | 1 byte       | +1 byte                       |
| `int`     | 4 bytes      | +4 bytes                      |
| `float`   | 4 bytes      | +4 bytes                      |
| `double`  | 8 bytes      | +8 bytes                      |

Examples:

* `char *pc` → `pc + 1` increases address by 1 byte.
* `double *pd` → `pd + 1` increases address by 8 bytes.

### **Pointer Math Summary**

* Pointer arithmetic increases or decreases the address stored in the pointer by **multiples of the size of the data type**.
* This behavior allows pointer variables to traverse arrays element by element, regardless of element size.
* The actual address manipulation:

  ```c
  ptr + i → address + i * sizeof(type)
  ```

### **Use of `sizeof` Operator**

* The `sizeof` operator is used to determine how many bytes a data type occupies in memory.
* Note: %zu is the correct specifier for printing unsigned size_t values
* Example:

  ```c
  printf("%zu", sizeof(int));    // typically prints 4
  printf("%zu", sizeof(double)); // typically prints 8
  ```

### **Practical Implications**

* Pointer arithmetic is essential for:

  * Array traversal
  * Dynamic memory management
  * Efficient algorithm implementation (e.g., iterators, memory buffers)
* Understanding how pointer arithmetic scales with data type size is critical for writing correct and safe C programs.

# Understanding Pointers and Arrays

### 1. **Character Arrays and `scanf()`**

* **Character Array Example**:

  ```c
  char text[10];
  scanf("%s", text); // No & operator needed
  ```
* **Why no `&`?**

  * Arrays already act like **pointers to their first element**.
  * So `text` is interpreted as a memory address (`&text[0]` implicitly).
* **Contrast**:

  ```c
  int x;
  scanf("%d", &x); // You need & for individual variables
  ```

### 2. **Array Name as a Pointer**

* When you write:

  ```c
  int arr[5] = {2, 4, 6, 8, 10};
  int *pt = arr;  // No & needed
  ```

  * `arr` decays to a pointer to its first element.
  * `pt` now holds the same address as `arr`.

* **Verifying the addresses**:

  ```c
  printf("%p\n", pt);    // address of pt
  printf("%p\n", arr);   // same address as above
  ```

### 3. **Accessing Array Elements with Pointers**

* You can access array elements using both:

  * **Array notation**: `arr[2]`
  * **Pointer notation**: `*(pt + 2)`

* Example using a loop:

  ```c
  for (int i = 0; i < 5; i++) {
      printf("Address: %p, Value: %d\n", (pt + i), *(pt + i));
  }
  ```

### 4. **Why Parentheses Matter**

* To access an array element with pointer arithmetic:

  ```c
  *(pt + 1)  // Correct: fetches value at next address
  ```
* Without parentheses:

  ```c
  *pt + 1    // Wrong: adds 1 to the value at pt
  ```

  * This returns: `(*pt) + 1`, not what you intended.

### 5. **Deconstructing Access**

```c
*(pt + 0) // same as pt[0]
*(pt + 1) // same as pt[1]
...
```

* This shows **equivalence** between pointer arithmetic and array indexing.
* But pointer math requires precision — formatting matters!

### 6. **Pointers vs Arrays – Similar but Different**

| Feature               | Pointer       | Array              |
| --------------------- | ------------- | ------------------ |
| Acts as address?      | Yes           | Yes (base address) |
| Can be reassigned?    | Yes           | No                 |
| Can be resized?       | Dynamically   | Fixed size         |

### 7. **Accessing Elements Using Pointers (Steps)**

1. **Declare** a pointer of the same data type as the array.
2. **Initialize** the pointer to the base address of the array.
3. Use `*pointer` to access the value.
4. Use `pointer + n` to move to the nth element.
5. Wrap the pointer math in `()` before dereferencing:

   ```c
   *(pt + n)
   ```

# Dynamic Memory Allocation with `malloc()` and `free()`

### 1. Allocating Memory on the Fly

* When a program needs a block of memory **dynamically** (at runtime), it uses the `malloc()` function.
* `malloc()` is declared in the **`<stdlib.h>`** header, so this must be included.
* You declare a pointer (e.g., `char *buffer`) to hold the address of the allocated memory.

### 2. How `malloc()` Works

```c
char *buffer = malloc(128 * sizeof(char));
```

* `malloc()` takes **one argument:** the number of bytes to allocate.
* Here, it allocates space for **128 characters**.
* Multiplying `128 * sizeof(char)` ensures correct byte count, making the code adaptable if the data type changes.
* The function returns an **address** to the start of the allocated memory.
* If allocation **fails**, `malloc()` returns the **NULL pointer**.

### 3. Checking Allocation Success

```c
if (buffer == NULL) {
    printf("Memory allocation failed\n");
    exit(1); // Immediately exits the program
}
```

* Immediately after allocation, check if `buffer` is `NULL`.
* 
* If yes, print an error and **exit**.
* The `exit()` function terminates the program immediately and can be used anywhere (unlike `return` which exits only from functions).

### 4. Using the Allocated Memory

* Once allocated, the buffer can be used to store data.
* Even if your code doesn’t use the buffer immediately, successful allocation means the memory is reserved.

### 5. Freeing Memory After Use

```c
free(buffer);
```

* Once done, **free** the allocated memory to avoid memory leaks.
* `free()` takes the pointer to the allocated block and releases the memory back to the system.
* It returns **no value**.
* The `free()` and `exit()` function is also defined in `stdlib.h` header file.

### 6. Important: Keep the Original Pointer for `free()`

* You **must keep the original pointer address** returned by `malloc()`.
* **Do not modify the original pointer** by incrementing it (e.g., `buffer++`).
* If you change the pointer and then pass it to `free()`, the behavior is undefined and likely to cause errors.

### 7. Accessing Elements Safely with Pointer Arithmetic

```c
for (int i = 0; i < 20; i++) {
    *(buffer + i) = i * 10; // Assign value without modifying 'buffer'
    printf("%d\n", *(buffer + i));
}
```

* Use a **separate pointer or pointer arithmetic** to navigate the allocated block.
* Incrementing **copies or offsets** the pointer for reading/writing but does **not modify** the original pointer.

### 8. Example Summary

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *buffer = malloc(20 * sizeof(int));
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < 20; i++) {
        *(buffer + i) = i * 10;
        printf("%d\n", *(buffer + i));
    }

    free(buffer); // safe because 'buffer' wasn't modified
    return 0;
}
```

# **Array of pointers**

### 1. Array of Pointers to Strings

When you declare:

```c
char *veeps[] = {
    "Adams",
    "Jefferson",
    "Burr",
    "Clinton",
    "Gerry"
};
```

* `veeps` is an **array of pointers to char** (`char *`).
* Each element `veeps[i]` is a pointer to the first character of a string literal.
* The strings themselves are stored separately in memory as null-terminated arrays of characters.

### 2. Array Name Decays to Pointer to Pointer

* In expressions, `veeps` *decays* to a pointer to its first element.
* Since each element is a `char *`, the type of `veeps` in expressions is `char **` (pointer to pointer to char).
* So `veeps` points to the first pointer in the array.

### 3. Accessing Elements Using Pointer Arithmetic and Dereferencing

* `veeps + i` is a pointer to the i-th element of the array (`char **`).
* `*(veeps + i)` dereferences this pointer, giving the i-th element itself — a `char *` pointer to a string.
* `veeps[i]` is syntactic sugar for `*(veeps + i)`; both give the same `char *`.

### 4. Printing Strings

For example, to print each string:

```c
for (int i = 0; i < 5; i++) {
    printf("%s\n", *(veeps + i)); // or printf("%s\n", veeps[i]);
}
```

* `%s` expects a `char *` (pointer to a string).
* `*(veeps + i)` provides a `char *`, so it matches perfectly.
* Without dereferencing, `veeps + i` is `char **` (pointer to pointer), which does **not** match `%s`.

### 5. Swapping Strings by Swapping Pointers

```c
char *temp = veeps[1];
veeps[1] = veeps[2];
veeps[2] = temp;
```

* `veeps[1]` and `veeps[2]` are pointers to strings, **not** the strings themselves.
* This code swaps the pointers, meaning `veeps[1]` now points to the string `"Burr"` instead of `"Jefferson"`, and vice versa.
* No characters are copied or moved — only pointer addresses are swapped, which is much faster and more memory-efficient than copying whole strings.

### 6. Accessing Individual Characters Using Double Dereferencing

To get the first character of the i-th string:

```c
char firstChar = *(*(veeps + i));
```

* `veeps + i` is a `char **`, pointing to the i-th pointer.
* `*(veeps + i)` is the i-th pointer itself (`char *`).
* `*(*(veeps + i))` dereferences that pointer to get the first character (`char`).

To access the j-th character of the i-th string:

```c
char ch = *(*(veeps + i) + j);
```

* `*(veeps + i)` points to the start of the i-th string.
* Adding `j` moves to the j-th character.
* Dereferencing gets the character at that position.

### 7. Summary of Pointer Types and Expressions

| Expression            | Type      | Description                                                            |
| --------------------- | --------- | ---------------------------------------------------------------------- |
| `veeps`               | `char **` | Pointer to the first element of the array (pointer to pointer to char) |
| `veeps + i`           | `char **` | Pointer to the i-th element in the array                               |
| `*(veeps + i)`        | `char *`  | The i-th string pointer                                                |
| `veeps[i]`            | `char *`  | Same as `*(veeps + i)` (the i-th string pointer)                       |
| `*(*(veeps + i))`     | `char`    | First character of the i-th string                                     |
| `*(*(veeps + i) + j)` | `char`    | The j-th character of the i-th string                                  |

# Structures and Pointers in C

### Case 1: Structure with a Pointer Member (Structure Variable)

In this case, the structure itself is a regular variable, but one of its members is a pointer. You must allocate memory for the pointer member before using it.

#### Structure Definition

```c
#include <stdio.h>
#include <stdlib.h>

struct person {
    char *name;
    int age;
};
```

#### Full Example Code

```c
int main() {
    struct person someone;

    // Allocate memory for the pointer member
    someone.name = malloc(32 * sizeof(char));
    if (someone.name == NULL) {
        fprintf(stderr, "Memory allocation for name failed\n");
        return 1;
    }

    printf("Enter your name: ");
    fgets(someone.name, 32, stdin);

    printf("Enter your age: ");
    scanf("%d", &someone.age);

    printf("You entered: %sAge: %d\n", someone.name, someone.age);

    // Free the allocated memory
    free(someone.name);

    return 0;
}
```

#### Key Points

* Structure accessed via **dot (`.`)** operator.
* Must allocate memory for the pointer member (`name`).
* Free the pointer member after use.

### Case 2: Pointer to a Structure (Structure Pointer)

Here, the structure itself is accessed via a pointer. All member access uses the **arrow (`->`)** operator. If the structure contains no pointer members, only the structure needs to be allocated.

#### Structure Definition

```c
#include <stdio.h>
#include <stdlib.h>

struct person {
    char *name;
    int age;
};
```

#### Full Example Code

```c
int main() {
    struct person *you;

    // Allocate memory for the structure itself
    you = malloc(sizeof(struct person));
    if (you == NULL) {
        fprintf(stderr, "Memory allocation for struct person failed\n");
        return 1;
    }

    // Set pointer member to NULL (not used in this case)
    you->name = NULL;

    printf("Enter your age: ");
    scanf("%d", &you->age);

    printf("Your age is: %d\n", you->age);

    // Free the structure memory
    free(you);

    return 0;
}
```

#### Key Points

* Structure accessed via **pointer**.
* Use **`->`** operator for member access.
* No pointer members in use here, so only one allocation.

### Case 3: Pointer to a Structure with a Pointer Member (Combined)

This is the most dynamic use: the structure is a pointer, and one of its members is also a pointer. You must allocate memory for **both** the structure and the pointer member.

#### Structure Definition

```c
#include <stdio.h>
#include <stdlib.h>

struct person {
    char *name;
    int age;
};
```

#### Full Example Code

```c
int main() {
    struct person *you;

    // Step 1: Allocate memory for the structure
    you = malloc(sizeof(struct person));
    if (you == NULL) {
        fprintf(stderr, "Memory allocation for struct person failed\n");
        return 1;
    }

    // Step 2: Allocate memory for the pointer member (name)
    you->name = malloc(32 * sizeof(char));
    if (you->name == NULL) {
        fprintf(stderr, "Memory allocation for name failed\n");
        free(you); // Clean up already allocated structure
        return 1;
    }

    // Input and output
    printf("Enter your name: ");
    fgets(you->name, 32, stdin);

    printf("Enter your age: ");
    scanf("%d", &you->age);

    printf("You entered: %sAge: %d\n", you->name, you->age);

    // Free memory in reverse order of allocation
    free(you->name);
    free(you);

    return 0;
}
```

#### Key Points

* Allocate memory for the structure first, then the pointer member.
* Use **`->`** to access all members.
* Always free pointer members first, then the structure pointer.