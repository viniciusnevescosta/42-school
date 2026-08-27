*This project has been created as part of the 42 curriculum by vneves-c.*

# Get Next Line

## Description

Get Next Line is a project from the 42 curriculum that introduces the concept of static variables in C. The goal is to program a function that returns a line read from a file descriptor. This function allows you to read a text file one line at a time, regardless of the `BUFFER_SIZE` used during reading.

## Instructions

To compile the project, you need to use a C compiler (like `cc`) and include the necessary source files (`get_next_line.c` and `get_next_line_utils.c`). You must also define the buffer size used by the `read()` function using the `-D BUFFER_SIZE=n` flag.

Example compilation command:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

Once compiled, repeated calls to the `get_next_line(int fd)` function will return consecutive lines from the specified file descriptor.

## Algorithm

The implementation relies on a single static variable, `stash`, to preserve data read from the file descriptor across multiple calls to the function.

1. **Reading**: The function reads data from the file descriptor in chunks of `BUFFER_SIZE` bytes and appends it to the `stash`. This loop continues until a newline character (`\n`) is found within the `stash` or the end of the file is reached.
2. **Extraction**: Once a newline is detected (or EOF is reached), the function `ft_extract_line` isolates the string from the beginning of the `stash` up to and including the newline character.
3. **Saving the Rest**: The remaining characters in the `stash` (those following the newline) are preserved by the `ft_save_rest` function for the next time `get_next_line` is called.
4. **Memory Management**: Helper functions like `ft_strjoin` dynamically allocate memory for strings as they grow, and temporary variables are carefully freed to avoid memory leaks.

## Resources

- `man 2 read`
- `man 3 malloc`
- `man 3 free`
- AI Usage: AI was used exclusively to assist in drafting this README file content.
