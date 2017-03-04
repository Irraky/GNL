#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int                main(int ac, char **av)
{
	int            fd;
	char        *line;
	int            ret;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			ft_putnbr(ret);
			ft_putstr("line :  |");
			ft_putstr(line);
	//		ft_putendl(line);
			ft_putendl("|");
			//free(line);
		}
		printf("%d", ret);
		close(fd);
		if (ret == -1)
			return (-1);
	}
	return (0);
}
