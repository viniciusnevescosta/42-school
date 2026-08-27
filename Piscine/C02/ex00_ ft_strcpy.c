#include <stdio.h>

char	*ft_strcpy(char *dest, char *src);

int	main(void)
{
	char dest[4] = "abc";
	char src[4] = "abc";

	printf("%s", ft_strcpy(dest, src));
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
