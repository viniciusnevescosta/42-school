*This project has been created as part of the 42 curriculum by vneves-c.*

# ft_printf

## Description

`ft_printf` is a static C library (`libftprintf.a`) that reimplements a subset of the
standard `printf()` function from the C library, without any of its buffer management.

The goal of the project is to learn how **variadic functions** work in C: how a function
can accept an arbitrary number of arguments, how those arguments are read from the stack
through the `<stdarg.h>` macros, and why the compiler cannot type-check them for you.

The function prototype is:

```c
int	ft_printf(const char *format, ...);
```

It parses a format string, prints it to the standard output, replacing every conversion
specifier with the corresponding argument, and returns the total number of characters
written.

### Supported conversions

| Specifier | Output |
|---|---|
| `%c` | a single character |
| `%s` | a string (`(null)` if the pointer is `NULL`) |
| `%p` | a `void *` pointer in hexadecimal, prefixed with `0x` (`(nil)` if `NULL`) |
| `%d` | a signed decimal (base 10) integer |
| `%i` | a signed decimal (base 10) integer |
| `%u` | an unsigned decimal (base 10) integer |
| `%x` | an unsigned integer in lowercase hexadecimal (base 16) |
| `%X` | an unsigned integer in uppercase hexadecimal (base 16) |
| `%%` | a literal percent sign |

Flags, field width and precision are **not** implemented (mandatory part only).

## Instructions

### Build

```bash
make        # builds libftprintf.a at the root of the repository
make clean  # removes the object files
make fclean # removes the object files and the library
make re     # fclean + all
```

The library is compiled with `cc -Wall -Wextra -Werror` and archived with `ar rcs`.
`make` does not relink when nothing has changed.

### Use it in your own program

Include the header, then link against the archive:

```c
#include "ft_printf.h"
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o my_program
./my_program
```

### Test program

Save the following file as `main.c` at the root of the repository. It prints the output
of `ft_printf` and of the real `printf` side by side, together with both return values,
so any difference is immediately visible.

```c
#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int		ft_ret;
	int		std_ret;
	char	*str = "42 Sao Paulo";

	ft_ret = ft_printf("ft : %s | int: %d | hex: %x | ptr: %p\n", str, 42, 255, str);
	std_ret = printf("std: %s | int: %d | hex: %x | ptr: %p\n", str, 42, 255, str);

	printf("\n-> ft_printf retornou: %d\n", ft_ret);
	printf("-> printf retornou   : %d\n", std_ret);

	return (0);
}
```

Compile and run it:

```bash
make && cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test && ./test
```

Every block must print two identical lines (apart from the `ft :` / `std:` prefix) and
report `[OK]` for the return values.

> Note on the `%s`-with-`NULL` and `%p`-with-`NULL` blocks: the C standard leaves both
> cases undefined, so the reference output depends on the libc. This implementation
> prints `(null)` and `(nil)`, which matches glibc; on macOS the system `printf` prints
> `0x0` for a null pointer, so that single block may legitimately differ.

## Algorithm and data structures

### Overall algorithm

`ft_printf` is a single linear pass over the format string — **O(n)** in its length, with
no dynamic allocation at all.

1. `va_start` initialises the `va_list` on the argument that follows `format`.
2. The string is walked one character at a time with an index `i`.
3. If the current character is **not** a `%`, it is written directly to `fd 1`.
4. If it **is** a `%` and it is not the last character of the string, the following
   character is handed to `ft_check_symbol`, which consumes the matching argument and
   dispatches to the right printing function. The index then jumps two positions, past
   both the `%` and the specifier.
5. A `%` sitting at the very end of the format string has no specifier to consume, so it
   is treated as an ordinary character. This guards against reading past the terminating
   `'\0'`.
6. Every printing function returns how many characters it wrote; those values accumulate
   into `count`, which is returned after `va_end`.

### Data structures

The project deliberately uses **no data structure beyond `va_list` and the format string
itself**. There is no buffer, no struct, no allocation.

* **`va_list`** is the only state carried across the parsing loop. It is passed to
  `ft_check_symbol` **by address** (`va_list *`) rather than by value. This matters: on
  some ABIs `va_list` is an array type, and copying it into a callee then advancing it
  there would leave the caller's copy unchanged or in an undefined state. Passing the
  pointer guarantees that every `va_arg` advances the one and only cursor.
* **A plain `int` counter** accumulates the return value. Since the subject forbids
  reimplementing `printf`'s buffering, characters go straight to `write`, so nothing else
  needs to be stored.

### Why this design

* **Dispatch table vs. if/else chain.** With only nine specifiers, a chain of comparisons
  in `ft_check_symbol` is shorter, easier to read, and — because there is no indirect
  call — at least as fast as an array of function pointers. Each conversion still lives
  in its own file behind its own function, so adding a specifier means adding one file
  and one `else if`.

* **Recursion for number conversion.** `ft_print_decimal`, `ft_print_unsigned` and
  `ft_print_hexa` all recurse on `n / base` before printing `n % base`. Digits are
  naturally produced least-significant-first, and recursion reverses them for free — no
  temporary buffer, no reversal loop. The recursion depth is bounded by the number of
  digits (at most 10 for a 32-bit decimal, 16 for a 64-bit pointer in hex), so the stack
  cost is negligible and constant-bounded.

* **`long int` inside `ft_print_decimal`.** Negating `INT_MIN` as an `int` overflows,
  because `-INT_MIN` is not representable in 32 bits. The value is widened to `long`
  before the sign is stripped, which makes `INT_MIN` print correctly instead of invoking
  undefined behaviour.

* **`unsigned long` in `ft_print_hexa`.** The same function serves both `%x`/`%X`
  (32-bit `unsigned int`) and `%p` (64-bit address), so the parameter is the widest of
  the two. The base string — `"0123456789abcdef"` or its uppercase twin — is selected
  from the specifier itself, which avoids duplicating the conversion logic.

* **One function per file.** Required by the 42 Norm and it keeps each conversion
  independently testable.

## Resources

* `man 3 printf` — the reference behaviour this project is compared against
* `man 3 stdarg` — `va_start`, `va_arg`, `va_copy`, `va_end`
* [C99 standard, §7.19.6.1 — the `fprintf` conversion specifications](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf)
* [cppreference — Variadic arguments](https://en.cppreference.com/w/c/variadic)
* `man 2 write` — the only output syscall used here
* The 42 Norm (`norminette`) — formatting rules applied to every file

### Use of AI

AI was **not** used to design or write the implementation. The parsing loop, the
conversion functions and the recursive digit-printing approach were written and debugged
by hand.

AI was used for two limited, post-implementation tasks:

1. **Review of the finished code against the subject.** It flagged two defects that were
   then fixed manually: the Makefile produced `printf.a` instead of the required
   `libftprintf.a`, and a `%` in the final position of the format string caused the index
   to skip over the terminating `'\0'` and read out of bounds.
2. **Drafting this README** and the comparison `main.c` shown above, from the existing
   source files.

No AI-generated code is present in `ft_printf.c`, `ft_check_symbol.c`, or any of the
`ft_print_*.c` files.
