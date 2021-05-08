#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "../libft.h"

char* msg = "This is the string: not copied";

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		if (((unsigned char *)src)[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}

int main( void )
{
    char buffer[30];

    memset( buffer, '\0', 30 );
    ft_memccpy( buffer, msg, ':', 30 );

    printf( "%s\n", buffer );
    
    return EXIT_SUCCESS;
}