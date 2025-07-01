
# **Basic Character Input and Output in C**

* The C language supports simple input and output using characters.
* Input typically comes from the **standard input device** (usually the keyboard).
* Output is sent to the **standard output device** (usually the terminal or display).

**2. Using `putchar` for Output**

* The `putchar` function sends a single character to standard output.
* Multiple calls to `putchar` can be used to display a series of characters one after another.
* A newline character (`'\n'`) is often added using `putchar` to improve readability by moving the cursor to the next line.

**3. Using `getchar` for Input**

* The `getchar` function reads one character from standard input.
* It requires no arguments and returns an **integer value**, not a character.
* Because it returns an `int`, the variable used to store its result must be of type `int` rather than `char`.

Example:

```c
int ch;
ch = getchar();
```

* A character read using `getchar` can be displayed using `printf`, e.g.:

```c
printf("%c", ch);
```

**4. Stream Input Behavior**

* C uses **stream-based input**, meaning characters are stored in a buffer and then read by the program.
* Input is not read character-by-character in real time (non-interactive).
* When you type a character and press Enter, multiple characters are added to the input stream: the typed character and the newline (`'\n'`).

Example behavior:

* Typing `A` followed by Enter results in the input stream containing `'A'` and `'\n'`.
* If the program reads two characters, the second character will be `'\n'`.

**5. Reading Multiple Characters**

* To read multiple characters, you declare additional integer variables and call `getchar` multiple times.

Example:

```c
int ch1, ch2;
ch1 = getchar();
ch2 = getchar();
```

* Input like `A B` followed by Enter will be read as:

  * `ch1 = 'A'`
  * `ch2 = ' '` (space character)
  * Remaining characters, including `B` and `\n`, remain in the input stream.

**6. Why `getchar` Returns an Integer**

* `getchar` must return an `int` to properly handle **EOF (End Of File)**.
* `EOF` is a special integer constant, typically defined as `-1`.
* A `char` variable cannot represent all possible character values plus `EOF`.
* Using an `int` ensures that the program can detect and respond to `EOF` correctly.

**7. The Typewriter Program Example**

* A basic "typewriter" program reads characters using `getchar` and outputs them using `putchar`, effectively echoing input back to the screen.

Example structure:

```c
int ch;
while ((ch = getchar()) != EOF) {
    putchar(ch);
}
```

* This loop continues until `EOF` is encountered.

**8. Supplying `EOF` from the Keyboard**

* To end the input stream and trigger `EOF`:

  * On **Unix/Linux/macOS**, press **Control-D**.
  * On **Windows**, press **Control-Z** and then Enter.
* Until `EOF` is detected, input is buffered and then echoed back.

**9. Summary of Key Points**

* Use `int` for variables receiving input from `getchar`.
* Understand that input is buffered and includes characters like Enter (`'\n'`).
* Use `EOF` to control the end of input loops.
* `getchar` and `putchar` are simple, low-level tools ideal for learning about character-based input and output in C.

# Testing and converting characters

* Character Testing Functions: Functions like isalpha, isdigit, isupper, and islower are used to test characters for being alphabetic, numeric, uppercase, or lowercase, respectively.

* Character Conversion Functions: Functions such as tolower and toupper convert characters to their lowercase or uppercase counterparts.

* The ctype.h header file contains these functions, and must be included to use them.

```c
#include <stdio.h>
#include <ctype.h>

int main(){
  char text[] = "Hello\n";
  for(int x = 0; text[x] != '\n'; x++){
    if(islower(text[x])){
      printf("The letter at position %d is %c and is a lowercase letter",x,text[x]);
    }
  }
  return 0;
}
```

# **Strings in C**

### **1. C Does Not Have a Built-In String Data Type**

* Unlike languages like Python or Java, C does **not have a dedicated string type**.
* Instead, a **string is represented using an array of characters**.
* The **last character** in a string **must** be the **null character** (`'\0'`), which acts as a **string terminator**.

### **2. The Null Character (`'\0'`)**

* The null character is **ASCII code 0**.
* It is represented as `'\0'` in code.
* It is **not counted** in the visible length of the string but **must be stored**.
* It's **different from the `NULL` pointer constant**.

```c
char name[] = "Alice"; // Stored as {'A', 'l', 'i', 'c', 'e', '\0'}
```

### **3. Declaring Strings**

#### **Using String Literals**

```c
char name[] = "John";
```

* The compiler automatically appends the null terminator (`'\0'`).
* This string is stored as: `{ 'J', 'o', 'h', 'n', '\0' }`

#### **Using Character Arrays Manually**

```c
char city[] = { 'P', 'a', 'r', 'i', 's', '\0' };
```

* You must **explicitly add** the `'\0'` character.

#### **Specifying Size for Buffers**

```c
char buffer[32]; // Can hold 31 characters + 1 null terminator
```

* Always allocate space for the null character.
* A string of 31 characters will still need one more space for `'\0'`.

### **4. Common Pitfall: Missing the Null Terminator**

```c
char wrong[] = { 'H', 'e', 'l', 'l', 'o' }; // No null terminator
```

* This is just a **character array**, not a string.
* Using string functions with it can cause **undefined behavior**.

### **5. Buffer Overflows**

* C does **not automatically protect** against writing past the end of arrays.
* Writing more characters than the array can hold causes a **buffer overflow**.
* You must ensure enough space and validate inputs.

