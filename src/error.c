/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 20:43:02 by guilhfer          #+#    #+#             */
/*   Updated: 2022/10/30 04:55:24 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	log_msg(int log_number)
{
	if (log_number == 0)
	{
		ft_printf("Game Complete!\n");
	}
	if (log_number == -1)
		ft_printf("Error\nMap has not found\n");
	if (log_number == 1)
		ft_printf("Error\nMap invalid format\n");
	if (log_number == 2)
		ft_printf("Error\nMap must be rectangular\n");
	if (log_number == 3)
		ft_printf("Error\nMap has invalid number of elements\n");
	if (log_number == 4)
		ft_printf("Error\nMap has unknown elements\n");
	if (log_number == 5)
		ft_printf("Error\nMap file must be .ber\n");
	if (log_number == 6)
		ft_printf("Error\nMap wall problem\n");
	if (log_number == 7)
		ft_printf("Error\nMap doesn't have a valid pathway\n");
}

void	check_arg(int argc, char **argv)
{
	char	*ext;

	if (argc != 2 || !argv[1])
	{
		log_msg(-1);
		exit(1);
	}
	ext = ft_strrchr(argv[1], '.');
	if ((ft_strlen(argv[1]) < 4) || !ext)
	{
		log_msg(5);
		exit(1);
	}
	if (ft_strncmp(ext, ".ber", 5) != 0)
	{
		log_msg(5);
		exit(1);
	}
}
