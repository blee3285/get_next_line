#include "get_next_line.h"

int main(int ac, char **av)
{
	char    *line;
	int fd1;
	int i;

	fd1 = open(av[1], O_RDONLY);
	//line = ft_strnew(500);
	line = NULL;
	i = 0;
	while (get_next_line(fd1, &line))
	{
		ft_putnbr(i);
		ft_putstr(": ");
		ft_putstr(line);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
