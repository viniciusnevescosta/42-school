This is a WIP repository.

## Important info:

1. Piscine lists are not finished yet, but they will be, I'm focusing on common core now;
2. All tests are LLM generated. Only the tests;
3. I publish how did I come to the code solution on my website, link: <http://viniciusnevescosta.com/42-são-paulo/>;

## How to execute the tests

1. You should have [fish shell](https://fishshell.com) installed on your computer, it's my preferred shell env and also the one used on 42 school computers;
2. Then, you should guarantee permissions to the script;

<!-- end list -->

- e.g `chmod +x tests/libft/test.fish`.

<!-- end list -->

3. You should use the script passing the correct path alongside it.

<!-- end list -->

- e.g `./tests/libft/test.fish ./common-core/libft`.

<!-- end list -->

4. The script compares the result with the result using the original function;

<!-- end list -->

- e.g It compares the `ft_isalpha.c` results with the `isalpha` results.

<!-- end list -->

5. Finally, if the results are as expected, the script will print `OK`, otherwise, it will print `KO`.
