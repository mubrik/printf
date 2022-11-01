# Recreating the famous printf C function

## Compile and usage

- Clone this repository and run `cd printf`
- Compile by running: `gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c -o run`
- Compile for tests by running: `gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c ./test/*.c -o runtest`
- compile for specific test e.g chars: `gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c ./test/test_char.c -o runtest`
- Run tests: `./runtest`
- verify memory leaks: install vagrind and run: `valgrind ./runtest`

## Changes and Contributions

- Test changes by editing the test.c file to your needs
- Makee sure to add `runtest` to your gitignorefile

## Todo

- Implement function to count format specification arguments required and type
- Implement Error handling when no arguments
- commenting
