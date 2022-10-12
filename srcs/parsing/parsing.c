/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:55:57 by mrattez           #+#    #+#             */
/*   Updated: 2022/10/12 10:45:52 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	parse_scene(t_engine *engine, char *path)
{
	char	*line;
	char	**parameters;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (false);
	line = get_next_line(fd);
	while (line != NULL)
	{
		parameters = str_split(line, " \t");
		printf("LINE: \"%s\"\n", line);
		for (int i = 0; parameters[i]; i++)
			printf("parameters[%d] = \"%s\"\n", i, parameters[i]);
		line = get_next_line(fd);
	}
	(void) engine;
	(void) line;
	return (true);
}
