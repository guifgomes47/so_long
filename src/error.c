/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 20:43:02 by guilhfer          #+#    #+#             */
/*   Updated: 2022/10/29 01:52:30 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	log_msg(int log_number)
{
	if (log_number == 0)
	{
		ft_printf("Game Complete!\n");
		exit(0);
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
	exit(1);
}

int	check_arg(char *argv)
{
	char	*ext;

	if (!argv)
		return (1);
	ext = ft_strrchr(argv, '.');
	if (ext == NULL)
	{
		log_msg(5);
		return (1);
	}
	if (ft_strncmp(ext, ".ber", 5) == 0)
		return (0);
	log_msg(5);
	return (1);
}
