/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 09:13:47 by saladin       #+#    #+#                 */
/*   Updated: 2021/05/05 12:29:13 by saladin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/* This function appends a single line into our line variable. We do this by
 * 	finding the length of the line.
 * 1) If at index len, the character is a newline, we save the string into line
 * 	up to the length found.
 * 2) Then we readjust the stored data (**saved) by creating a temporary string
 * 	that stored the rest of data after the newline.
 * 3) We free the stored data to update it to the current address because we
 * 	already append a line from it. This is done by freeing *s and setting it
 * 	equal to the temporary string that stored the remaining data.
 * 4) At any point when we reach the end of file, we free the memory used to
 * 	track our location in *s because it is not nedded anymore.
 */

static void	ft_memdel(void **stringArray)
{
	if (stringArray != NULL)
	{
		free(*stringArray);
		*stringArray = NULL;
	}
}

static void	ft_strdel(char **stringArray)
{
	if (stringArray != NULL && *stringArray != NULL)
		ft_memdel((void**)stringArray);
}

static int	appendline(char **saved, char **line)
{
	char *tmp;
	size_t i;

	i = 0;
	while((*saved)[i] != '\n' && (*saved)[i] != '\0')
		i++;
	if ((*saved)[i] == '\n')
	{
		*line = ft_substr(*saved, 0, i);
		tmp = ft_strdup(&((*saved)[i]) + 1);
		free(*saved);
		*saved = tmp;
		if ((*saved)[0] == '\0')
			ft_strdel(saved);
	}
	else
	{
		*line = ft_strdup(*saved);
		ft_strdel(saved);
	}
	return (1);
}

/* This is a helper function created to output the results after all the other
 * cases are taken care of in get_next_line.
 * 1) If ret is less than 0 , then return -1 since an error occurred.
 * 2) If the reading is completed, return a 0.
 * 3) Else , go to appendline function to return 1 and save the line read at
 * 	the current address of the static variavle stored.
*/

static int	output(char **saved, char **line, int fd, int rbytes)
{
	if (rbytes < 0)
		return (-1);
	if (rbytes == 0 && saved[fd] == NULL)
		return (0);
	else
		return (appendline(&saved[fd], line));
}

/*
SYNOPSIS
       #include <unistd.h>

       ssize_t read(int fd, void *buf, size_t count);

DESCRIPTION
       read()  attempts to read up to count bytes from file descriptor fd into
       the buffer starting at buf.
*/

/* the get_next line Fucntion reads a file and returns the line ending with a 
 * newline character from a file descriptor.
 * 1) A static variable is used, so that whenever get_next_line is called, it
 * 	remembers the prevous function call. 
 * 2) When get_next_line is first called, we check to see if our static
 * 	variable **s is empty. If it is, we allocate memory for it using our buff 
 * string. 
 * 3) In the loop, we will continue to read more of the line and join them 
 * 	together using a temporary string. 
 * 4) This temporary string will replace the stored data each iteration so that
 * 	we can keep track of how much is read and delete the previous stored data.
 * 5) This is needed because we are only reading so many n-bytes at a time
 * 	decided by our BUFF_SIZE.
 * 6) If we read at each iteration withour freeing memory, then we would have
 * 	memory leaks, the loop breaks when a newline is encountered.
 * 7) Finally, we call output function to check what should be returned.
 */

int	get_next_line(int fd, char **line)
{
	static	char *saved[fd];
	char *tmp;
	char buf[BUFFER_SIZE + 1];
	ssize_t rbytes;

	if (fd < 0 || line == NULL)
		return (-1);
	while((rbytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		printf("rbytes: %zu\n", rbytes);
		buf[rbytes] = '\0';
		if(saved[fd] == NULL)
			saved[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(saved[fd], buf);
			free(saved[fd]);
			saved[fd] = tmp;
		}
		if (ft_strchr(saved[fd], '\n'))
			break ;
	}
	return (output(saved, line, fd, rbytes));
}
