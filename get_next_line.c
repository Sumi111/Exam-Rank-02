#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int i;
	
	i = 0;
	if (!s)
		return(0);
	while(s[i])
		i++;
	return(i);
}

char	*ft_strjoin(char *str, char *buf)
{
	char *result;
	int size;
	int i, j;
	
	if (!str && !buf)
		return(NULL);
	size = ft_strlen(str) + ft_strlen(buf);
	array = malloc(sizeof(char) * (size + 1);
	if (!array)
		return(NULL);
	i = 0;
	j = 0;
	if (str != '\0')
	{
		while (str[i])
		{
			result[j] = str[i];
			i++;
			j++;
		}
		i = 0;
	}
	while(buf[i])
	{
		result[j] = buf[i];
		i++;
		j++;
	}
	result[j] = '\0';
	free(str);
	return(result);
}

char *get_line(char *str);
{
	char *result;
	int i;
	
	i = 0;
	while(str[i] && str[i] != '\n')
		i++;
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return(NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return(result);
}

char *next_line(char *str)
{
	char *s;
	int i, j;
	
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free (str);
		return (NULL);
	}
	s = malloc(sizeof(char) * (ft_strlen(str) - i + 1);
	if (!s)
		return(NULL);
	j = 0;
	i++;
	while (str[i] != '\0')
	{
		s[j] = str[i];
		i++;
		j++;
	}
	s[j] = '\0';
	free(str);
	return(s);
}

int get_next_line(char **line)
{
	char *buf;
	static char *str;
	int fd;
	int count;

	count = 1;
	fd =0;
	if(!line)
		return(-1);
	while(buf[0] != '\n' && count != 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if(count == -1)
			return(-1);
		buf[count] = '\0';
		str = ft_strjoin(str, buf);

	}
	*line = get_line(str);
	str = next_line(str);
	if (count == 0)
		return(0);
	return(1);
}
