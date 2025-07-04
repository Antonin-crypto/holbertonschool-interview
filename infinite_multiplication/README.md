## Infinite Multiplication

## Requirements

## General

- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 14.04 LTS
- Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- You are not allowed to use global variables
- No more than 5 functions per file
- The only C standard library functions allowed are malloc, free and exit. Any use of functions like printf, puts, calloc, realloc etc… is forbidden
- You are allowed to use \_putchar
- You don’t have to push \_putchar.c, we will use our file. If you do it won’t be taken into account
- In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
- The prototypes of all your functions and the prototype of the function \_putchar should be included in your header file called holberton.h
- Don’t forget to push your header file

## Tasks

### 0. Infinite Multiplication

Write a program that multiplies two positive numbers:

- Usage: mul num1 num2
- num1 and num2 will be passed in base 10
- Print the result, followed by a new line
- If the number of arguments is incorrect, print Error, followed by a new line, and exit with a status of 98
- num1 and num2 should only be composed of digits. If not, print Error, followed by a new line, and exit with a status of 98
- You are allowed to use more than 5 functions in your file
  You can use bc (man bc) to check your results.

## Compilation

```bash
gcc -Wall -pedantic -Werror -Wextra 0-mul.c _putchar.c -o mul
./mul 10 98
```

## Result

```bash
980
```
