*This project has been created as part of the 42 curriculum by vneves-c.*

# libft

A C library of general-purpose functions, built from scratch as the first project of the 42 Common Core.

-----

## Description

**libft** is a custom C standard library written without relying on any libc functions. The goal is to deeply understand how foundational C functions work by reimplementing them — covering memory manipulation, string handling, character classification, linked lists, and output utilities.

This library is designed to be reused across all future 42 projects, making it a long-term tool rather than a one-off exercise.

The project is divided into three parts:

- **Part 1** — Reimplementations of standard libc functions (`ft_strlen`, `ft_memcpy`, `ft_strchr`, etc.)
- **Part 2** — Additional utility functions not found in libc (`ft_split`, `ft_itoa`, `ft_substr`, etc.)
- **Part 3** — Linked list manipulation functions using the `t_list` structure

-----

## Instructions

### Compilation

Clone the repository and run `make` at the root:

```sh
git clone https://github.com/viniciusnevescosta/42-saopaulo
cd libft
make
```

This produces `libft.a` at the root of the directory.

### Cleaning

```sh
make clean    # removes object files
make fclean   # removes object files and libft.a
make re       # fclean + full rebuild
```

### Using in a project

Include the header and link the archive at compile time:

```c
#include "libft.h"
```

```sh
cc -Wall -Wextra -Werror main.c -L. -lft -o program
```

-----

## Library Reference

### Part 1 — Libc Functions

| Function | Description |
| --- | --- |
| `ft_isalpha` | Returns 1 if `c` is an alphabetic character, 0 otherwise |
| `ft_isdigit` | Returns 1 if `c` is a decimal digit character, 0 otherwise |
| `ft_isalnum` | Returns 1 if `c` is alphanumeric, 0 otherwise |
| `ft_isascii` | Returns 1 if `c` is a 7-bit ASCII character, 0 otherwise |
| `ft_isprint` | Returns 1 if `c` is a printable character, 0 otherwise |
| `ft_strlen` | Returns the length of a null-terminated string |
| `ft_memset` | Fills `n` bytes of memory starting at `b` with value `c` |
| `ft_bzero` | Sets `n` bytes of memory at `s` to zero |
| `ft_memcpy` | Copies `n` bytes from `src` to `dst` (no overlap) |
| `ft_memmove` | Copies `n` bytes from `src` to `dst`, handling overlap safely |
| `ft_strlcpy` | Copies up to `dstsize - 1` chars from `src` to `dst`, null-terminates; returns `strlen(src)` |
| `ft_strlcat` | Appends `src` to `dst` up to `dstsize` total; returns combined length |
| `ft_toupper` | Returns the uppercase equivalent of `c`, or `c` unchanged |
| `ft_tolower` | Returns the lowercase equivalent of `c`, or `c` unchanged |
| `ft_strchr` | Returns a pointer to the first occurrence of `c` in `s`, or NULL |
| `ft_strrchr` | Returns a pointer to the last occurrence of `c` in `s`, or NULL |
| `ft_strncmp` | Compares up to `n` characters of `s1` and `s2`; returns the difference |
| `ft_memchr` | Searches the first `n` bytes of `s` for byte `c`; returns pointer or NULL |
| `ft_memcmp` | Compares `n` bytes of `s1` and `s2`; returns the difference |
| `ft_strnstr` | Finds `needle` in `haystack`, searching at most `len` characters |
| `ft_atoi` | Converts the initial portion of `str` to an `int` |
| `ft_calloc` | Allocates `count * size` zero-initialized bytes; returns pointer or NULL |
| `ft_strdup` | Returns a malloc'd copy of string `s1`, or NULL on failure |

### Part 2 — Additional Functions

| Function | Description |
| --- | --- |
| `ft_substr` | Allocates and returns a substring of `s` starting at `start` with max length `len` |
| `ft_strjoin` | Allocates and returns the concatenation of `s1` and `s2` |
| `ft_strtrim` | Allocates a copy of `s1` with characters in `set` removed from both ends |
| `ft_split` | Splits `s` on delimiter `c`; returns a NULL-terminated array of strings |
| `ft_itoa` | Converts integer `n` to a malloc'd string representation |
| `ft_strmapi` | Applies function `f(index, char)` to each character of `s`; returns new string |
| `ft_striteri` | Applies function `f(index, &char)` to each character of `s` in place |
| `ft_putchar_fd` | Writes character `c` to file descriptor `fd` |
| `ft_putstr_fd` | Writes string `s` to file descriptor `fd` |
| `ft_putendl_fd` | Writes string `s` followed by a newline to file descriptor `fd` |
| `ft_putnbr_fd` | Writes integer `n` to file descriptor `fd` |

### Part 3 — Linked List

The list is built on the following structure, defined in `libft.h`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Function | Description |
| --- | --- |
| `ft_lstnew` | Allocates and returns a new node with `content`; `next` set to NULL |
| `ft_lstadd_front` | Inserts node `new` at the beginning of list `*lst` |
| `ft_lstsize` | Returns the number of nodes in the list |
| `ft_lstlast` | Returns a pointer to the last node of the list |
| `ft_lstadd_back` | Appends node `new` to the end of list `*lst` |
| `ft_lstdelone` | Frees the content of node `lst` using `del`, then frees the node |
| `ft_lstclear` | Frees all nodes in the list using `del`; sets the pointer to NULL |
| `ft_lstiter` | Applies function `f` to the `content` of each node |
| `ft_lstmap` | Creates a new list by applying `f` to each node's content; uses `del` on failure |

-----

## Resources

### References

- [42 Norm v4.1](https://github.com/42School/norminette) — coding standard applied throughout
- [norminette](https://github.com/42School/norminette) — automated norm checker

### AI Usage

Claude and Gemini was used as a learning aid throughout the project, in two ways:

1. **Clarifying concepts** — when in doubt about how a specific function was supposed to behave (edge cases, return values, memory semantics), questions were asked to the AI to understand the underlying behavior before writing any code.

2. **Code review** — after writing each function independently, the AI was asked to evaluate the implementation and point out logical errors, undefined behavior, or norm violations. All fixes were applied and understood before moving on.
