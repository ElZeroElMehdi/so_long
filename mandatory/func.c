/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:33:08 by eelmoham          #+#    #+#             */
/*   Updated: 2022/03/16 01:14:47 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_over(char *msg, char **map)
{
	write (2, msg, ft_strlen(msg));
	free(map);
	exit(1);
	return (0);
}

int	is_exit(t_data *data)
{
	int	count_co;

	count_co = count_c(data->map, 'C');
	if (count_co == 0)
		return (1);
	else
		return (0);
}

int	func(int key, t_data *obj)
{
	int			x;
	int			y;
	static int	count;

	x = obj->player.x;
	y = obj->player.y;
	if (key == 53)
		game_over("Game Over, You Lose\n", obj->map);
	if (key == 13 || key == 2 || key == 0 || key == 1)
	{
		mlx_clear_window(obj->mlx, obj->win);
		obj->map[y][x] = '0';
		if (key == 13)
			obj->player.y -= 1;
		if (key == 2)
			obj->player.x += 1;
		if (key == 0)
			obj->player.x -= 1;
		if (key == 1)
			obj->player.y += 1;
		obj->true = 1;
	}
	move(x, y, obj);
	return (0);
}

void	check_element(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] != '1') && (map[i][j] != '0') && (map[i][j] != 'E')
				&& (map[i][j] != 'P') && (map[i][j] != 'C'))
				game_over("wrong map\n", map);
			j++;
		}
		i++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, int from, size_t n)
{
	size_t	i;
	size_t	j;

	i = from;
	j = 0;
	while ((i < n) && (s1[i] != '\0' || s2[j] != '\0'))
	{
		if (s1[i] == s2[j])
		{
			i++;
			j++;
		}
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[j]);
	}
	return (0);
}
