# Reading files

#### 1. **Opening Files with `fopen()`**

To work with files in C, the standard I/O library (`<stdio.h>`) provides functions to open, manipulate, and close files. The fundamental function for opening a file is `fopen()`.

* **Prototype**: `FILE *fopen(const char *filename, const char *mode);`

* **Arguments**:

  * `filename`: Name of the file, passed as a string.
  * `mode`: A string specifying the access mode. Two common modes are:

    * `"r"`   – Open for **reading**. The file must exist.
    * `"w"`   – Open for **writing**. Creates the file or overwrites it if it exists.
    * `"a"`   – Open for **appending**. Appends data to a file. Creates the file if it doesn't exist.
    * `"r+"`  – Open for **reading and writing**, must already exist.
    * `"w+"`  – Create for **reading and writing**, truncates if it exists.
    * `"a+"`  – Open for **reading and appending**, creates if it doesn't exist.
    * `"wx"`  – Create for **writing**, fail if file exists.
    * `"w+x"` – Create for **reading and writing**, fail if file exists.


"w+": Create for reading and writing, truncates if it exists.

"a+": Open for reading and appending, creates if it doesn't exist.

"wx": Non-standard in C (but POSIX extension): Create for writing, fail if file exists.

"w+x": Also non-standard/POSIX — open for reading and writing, fail if file exists.

* **Return Value**: Returns a file pointer (handle) if successful. Returns `NULL` if the file cannot be opened.

Example:

```c
FILE *fh = fopen("sonnet18.txt", "r");
if (fh == NULL) {
    printf("Failed to open file.\n");
    exit(1);
}
```

#### 2. **File Pointer and Error Checking**

Once `fopen` is called, its return value must be checked. If it returns `NULL`, the file failed to open. The file handle (`fh`) points to an internal structure used by the standard library to manage file operations.

Always validate the pointer to avoid undefined behavior:

```c
if (fh == NULL) {
    // Handle the error
}
```

#### 3. **Reading a File Character-by-Character with `fgetc()`**

Once the file is opened successfully in read mode (`"r"`), a common method to read its contents is using a loop with `fgetc()`. Since the file’s length may not be known in advance, an infinite loop is typically used, which breaks upon reaching the end of file.

Use an `int` variable to store each character returned by `fgetc()`. This is important because `fgetc()` returns `EOF` (a negative integer) when no more characters are left to read.

Example:

```c
int ch;
while (1) {
    ch = fgetc(fh);
    if (ch == EOF) break;
    putchar(ch); // Display the character read
}
```

#### 4. **Writing to Files**

C provides functions to write data to a file once it is opened in write mode (`"w"` or similar). These include:

* `fprintf(FILE *stream, const char *format, ...)`
* `fputc(int char, FILE *stream)`
* `fputs(const char *str, FILE *stream)`

Each of these functions sends output to the file instead of the console. The file handle is required in every call.

#### 5. **Closing Files**

After completing operations on a file, use `fclose()` to release the associated resources and flush any buffers.

* **Prototype**: `int fclose(FILE *stream);`

Example:

```c
fclose(fh);
```

Closing a file is necessary to prevent memory leaks and to ensure data integrity, especially in write mode.

# **Reading and Writing Binary Data in C using `fread` and `fwrite`**

### **1. Standard File I/O vs. Binary I/O**

* Standard CIO (`fprintf`, `fscanf`, etc.) functions deal with **text-based data**.
* For **raw (binary) data**, use:

  * `fwrite()` for writing binary data.
  * `fread()` for reading binary data.

### **2. File Handling Basics**

* File opening and closing operations are **the same** for both text and binary I/O.

  * Use `fopen()` to open a file.

    * `"wb"` mode for writing binary files.
    * `"rb"` mode for reading binary files.
  * Use `fclose()` to close the file.

### **3. Writing Data Using `fwrite()`**

#### **Function Signature:**

```c
size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);

/*
Note: Because void * is a generic pointer type in C, it allows the function to accept a pointer to any data type, such as int *, char *, float *, etc.
*/
```

#### **Parameters:**

1. `ptr` – Pointer to the data you want to write (e.g., `&A` or `A` for arrays).
2. `size` – Size of each data element (e.g., `sizeof(int)`).
3. `count` – Number of elements to write.
4. `stream` – File pointer returned by `fopen()`.

#### **Example (Writing 10 integers):**

```c
FILE *file = fopen("integers.dat", "wb");
int A;
for (int i = 0; i < 10; i++) {
    A = 10 + (i * 5); // Values: 10, 15, ..., 55
    fwrite(&A, sizeof(int), 1, file);
}
fclose(file);
```

#### **Explanation:**

* The file `integers.dat` is created with 10 binary integers.
* Each integer occupies **4 bytes**.
* The loop writes one integer at a time.

### **4. Viewing Binary Data**

