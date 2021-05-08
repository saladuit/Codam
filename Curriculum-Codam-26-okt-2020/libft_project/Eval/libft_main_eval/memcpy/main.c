#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (dst == src)
		return (dst);
	while (n)
	{
		((char *)dst)[n - 1] = ((char *)src)[n - 1];
		n--;
	}
	return (dst);
}

int main()
{
	const char src[50] = "http://www.tutorialspoint.com";
	char dest[50];
	strcpy(dest, "Heloooo!!");
	printf("Before memcpy dest = %s\n", dest);
	ft_memcpy(dest, src, strlen(src) + 1);
	printf("After memcpy dest = %s\n", dest);

	return (0);
}