/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:24:24 by guilhfer          #+#    #+#             */
/*   Updated: 2022/10/29 01:53:23 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	game_init(t_game *game)
{
	game->mlx_ptr = NULL;
	game->mlx_win = NULL;
	game->mlx_width = 0;
	game->mlx_height = 0;
	game->fd = 0;
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->map_e_count = 0;
	game->map_p_count = 0;
	game->map_c_count = 0;
	game->total_line_char = 0;
	game->img_width = 0;
	game->img_height = 0;
	game->img_collectable = NULL;
	game->img_empty_space = NULL;
	game->img_player = NULL;
	game->img_wall = NULL;
	game->img_exit = NULL;
	game->player_x = 0;
	game->player_y = 0;
	game->movements = 0;
}

static void	game_play(t_game *game)
{
	game->mlx_ptr = mlx_init();
	img_setup(game);
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->img_width
			* game->map_width, game->img_height * game->map_height, GAME_NAME);
	map_to_win(game);
	player_postion(game);
	mlx_key_hook(game->mlx_win, key_events, game);
	mlx_hook(game->mlx_win, 17, 1L << 0, game_exit_sucess, game);
	mlx_loop_hook(game->mlx_ptr, map_to_win, game);
	mlx_loop(game->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game_init(&game);
	if (check_arg(argv[1]) == 1)
		return (1);
	if (argc == 2)
	{
		game.map = init_map(&game, argv[1]);
		if (!game.map)
		{
			ft_clear_split(game.map);
			log_msg(-1);
		}
		if (map_check(&game) == 0)
			game_play(&game);
		else
		{
			ft_clear_split(game.map);
			log_msg(1);
		}
	}
	game_exit_sucess(&game);
	return (0);
}
