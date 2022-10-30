/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 03:27:38 by guilhfer          #+#    #+#             */
/*   Updated: 2022/10/30 06:04:12 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	flood_fill(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1' || game->map[y][x] == 'F')
		return ;
	if (game->map[y][x] == '0' || game->map[y][x] == 'C' ||
		game->map[y][x] == 'E' || game->map[y][x] == 'P')
	{
		if (game->map[y][x] == 'C')
			game->c_acess++;
		if (game->map[y][x] == 'E')
			game->e_acess++;
		game->map[y][x] = 'F';
		flood_fill(game, x, y - 1);
		flood_fill(game, x, y + 1);
		flood_fill(game, x - 1, y);
		flood_fill(game, x + 1, y);
		return ;
	}
}

int	map_valid(t_game *game, char *argv)
{
	int	check_collect;
	int	check_exit;

	player_position(game);
	flood_fill(game, game->player_x, game->player_y);
	check_collect = game->map_c_count - game->c_acess;
	check_exit = game->map_e_count - game->e_acess;
	if (check_collect == 0 && check_exit == 0)
	{
		free_map(game->map);
		game->map = init_map(game, argv);
		return (0);
	}
	log_msg(7);
	return (1);
}
