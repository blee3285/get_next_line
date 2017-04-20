#include "get_next_line.h"

int main(int ac, char **av)
{
	char    *line;
	int fd1;

	fd1 = open(av[1], O_RDONLY);
	line = (char*)malloc(sizeof(char) * 500);
	while (get_next_line(fd1, &line))
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
	return (0);
}
