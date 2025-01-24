/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:57:18 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/24 16:53:16 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	correct_distortion(t_game *game)
{
	game->ray.length = game->ray.length * cos(game->ray.angle - game->player.angle);
}

void	draw_background(t_game *game)
{
	int	i;
	int j;

	i = 0;
	return ;
	while (i < WINDOW_WIDTH)
	{
		j = 0;
		while (j < WINDOW_HEIGHT / 2)
			mlx_put_pixel(game->background, i, j++, 0x0000FFFF); //green for testing
		while (j < WINDOW_HEIGHT)
			mlx_put_pixel(game->background, i, j++, 0x000000FF); //yellow for testing
		i++;
	}
}

static void	draw_floor_ceiling(t_game *game, int ray)
{
	int	i;

	i = 0;
	while (i < WINDOW_HEIGHT / 2)
		mlx_put_pixel(game->frame, ray, i++, 0x0000FFFF); //green for testing
	while (i < WINDOW_HEIGHT)
		mlx_put_pixel(game->frame, ray, i++, 0x000000FF); //yellow for testing
}

static void draw_walls(t_game *game, float top, float bottom, int ray)
{
	int color;

	color = 0x00FFFFFF; //later determine based direction, even later replace by textures
	while (top <= bottom)
	{
		//if ()
		mlx_put_pixel(game->frame, ray, top, color);
		top++;
		if (top >= WINDOW_HEIGHT)
			break ;
	}
}

void	clear_frame(t_game *game)
{
	int			i;
	int			black;
	
	black = 0xFF0000;
	i = 0;
	return ;
	while (i < (WINDOW_HEIGHT * WINDOW_HEIGHT))
	{
		game->frame->pixels[i] = (uint8_t)black;
		i++;
	}
}

void    render_ray_into_frame(t_game *game, int ray)
{
	float		wall_height;
	float		wall_top;
	float		wall_bottom;

	correct_distortion(game);
	wall_height = TILE_SIZE * WINDOW_HEIGHT / game->ray.length;
	wall_top = (WINDOW_HEIGHT / 2) - (wall_height / 2);
	if (wall_top < 0)
		wall_top = 0;
	wall_bottom = (WINDOW_HEIGHT / 2) + (wall_height / 2);
	if (wall_bottom > WINDOW_HEIGHT)
		wall_bottom = WINDOW_HEIGHT;
	draw_floor_ceiling(game, ray);
	draw_walls(game, wall_top, wall_bottom, ray); // here or somewhere else?
}
