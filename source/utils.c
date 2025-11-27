/*
 * ________________________________________________________________________________
 * |  File: utils.c
 * |  Project: patient
 * |  File Created: Friday, 29th November 2024 07:33 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */


# include "../includes/minihell.h"


#define BUFFER_SIZE 32

char *get_next_line(int fd)
{
    char c;
    int i = 0;
    int rd_status = 0;
	int total_size = BUFFER_SIZE;
    char *buffer = malloc(BUFFER_SIZE + 1);
	

    if (!buffer)
        return (NULL);

    while ((rd_status = read(fd, &c, 1)) > 0)
    {
		if (i >= total_size - 1)
		{
			total_size *= 2;
			char *newbuffer = realloc(buffer, total_size + 1);
			if (!newbuffer)
			{
				free(buffer);
				return NULL;
			}
			buffer = newbuffer;
		}
        buffer[i++] = c;
        if (c == '\n')
            break;
    }

    if (rd_status == -1 || i == 0)
    {
        free(buffer);
        return NULL;
    }

    buffer[i] = '\0';
    return buffer;
}


u32	numlen(int n)
{
	u32		len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len += 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*itoa(int n)
{
	char		*str;
	int	num;
	u32		len;

	len = numlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	else
		num = n;
	if (num == 0)
		str[0] = '0';
	str[len] = '\0';
	while (num != 0)
	{
		str[len - 1] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}


static void	*malloc_strlen_n(u32 c, va_list arg)
{
	u32			size;
	va_list		arg_copy;
	char			*out;

	va_copy(arg_copy, arg);
	size = 0;
	while (c)
	{
		size += strlen(va_arg(arg_copy, char *));
		c--;
	}
	va_end(arg_copy);
	out = malloc(sizeof(char) * (size + 1));
	return (out);
}

char	*strjoin_e(u32 c, ...)
{
	va_list		arg;
	char			*dcse2;
	char			*tmp;
	u32			i;
	u32			j;

	va_start(arg, c);
	dcse2 = malloc_strlen_n(c, arg);
	j = 0;
	if (!dcse2)
	{
		va_end(arg);
		free(dcse2);
		return (NULL);
	}
	while (c)
	{
		i = 0;
		tmp = va_arg(arg, char *);
		while (tmp[i])
			dcse2[j++] = tmp[i++];
		c--;
	}
	dcse2[j] = '\0';
	va_end(arg);
	return (dcse2);
}

void print_list_2d(char **list)
{
	int i;
	i = 0;
	while (list[i])
	{
		printf("%s\n", list[i]);
		i += 1;
	}
}
