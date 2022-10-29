/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:51:00 by guilhfer          #+#    #+#             */
/*   Updated: 2022/10/16 20:05:22 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	draw_map(t_game *game, int x)
{
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		if (game->map[y][x] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_wall, x * game->img_width, y * game->img_height);
		if (game->map[y][x] == '0')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_empty_space, x * game->img_width,
				y * game->img_height);
		if (game->map[y][x] == 'P')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_player, x * game->img_width, y * game->img_height);
		if (game->map[y][x] == 'E')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_exit, x * game->img_width, y * game->img_height);
		if (game->map[y][x] == 'C')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_collectable, x * game->img_width,
				y * game->img_height);
		y++;
	}
}

int	map_to_win(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->map_width)
	{
		draw_map(game, x);
		x++;
	}
	return (0);
}
