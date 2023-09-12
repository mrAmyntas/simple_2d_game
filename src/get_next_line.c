/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/02 19:50:53 by bhoitzin      #+#    #+#                 */
/*   Updated: 2021/10/02 19:50:55 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int get_next_line(int fd, char **line)
{
    char    buff[1];
    int     i;
    char    *newline;
	int		j;

    line[0] = (char *)malloc(sizeof(char) * 1);
    if (line[0] == NULL)
        return (-1);
    line[0][0] = '\0';
    j = 2;
    while (j != 0)
    {
        j = read(fd, buff, 1);
		if (j == -1)
			return (-1);
        if (j == 0)
            return (0);
        if (buff[0] == '\n')
            return (1);
        i = 0;
        while (line[0][i] != '\0')
            i++;
        newline = (char *)malloc(i + 1);
        if (newline == NULL)
    	{
    		free (line[0]);
        	return (-1);
    	}
    	i = 0;
    	while (line[0][i] != '\0')
    	{
    	    newline[i] = line[0][i];
    	    i++;
    	}
    	newline[i] = '\0';
    	free(line[0]);
    	line[0] = (char *)malloc(i + 2);
    	if (line[0] == NULL)
    	{
    	    free (newline);
    	    return (-1);
    	}
    	i = 0;
    	while (newline[i] != '\0')
    	{
    	    line[0][i] = newline[i];
    	    i++;
    	}
		free(newline);
    	line[0][i] = buff[0];
    	line[0][i + 1] = '\0';
    }
    return (1);
}

