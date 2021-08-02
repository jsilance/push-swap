/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:47:55 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/08 23:29:02 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# include <stdlib.h>
# include <unistd.h>

int	get_next_line(int fd, char **line);

#endif
