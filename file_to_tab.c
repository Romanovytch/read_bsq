#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 10

int	main()
{
	int	fd;
	char	*buffer;
	int	ret;
	char	*tmp;
	int	relloc;
	char	*start;

	relloc = 1;
	fd = open("test", O_RDONLY);
	buffer = malloc(sizeof(char) * SIZE + 1);
	start = buffer;
	while ((ret = read(fd, buffer, SIZE)) != 0)
	{
		start[(SIZE * (relloc - 1)) + ret] = '\0';
		if (ret == SIZE)
		{
			tmp = start;
			buffer = malloc(sizeof(char) * (SIZE * (relloc + 1)) + 1);
			start = buffer;
			buffer = strncpy(buffer, tmp, (SIZE * relloc));
			buffer = buffer + (SIZE * relloc);
			relloc++;
		}
	}
	printf("%s\n", start);
	close(fd);
	return (0);
}
