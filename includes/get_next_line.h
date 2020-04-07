/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:24:43 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/16 13:40:08 by hehlinge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 2048

typedef struct			s_gnl
{
	int					fd;
	char				buf[BUFF_SIZE + 1];
	struct s_gnl		*next;
}						t_gnl;

int						get_next_line(const int fd, char **line);

#endif
