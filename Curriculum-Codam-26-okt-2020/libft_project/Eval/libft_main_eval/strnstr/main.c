#include "../libft.h"
#include <stdio.h>
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*l;
	char	*b;

	i = 0;
	j = 0;
	l = (char*)little;
	b = (char*)big;
	if (little == 0 || big == 0)
		return (0);
	if (*little == 0)
		return (b);
	while (i < len && b[i] != 0)
	{
		if (b[i] == l[j])
		{
			while (j + i < len && l[i])
			{
				if (b[i + j] != l[j])
					break;
				j++;
			}
			if (l[j] == 0)
				return (b + i);
		}
		i++;
	}
	return (NULL);
}

int main()
{
    char dest[50] = {"hallo maarten van codam"};
    char src[20] = {0};
    char *pt;

    pt = ft_strnstr(dest, src, 17);
    puts(pt);
    printf("%p/n", pt);
}