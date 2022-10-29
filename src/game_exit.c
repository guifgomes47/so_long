/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:29:58 by guilhfer          #+#    #+#             */
/*   Updated: 2022/10/28 21:20:50 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_clear_split(char **ptr)
{
	int	i;

	if (ptr != NULL)
	{
		i = -1;
		while (ptr[++i])
			free(ptr[i]);
		free(ptr);
	}
}

int	game_exit(t_game *game, int status)
{
	if (!game->img_player)
		mlx_destroy_image(game->mlx_ptr, game->img_player);
	if (!game->img_exit)
		mlx_destroy_image(game->mlx_ptr, game->img_exit);
	if (!game->img_collectable)
		mlx_destroy_image(game->mlx_ptr, game->img_collectable);
	if (!game->img_wall)
		mlx_destroy_image(game->mlx_ptr, game->img_wall);
	if (!game->img_empty_space)
		mlx_destroy_image(game->mlx_ptr, game->img_empty_space);
	if (!game->mlx_win)
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	if (!game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	ft_clear_split(game->map);
	free(game->mlx_ptr);
	exit(status);
}

int	game_exit_sucess(t_game *game)
{
	game_exit(game, 0);
	return (0);
}