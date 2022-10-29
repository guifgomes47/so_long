/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:50:11 by guilhfer          #+#    #+#             */
/*   Updated: 2022/10/29 01:03:50 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	key_up(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] != '1')
	{
		if (game->map[game->player_y - 1][game->player_x] == 'C')
			game->map_c_count--;
		if (game->map[game->player_y - 1][game->player_x] == 'E'
			&& game->map_c_count == 0)
		{
			log_msg(0);
			game_exit_sucess(game);
		}
		if (game->map[game->player_y - 1][game->player_x] != 'E'
			|| game->map_c_count == 0)
		{
			game->map[game->player_y][game->player_x] = '0';
			game->map[game->player_y - 1][game->player_x] = 'P';
			map_to_win(game);
			game->player_y = game->player_y - 1;
			game->movements++;
			ft_printf("Movements: %d\n", game->movements);
		}
	}
}

static void	key_left(t_game *game)
{
	if (game->map[game->player_y][game->player_x - 1] != '1')
	{
		if (game->map[game->player_y][game->player_x - 1] == 'C')
			game->map_c_count--;
		if (game->map[game->player_y][game->player_x - 1] == 'E'
			&& game->map_c_count == 0)
		{
			log_msg(0);
			game_exit_sucess(game);
		}
		if (game->map[game->player_y][game->player_x - 1] != 'E'
			|| game->map_c_count == 0)
		{
			game->map[game->player_y][game->player_x] = '0';
			game->map[game->player_y][game->player_x - 1] = 'P';
			map_to_win(game);
			game->player_x = game->player_x - 1;
			game->movements++;
			ft_printf("Movements: %d\n", game->movements);
		}
	}
}

static void	key_down(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] != '1')
	{
		if (game->map[game->player_y + 1][game->player_x] == 'C')
			game->map_c_count--;
		if (game->map[game->player_y + 1][game->player_x] == 'E'
			&& game->map_c_count == 0)
		{
			log_msg(0);
			game_exit_sucess(game);
		}
		if (game->map[game->player_y + 1][game->player_x] != 'E'
			|| game->map_c_count == 0)
		{
			game->map[game->player_y][game->player_x] = '0';
			game->map[game->player_y + 1][game->player_x] = 'P';
			map_to_win(game);
			game->player_y = game->player_y + 1;
			game->movements++;
			ft_printf("Movements: %d\n", game->movements);
		}
	}
}

static void	key_right(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] != '1')
	{
		if (game->map[game->player_y][game->player_x + 1] == 'C')
			game->map_c_count--;
		if (game->map[game->player_y][game->player_x + 1] == 'E'
			&& game->map_c_count == 0)
		{
			log_msg(0);
			game_exit_sucess(game);
		}
		if (game->map[game->player_y][game->player_x + 1] != 'E'
			|| game->map_c_count == 0)
		{
			game->map[game->player_y][game->player_x] = '0';
			game->map[game->player_y][game->player_x + 1] = 'P';
			map_to_win(game);
			game->player_x = game->player_x + 1;
			game->movements++;
			ft_printf("Movements: %d\n", game->movements);
		}
	}
}

int	key_events(int key, t_game *game)
{
	if (key == KEY_ESC)
		game_exit(game, 0);
	else if (key == KEY_W)
		key_up(game);
	else if (key == KEY_A)
		key_left(game);
	else if (key == KEY_S)
		key_down(game);
	else if (key == KEY_D)
		key_right(game);
	return (0);
}