```c
char name[5];
strcpy(name, "Robert"); // Overflow: "Robert" + '\0' is 7 chars
```

* Use safer functions like `strncpy`.

## **String Handling Functions in `string.h`**

C provides a set of standard string functions declared in the `string.h` header.

### **Common String Functions**

| Function  | Description                          | Example                 |
| --------- | ------------------------------------ | ----------------------- |
| `strlen`  | Returns the length of a string       | `strlen("Hello") // 5`  |
| `strcpy`  | Copies one string to another         | `strcpy(dest, src)`     |
| `strncpy` | Safer version of `strcpy`            | `strncpy(dest, src, n)` |
| `strcat`  | Appends one string to another        | `strcat(dest, src)`     |
| `strcmp`  | Compares two strings                 | `strcmp(str1, str2)`    |
| `strchr`  | Searches for a character in a string | `strchr(str, 'a')`      |
| `strstr`  | Searches for a substring             | `strstr(str, "word")`   |

### **Example: Using `strlen` and `strcpy`**

```c
#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "OpenAI";
    char destination[10];

    printf("Length: %lu\n", strlen(source)); // Output: 6

    strcpy(destination, source);
    printf("Copied String: %s\n", destination);

    return 0;
}
```

## **String Concatenation (No `+` Operator)**

* C does **not support `+` or `+=` operators** for strings.
* Use `strcat` or `strncat`.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char greeting[20] = "Hello, ";
    char name[] = "Bob";

    strcat(greeting, name); // greeting becomes "Hello, Bob"
    printf("%s\n", greeting);

    return 0;
}
```

## **Custom String Functions**

If the standard library lacks a needed function, you can write your own.

### **Example: Custom `strlen` Implementation**

```c
int custom_strlen(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
```

## **Best Practices**

* Always allocate one extra byte for the null terminator.
* Avoid buffer overflows by validating input lengths.
* Remember: In C, managing memory and boundaries is **your responsibility**.

# **Reading Strings from Standard Input in C**

### **1. Using `scanf` to Read a String**

```c
#include <stdio.h>

int main() {
    char input[10]; // Room for 9 characters + null terminator

    printf("Enter your name: ");
    scanf("%s", input); // Reads string from standard input

    printf("You entered: %s\n", input);
    return 0;
}
```

### **Key Points:**

* `%s` tells `scanf` to read a string until a **whitespace character** (space, tab, newline).
* No `&` is needed with the array name `input` because arrays decay to pointers.
* Only the first word is read if input includes spaces:

#### **Example:**

Input: `Jim Bob`
Output: `Jim`

* `scanf` stops at the **first whitespace**.

## **2. Problem: Buffer Overflow with `scanf`**

If the input is **longer than the buffer size**, you get a **buffer overflow**:

```c
char input[10]; // Max 9 characters + '\0'
scanf("%s", input); // No safeguard on input size
```

#### **Example:**

Input: `Bartholomew` (11 characters)

* `input` only holds 10 bytes → **overflow occurs**
* This is **dangerous** and **insecure**

## **3. Safer Input with `fgets`**

`fgets` is a **safer alternative** to `scanf` for reading strings.

### **Syntax:**

```c
fgets(buffer, buffer_size, stdin);
```

* Reads a line of input (including spaces) from `stdin`
* Stops after reading `buffer_size - 1` characters or when a newline is found
* Appends a **null terminator `'\0'`**
* **Includes the newline character** if it fits

### **Example:**

```c
#include <stdio.h>

int main() {
    char input[10]; // Room for 9 chars + null

    printf("Enter your name: ");
    fgets(input, 10, stdin); // Safer than scanf

    printf("You entered: %s", input); // Might include '\n'
    return 0;
}
```

#### **Input:** `Bartholomew`

#### **Output:** `Barthol` (input truncated to prevent overflow)

## **4. Removing the Newline Character from `fgets` Input**

`fgets` may store the **newline (`\n`) character**. You can remove it manually:

### **Code to Remove Newline:**

```c
for (int i = 0; i < 10; i++) {
    if (input[i] == '\n') {
        input[i] = '\0';
        break;
    }
}
```

### **Full Example:**

```c
#include <stdio.h>

int main() {
    char input[10]; // Buffer for 9 chars + '\0'

    printf("Enter your name: ");
    fgets(input, 10, stdin); // Safe input

    // Remove newline if present
    for (int i = 0; i < 10; i++) {
        if (input[i] == '\n') {
            input[i] = '\0';
            break;
        }
    }

    printf("You entered: %s\n", input);
    return 0;
}
```

## **Comparison: `scanf` vs `fgets`**

| Feature              | `scanf("%s", ...)` | `fgets(...)`                   |
| -------------------- | ------------------ | ------------------------------ |
| Reads spaces         | No                 | Yes                            |
| Buffer overflow risk | High               | Low (buffer size respected)    |
| Newline included     | No                 | Yes (must be manually removed) |
| Recommended?         | ❌ No (for strings) | ✅ Yes                          |

## **Best Practices for String Input in C**

* Always **allocate enough space**, including for the null terminator.
* Use `fgets` for reading strings to avoid buffer overflows.
* Always **sanitize input** by removing newline characters from the buffer.
* Avoid `scanf` for reading general strings, especially from untrusted input sources.