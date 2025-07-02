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