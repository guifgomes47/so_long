/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:52:40 by guilhfer          #+#    #+#             */
/*   Updated: 2022/10/29 00:47:48 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	empty_line(char *temp)
{
	int	i;

	i = 0;
	if (temp[0] == '\n')
	{
		log_msg(1);
		free(temp);
		return (1);
	}
	while (temp[i] != '\0')
	{
		if (temp[i] == '\n')
		{
			if (temp[i + 1] == '\n' && temp[i + 2] == '1')
			{
				log_msg(1);
				free(temp);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

char	**init_map(t_game *game, char *map_name)
{
	char	**map;
	char	*swap;
	char	*line;
	char	*temp;

	game->fd = open(map_name, O_RDONLY);
	if (game->fd == -1)
		return (NULL);
	temp = ft_strdup("");
	while (1)
	{
		line = get_next_line(game->fd);
		if (!line)
			break ;
		swap = temp;
		temp = ft_strjoin(swap, line);
		free(swap);
		free(line);
	}
	if (empty_line(temp) == 1)
		return (NULL);
	map = ft_split(temp, '\n');
	free(temp);
	close(game->fd);
	return (map);
}
