# C - Stacks, Queues - LIFO, FIFO

## Stacks
A stack is a data structure that follows the Last In, First Out (LIFO) principle.
Elements are added or removed from the top of the stack.

## Queues
A queue is a data structure that follows the First In, First Out (FIFO) principle.
Elements are added at the rear and removed from the front of the queue.

## Requirements
+ Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=c89

## Data Structures
This project uses some data structures for its implementation and they can found in the [header file](  )

## Compilation and Output
This code is compiled this way:
`$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty`
+ All output are printed to printed on `stdout`
- All error messages are printed on `stderr`

# The Monty Language
Monty 0.98 is a scripting language that is first compiled into Monty bytes codes(Just like Python). It relies on a unique stack, with specific instruction to manipulate it. The goal of this project is to creat an interpreter for Monty ByteCodes files.
