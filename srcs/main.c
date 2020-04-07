/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:03:58 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/18 09:44:18 by hehlinge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fd;
	int		arg;
	char	*line;

	if (argc < 1)
		ft_putendl("No file to read");
	arg = 0;
	line = NULL;
	while (++arg < argc)
	{
		fd = open(argv[arg], O_RDONLY);
		if (fd < 3)
			ft_putendl("Le fichier n'est pas valide");
		else
		{
			while (get_next_line(fd, &line))
				ft_putendl(line);
		}
		close(fd);
	}
}
