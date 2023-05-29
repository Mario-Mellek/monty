# Monty Bytecode Interpreter

## The Monty Language

Monty 0.98 is a scripting language that is first compiled into Monty bytecodes. It relies on a unique stack and specific instructions to manipulate it.

Monty bytecodes are stored in files with a .m extension. Each line contains a single instruction with optional spaces before and after the opcode and argument.

### Compilation

The files can be compiled into an executable monty using:
`gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty`

### Usage

Run the command:
`./monty file`
Where file is the path to a file containing Monty bytecodes.

#### The interpreter will run the bytecodes in the file line by line until either:

- The end of the file is reached
- An error occurs

If an invalid instruction is encountered, the interpreter will print an error message in the format<br>
`L<line_number>: unknown instruction <opcode>` and exit.

### Features

This interpreter contains opcodes to:

- Push and pop values to and from the stack
- Print values at the top of the stack (pint, pchar)
- Perform arithmetic operations (add, sub, mul, div, mod)
- Swap the top two stack values (swap)
- And more!

### License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
