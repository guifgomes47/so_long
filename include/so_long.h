/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:54:08 by guilhfer          #+#    #+#             */
/*   Updated: 2022/10/29 22:40:21 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <libft.h>
# include <mlx.h>
# include <stdlib.h>
# define GAME_NAME "so_long"
# define WALL "./sprites/Wall.xpm"
# define EXIT "./sprites/Exit.xpm"
# define PLAYER_UP "./sprites/Player_Up.xpm"
# define PLAYER_DOWN "./sprites/Player_Down.xpm"
# define PLAYER_LEFT "./sprites/Player_Left.xpm"
# define PLAYER_RIGHT "./sprites/Player_Right.xpm"
# define EMPTY_SPACE "./sprites/Empty_space.xpm"
# define COLLECTABLE "./sprites/Collectable.xpm"
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_game
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		mlx_width;
	int		mlx_height;

	int		fd;
	char	**map;
	int		map_width;
	int		map_height;
	int		map_e_count;
	int		map_p_count;
	int		map_c_count;
	int		total_line_char;

	int		img_width;
	int		img_height;
	void	*img_collectable;
	void	*img_empty_space;
	void	*img_player;
	void	*img_wall;
	void	*img_exit;

	int		player_x;
	int		player_y;
	int		movements;
}			t_game;

int			main(int argc, char **argv);
int			init_build(t_game *game);
void		check_arg(int argc, char **argv);
char		**init_map(t_game *game, char *map_name);
void		img_setup(t_game *game);
int			map_to_win(t_game *game);
void		free_split(char **ptr);
int			map_check(t_game *game);
void		player_postion(t_game *game);
int			key_events(int key, t_game *game);
int			game_exit(t_game *game, int status);
int			game_exit_sucess(t_game *game);
void		log_msg(int log_number);
#endif
