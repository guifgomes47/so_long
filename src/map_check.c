/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:40:39 by guilhfer          #+#    #+#             */
/*   Updated: 2022/10/29 01:35:35 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	wall_check(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_width)
	{
		y = 0;
		while (y < game->map_height)
		{
			if (game->map[0][x] != '1' || game->map[y][0] != '1'
				|| game->map[game->map_height - 1][x] != '1'
				|| game->map[y][game->map_width - 1] != '1')
				log_msg(6);
			y++;
		}
		if (y != game->map_height)
			log_msg(6);
		x++;
	}
	return (0);
}

static int	elements_count(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_width)
	{
		y = 0;
		while (y < game->map_height)
		{
			if (game->map[y][x] == 'P')
				game->map_p_count++;
			if (game->map[y][x] == 'E')
				game->map_e_count++;
			if (game->map[y][x] == 'C')
				game->map_c_count++;
			y++;
		}
		x++;
	}
	if (game->map_e_count != 1 || game->map_p_count != 1
		|| game->map_c_count == 0)
		log_msg(3);
	return (0);
}

int	map_rect(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		if ((int)ft_strlen(game->map[i]) != game->map_width)
			log_msg(2);
		i++;
	}
	return (0);
}

static int	elements_check(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_width)
	{
		y = 0;
		while (y < game->map_height)
		{
			if (game->map[y][x] != '1' && game->map[y][x] != '0'
				&& game->map[y][x] != 'P' && game->map[y][x] != 'E'
				&& game->map[y][x] != 'C')
				log_msg(4);
			y++;
		}
		x++;
	}
	return (0);
}

int	map_check(t_game *game)
{
	int	element_count;
	int	element_check;
	int	wall;
	int	i;

	i = -1;
	while (game->map[++i])
		game->map_height++;
	game->map_width = (int)ft_strlen(game->map[0]);
	if (map_rect(game) == 1)
		log_msg(3);
	element_count = elements_count(game);
	element_check = elements_check(game);
	wall = wall_check(game);
	if (element_count == 0 && wall == 0 && element_check == 0)
		return (0);
	log_msg(1);
	return (1);
}