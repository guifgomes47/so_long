/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:52:40 by guilhfer          #+#    #+#             */
/*   Updated: 2022/10/29 23:01:16 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	empty_line(char *temp)
{
	int	i;

	i = 0;
	if (temp[0] == '\n')
	{
		free(temp);
		log_msg(1);
		return (1);
	}
	while (temp[i] != '\0')
	{
		if (temp[i] == '\n')
		{
			if (temp[i + 1] == '\n' && temp[i + 2] == '1')
			{
				free(temp);
				log_msg(1);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

char	*line_format(int fd)
{
	char	*line;
	char	*temp;
	char	*swap;

	line = ft_strdup("");
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		swap = line;
		line = ft_strjoin(swap, temp);
		free(swap);
		free(temp);
	}
	return (line);
}

char	**init_map(t_game *game, char *map_name)
{
	char	**map;
	char	*line;

	game->fd = open(map_name, O_RDONLY);
	if (game->fd == -1)
		return (NULL);
	line = line_format(game->fd);
	if (empty_line(line) == 1)
	{
		free_split(game->map);
		exit(1);
	}
	map = ft_split(line, '\n');
	free(line);
	close(game->fd);
	return (map);
}
