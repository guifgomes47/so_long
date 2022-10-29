/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_postion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:25:39 by guilhfer          #+#    #+#             */
/*   Updated: 2022/10/29 00:21:23 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	player_postion(t_game *game)
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
			{
				game->player_x = x;
				game->player_y = y;
				break ;
			}
			y++;
		}
		x++;
	}
	game->movements = 0;
}
