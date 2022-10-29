/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:50:05 by guilhfer          #+#    #+#             */
/*   Updated: 2022/10/29 01:02:25 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	img_setup(t_game *game)
{
	game->img_width = 32;
	game->img_height = 32;
	game->img_empty_space = mlx_xpm_file_to_image(game->mlx_ptr, EMPTY_SPACE,
			&game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, WALL,
			&game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, EXIT,
			&game->img_width, &game->img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER_DOWN,
			&game->img_width, &game->img_height);
	game->img_collectable = mlx_xpm_file_to_image(game->mlx_ptr, COLLECTABLE,
			&game->img_width, &game->img_height);
}
