## Insert Node into a Sorted Singly Linked List

This project involves implementing a function in C that inserts a number into a sorted singly linked list while maintaining the sorted order. Below, you'll find the project requirements, implementation details, and how to test the code.

## Requirements

# General

- Allowed editors: vi, vim, emacs

- OS: Ubuntu 14.04 LTS

- Compiler: gcc 4.8.4 with the flags -Wall -Werror -Wextra -pedantic

- Coding style: Betty (checked using betty-style.pl and betty-doc.pl)

- Restrictions:

- No global variables

- No more than 5 functions per file

- All files should end with a new line.

- All prototypes must be included in a header file named lists.h.

- Header files must be include-guarded.

## Project Files

- lists.h: Contains the definition of the singly linked list structure and prototypes.

- linked_lists.c: Contains utility functions for working with linked lists.

- 0-insert_number.c: Contains the insert_node function implementation.

- 0-main.c: Test file for the insert_node function.

## File Descriptions

## lists.h

This header file contains the structure definition and function prototypes:

```c
#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/\*\*

- struct listint_s - singly linked list
- @n: integer
- @next: points to the next node
-
- Description: singly linked list node structure
  */
  typedef struct listint_s
  {
  int n;
  struct listint_s *next;
  } listint_t;

size_t print_listint(const listint_t *h);
listint_t *add_nodeint_end(listint_t **head, const int n);
void free_listint(listint_t *head);
listint_t *insert_node(listint_t **head, int number);

#endif /_ LISTS_H _/
```

## linked_lists.c

Contains helper functions to manipulate linked lists, such as printing, adding nodes, and freeing the list.

## 0-insert_number.c

This file contains the insert_node function:

```c
listint_t *insert_node(listint_t \*\*head, int number)
{
listint_t *new_node, *current, *prev;

    if (!head)
        return (NULL);

    new_node = malloc(sizeof(listint_t));
    if (!new_node)
        return (NULL);
    new_node->n = number;
    new_node->next = NULL;

    if (!(*head) || (*head)->n >= number)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    current = *head;
    while (current && current->n < number)
    {
        prev = current;
        current = current->next;
    }

    new_node->next = current;
    prev->next = new_node;

    return (new_node);

}
```

## 0-main.c

A test file that verifies the insert_node function:

```c
#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

int main(void)
{
listint_t \*head = NULL;

    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    print_listint(head);

    printf("-----------------

");

    insert_node(&head, 27);

    print_listint(head);
    free_listint(head);

    return (0);

}
```

## How to Run

- 1.Compile the files:

```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-insert_number.c -o insert
```

- 2.Run the program:

```bash
./insert
```

- 3.Expected Output:

```bash
0
1
2
3
4
98
402
1024

---

0
1
2
3
4
27
98
402
1024
```

## How to Check Coding Style

- 1.Install Betty:

```bash
git clone https://github.com/holbertonschool/Betty.git
cd Betty
sudo ./install.sh
```

- 2.Run Betty:

```bash
betty 0-insert_number.c
```