* Binary files do **not** store human-readable numbers.
* Use a hex viewer or terminal tools (like `hexdump -C integers.dat` or `xxd`) to inspect raw binary contents.
* Example:

  * `0A` for 10
  * `37` for 55

### **5. Reading Data Using `fread()`**

#### **Function Signature:**

```c
size_t fread(void *ptr, size_t size, size_t count, FILE *stream);
```

#### **Parameters:**

1. `ptr` – Pointer to the memory where the read data will be stored.
2. `size` – Size of each data chunk to read (e.g., `sizeof(int)`).
3. `count` – Number of chunks to read.
4. `stream` – File pointer to the open file.

### **Example 1: Reading One Integer at a Time**

```c
FILE *file = fopen("integers.dat", "rb");
int A;
for (int i = 0; i < 10; i++) {
    fread(&A, sizeof(int), 1, file);
    printf("%d\n", A);
}
fclose(file);
```

#### **Explanation:**

* Each `fread` call reads one integer into variable `A`.
* The values are printed immediately after being read.

### **Example 2: Reading an Array of Integers at Once**

```c
FILE *file = fopen("integers.dat", "rb");
int A[10];
fread(A, sizeof(int), 10, file);  // Read all at once
for (int i = 0; i < 10; i++) {
    printf("%d\n", A[i]);
}
fclose(file);
```

#### **Changes from Previous Example:**

* Variable `A` is now an **array of 10 integers**.
* `fread` is **moved outside the loop** to read all data in one operation.
* The loop only prints the elements using **array notation** (`A[i]`).
* No need for the address-of (`&`) operator with arrays (since the array name already points to the first element).

### **6. Advantages of `fwrite` and `fread`**

* Efficient for **reading/writing large chunks of data**.
* Faster than line-by-line or value-by-value processing.
* Ideal when:

  * Data is **homogeneous** (same type throughout).
  * You **know the structure** and size of the data in advance.

### **7. Limitations**

* Binary files are **not portable** between systems with different endianness or word sizes.
* You **must know** the exact layout of the data in the file.
* Cannot be edited manually or viewed as plain text.

# **File Position Indicator**

* When a file is opened for reading or writing, the **operating system** uses a **file position indicator**.
* This indicator keeps track of where data is **read from** or **written to** within the file.

### **2. Types of File Access**

#### **A. Sequential File Access**

* Data is read or written **one byte after another**, from **start to end**.
* The file position indicator **automatically advances** as the file is read or written.
* Reading continues until:

  * The **end-of-file (EOF)** is reached, or
  * The `feof()` function returns `true`.

#### **B. Random File Access**

* The file position indicator can be **manually set** to any location in the file.
* Allows **non-sequential** access to data.
* Best suited for files containing **uniform data**, such as:

  * Arrays of integers
  * Structures
  * Other consistently sized data types

### **3. The `fseek` Function**

#### **Prototype:**

```c
int fseek(FILE *stream, long int offset, int whence);
```

#### **Arguments:**

1. **`FILE *stream`**: The file handle (pointer to the file).
2. **`long int offset`**: The number of bytes to move the file position indicator.
3. **`int whence`**: The reference point from which the offset is measured.

#### **Values for `whence`:**

* `SEEK_SET`: Offset is from the **start of the file**.
* `SEEK_CUR`: Offset is from the **current position**.
* `SEEK_END`: Offset is from the **end of the file**.

#### **Return Value:**

* Returns `0` on **success**.
* Returns `-1` on **failure**.

### **4. Practical Example: Accessing Records in a Data File**

#### **Creating the File**

* A structure array called `presidents[]` is declared and initialized.
* `fwrite()` is used to write all structures to a binary file `presidents.dat`.
* The file is then closed.
* This program has **no standard output** and is used to prepare data for the next step.

#### **Reading a Specific Record**

* The file `presidents.dat` is opened for reading.
* The user is prompted to **enter a record number** to read.
* Input validation ensures the value is within a valid range (e.g., 1–10).
* The value is decremented (e.g., `x--`) to match **zero-based indexing**.

#### **Using `fseek` to Locate the Record**

* `fseek()` is used to **move the file position indicator** to the desired structure in the file:

  ```c
  fseek(fp, x * sizeof(struct person), SEEK_SET);
  ```
* This moves the indicator to the location of the `x`-th structure (record).
* The size of the structure is used to calculate the correct offset.
* The offset is measured from the **start of the file**.

#### **Example Output**

* If the user selects record 4, the structure at that position is read.
* The output should correctly show **James Madison**, demonstrating proper random access.

### **5. Key Concepts to Remember**

* `fseek` enables **random file access**, crucial for reading/writing specific portions of structured data files.
* Uniform data (equal-sized records) is essential for `fseek` to work correctly.
* The second argument in `fseek` must be carefully calculated using `sizeof()` to ensure correct positioning.
* Always validate user input when accessing specific records to avoid file errors or corruption.