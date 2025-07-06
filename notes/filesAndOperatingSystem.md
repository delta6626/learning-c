# Reading files

#### 1. **Opening Files with `fopen()`**

To work with files in C, the standard I/O library (`<stdio.h>`) provides functions to open, manipulate, and close files. The fundamental function for opening a file is `fopen()`.

* **Prototype**: `FILE *fopen(const char *filename, const char *mode);`

* **Arguments**:

  * `filename`: Name of the file, passed as a string.
  * `mode`: A string specifying the access mode. Two common modes are:

    * `"r"` – Open for reading. The file must exist.
    * `"w"` – Open for writing. Creates the file or overwrites it if it exists.
    * `"a"` - Open for appending. Appends data to a file. Creates the file if it doesn't exist.

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