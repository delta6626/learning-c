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