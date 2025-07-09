# **Running External Programs**

In some situations, a program might need to run another external program—for example, to execute a system command or use an existing utility instead of rewriting its functionality. C provides mechanisms to facilitate this through the `system()` and `popen()` functions.

## **1. The `system()` Function**

### **Purpose:**

* Used to execute an external system command.
* Control is temporarily passed to the operating system to run the command.
* Once the command is executed, control returns to the program.

### **Header File:**

```c
#include <stdlib.h>
```

### **Syntax:**

```c
int system(const char *command);
```

### **Usage Example:**

```c
system("clear"); // Clears the terminal screen (on Unix-like systems)
```

### **Behavior:**

* The command is passed as a string to the operating system.
* The program does **not** receive or interact with the output of the command.
* The return value typically indicates the command’s exit status.

### **Limitations:**

* No access to the output of the executed command.
* Security risks if untrusted input is passed into `system()`.

## **2. The `popen()` Function**

### **Purpose:**

* Opens a process by creating a pipe, for either reading from or writing to the process.
* Allows the program to **capture the output** of an external command.

### **Header File:**

```c
#include <stdio.h>
```

### **Syntax:**

```c
FILE *popen(const char *command, const char *mode);
```

* `command`: the shell command to execute.
* `mode`: `"r"` for reading output from the process, `"w"` for writing input to it.

### **Usage Example:**

```c
FILE *p;
p = popen("uname", "r");
```

* This opens a process that executes the `uname` command and allows the program to read its output.

### **Reading Output from the Process:**

```c
int c;
while ((c = fgetc(p)) != EOF) {
    putchar(c);
}
```

* Reads each character from the output stream of the command and prints it to the standard output.

### **Closing the Process:**

```c
pclose(p);
```

* Terminates the process and closes the associated pipe.
* Analogous to `fclose()` for files.

## **Key Differences: `system()` vs `popen()`**

| Feature         | `system()`                       | `popen()`                             |
| --------------- | -------------------------------- | ------------------------------------- |
| Returns output? | No                               | Yes                                   |
| Interactivity   | Not suitable for interactive I/O | Not suitable for interactive I/O      |
| Complexity      | Simple to use                    | Slightly more complex, file-like API  |
| Control         | One-way execution                | Two-way (read/write) with the process |

## **Common Use Cases**

* **`system()`**

  * Simple tasks like clearing the screen, listing files, or restarting a service.
* **`popen()`**

  * Capturing output from utilities (e.g., system info, network status).
  * Analyzing or processing command output within a C program.
  * Creating custom wrappers for shell utilities.