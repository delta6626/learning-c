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

# **File Manipulation**

The C Standard Library provides a limited set of file manipulation functions. While it includes essential operations like reading and writing files, it lacks built-in functions for tasks such as copying a file. However, C programmers can handle such limitations by writing their own utilities using low-level file operations.

#### **1. Renaming a File**

**Function:** `rename()`

* **Header File:** `<stdio.h>`
* **Prototype:** `int rename(const char *oldname, const char *newname);`
* **Description:** Renames a file from `oldname` to `newname`.
* **Return Value:**

  * `0` on success
  * Non-zero on failure (e.g., if the original file doesn’t exist or the new name is invalid)

**Usage Example:**

```c
rename("alpha.txt", "a.txt");
```

* In this example, the file `alpha.txt` is renamed to `a.txt`.
* Both filenames can include full paths (e.g., `"./folder/alpha.txt"`).

#### **2. Deleting a File**

**Function:** `unlink()`

* **Header File:** `<unistd.h>`
* **Prototype:** `int unlink(const char *pathname);`
* **Description:** Deletes the file specified by `pathname`.
* **Return Value:**

  * `0` on success
  * `-1` on failure (e.g., file not found, permission denied)

**Usage Example:**

```c
unlink("deleteme.txt");
```

* This deletes the file `deleteme.txt` from the current working directory.
* Works with full path names as well.

#### **3. Copying a File (Manual Implementation)**

The C Standard Library **does not include a file copy function**, so programmers implement their own.

**Approach:**

1. Open the source file in read mode.
2. Open/create the destination file in write mode.
3. Read the source file byte-by-byte and write each byte to the destination file.
4. Close both files.

**Function Signature:**

```c
int copyFile(const char *source, const char *destination);
```

**Core Logic:**

```c
int copyFile(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    FILE *dest = fopen(destination, "wb");

    if (src == NULL || dest == NULL) {
        return -1;  // Error handling
    }

    int ch;
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    fclose(src);
    fclose(dest);
    return 0;
}
```

* **"rb"** and **"wb"**: These modes are used to ensure binary-safe reading and writing.
* The `while` loop copies each byte until EOF is reached.
* `fgetc()` reads a single byte; `fputc()` writes a single byte.
* Returns `0` on success and `-1` if an error occurred.

### **4. Return Value Conventions**

All these functions return `0` on success, and a **non-zero (usually -1)** value on failure. This convention is consistent with other system-level file operations in C.

### **5. Summary Table**

| Operation   | Function   | Header       | Description                         | Success Return |
| ----------- | ---------- | ------------ | ----------------------------------- | -------------- |
| Rename file | `rename()` | `<stdio.h>`  | Renames a file                      | `0`            |
| Delete file | `unlink()` | `<unistd.h>` | Deletes a file                      | `0`            |
| Copy file   | *custom*   | `<stdio.h>`  | Copies contents from one to another | `0` (custom)   |

### **6. Best Practices**

* Always check if file pointers returned by `fopen()` are `NULL`.
* Prefer `"rb"` and `"wb"` modes for copying to handle all file types.
* Handle errors gracefully and report failures to the user.
* Close all opened files to avoid memory leaks or file corruption.


# **Working with Directories**

#### **1. Accessing Files**

* A program can access a file if it knows the **filename**, provided the file is in the **same directory** from which the program is running.
* To work with files in **other directories**, the program must:

  * Use a **full path** (absolute path),
  * Use a **relative path**, or
  * **Change the current working directory** using a system function.

#### **2. Current Working Directory (CWD)**

##### **Function: `getcwd`**

* Retrieves the **current working directory** of the running program.
* **Prototype:** `char *getcwd(char *buf, size_t size);`
* **Header File:** `unistd.h`
* **Arguments:**

  * `buf`: A character array (buffer) to store the directory path.
  * `size`: The size of the buffer.
* **Returns:**

  * Pointer to the buffer (`buf`) on success.
  * `NULL` on failure.
* This function helps verify or log the directory context in which the program is executing.

##### **Usage Example:**

```c
#include <unistd.h>
#include <stdio.h>

int main() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current directory: %s\n", cwd);
    } else {
        perror("getcwd() error");
    }
    return 0;
}
```

#### **3. Changing Directories**

##### **Function: `chdir`**

* Changes the **current working directory** of the running program.
* **Prototype:** `int chdir(const char *path);`
* **Header File:** `unistd.h`
* **Argument:**

  * `path`: A string representing the target directory path.

    * Can be relative (e.g., `".."` for parent) or absolute (e.g., `"/home/user/docs"`).
* **Returns:**

  * `0` on success.
  * `-1` on failure.

##### **Common Usage:**

* `".."` (dot dot) is a shortcut for the **parent directory**.
* Useful for temporarily moving around the filesystem during program execution.

##### **Usage Example:**

```c
#include <unistd.h>
#include <stdio.h>

int main() {
    if (chdir("..") == 0) {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("Changed to parent directory: %s\n", cwd);
        }
    } else {
        perror("chdir() error");
    }
    return 0;
}
```

#### **4. Important Notes**

* The **change of directory using `chdir` is only effective during the program’s execution**.
* Once the program terminates, the **original working directory** (from which the program was started) is **restored** by the operating system.
* This behavior makes `chdir` useful for temporarily accessing files or executing operations in different directory contexts.