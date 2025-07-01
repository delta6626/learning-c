
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