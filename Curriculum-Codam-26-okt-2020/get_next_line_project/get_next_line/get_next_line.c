/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 09:13:47 by saladin       #+#    #+#                 */
/*   Updated: 2021/04/27 16:38:35 by saladin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// objective: create a function that will allow us to read the text available on a
// file descriptor one line at a time until the EOF

// Compilation: gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c
// get_next_line_utils.c
// flags used for debugging: g
// gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c

// int open(const char *pathname, int flags);
// int close(int fd);
// void *malloc(size_t size);
// void free(void *ptr);
// int get_next_line(int fd, char **line);
// ssize_t read(int fd, void *buf, size_t count);

//				#####	GET_NEXT_LINE	#####

// bytes_read = the amount of bytes were read into the buffer
// save = temporary array to store current fd and lines read
// buffer = Temporary array that will hold a string, will be joined with saved

// allocate save and buffer accordingly
// assign positive number to bytes_read to enter loop

// 				#####	conditional structure	#####
// read fd into buffer size of BUFFER_SIZE
// if bytes == -1 return -1
// call ft_bufer transfer

char *readfd(int fd, char *save)
{
	char buffer[BUFFER_SIZE + 1];
	ssize_t r_number;

	if (fd < 0 || read(fd, buffer, 0) < 0 || BUFFER_SIZE < 1)
	{
		printf("fd < 0 || r_number < 0 || BUFFER_SIZE < 0\n");
		return (0);
	}
	if (save == NULL)
		save = ft_strnew(1);
	while (!(ft_strchr(save, '\n')))
	{
		r_number = read(fd, buffer, BUFFER_SIZE);
		if (r_number < 0)
		{
			printf("r_number < 0\n");
			return (0);
		}
		buffer[r_number] = '\0';
		save = ft_strjoin(save, buffer);
		if (save[0] == '\0' || r_number == 0)
			break;
	}
	return (save);
}

int get_next_line(int fd, char **line)
{
	static char *save;
	t_line transport;

	save = readfd(fd, save);
	if (!save || !line)
	{
		printf("line or string does not exist\n");
		return (-1);
	}
	transport.temp = ft_strchr(save, '\n');
	if (transport.temp)
	{
		transport.i = transport.temp - save;
		*line = ft_strndup(save, transport.i);
		if (!*line)
		{
			printf("Strndup failed to copy text\n");
			return (-1);
		}
		save = ft_strdup(transport.temp + 1);
		return (1);
	}
	else
	{
		*line = ft_strdup(save);
		if (!line)
		{
			printf("Strndup failed to copy text\n");
			return (-1);
		}
		free(save);
		save = NULL;
		if (*line[0] == '\0')
			return (0);
		return (1);
	}
}

// 						######	TEST	#####

// fd = file descriptor
// line = text that will be printed
// read_code = Return 1 when a line has been read,
// 0 when EOF has been reached, -1 when an error happened

// open file into file descriptor
// check whether fd exist; return error when unsuccessful
// assign positive value to read code to enter loop
// call get_next_line to check whether file is readable
// print line with SIZE_BUFFER

// free our line that will be allocated to the buffer size in get next line
// and finally closing file descriptor befor exiting the program

