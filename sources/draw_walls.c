/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:57:18 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/24 15:20:54 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// static void	correct_distortion(t_game *game)
// {
// 	game->ray.length = game->ray.length * cos(game->ray.angle - game->player.angle);
// }

static void	draw_floor_ceiling(t_game *game, int ray)
{
	int	i;

	i = 0;
	while (i < WINDOW_HEIGHT / 2)
		//mlx_put_pixel(game->frame, x, i++, game->found_ceiling_rgb);
		mlx_put_pixel(game->frame, ray, i++, 0xFF00FF00); //green for testing
	while (i < WINDOW_HEIGHT)
		//mlx_put_pixel(game->frame, x, i++, game->found_floor_rgb);
		mlx_put_pixel(game->frame, ray, i++, 0xFFFFFF00); //yellow for testing
}

static void draw_walls(t_game *game, float top, float bottom, int ray)
{
	int color;

	color = 0x0000FF; //later determine based direction, even later replace by textures
	while (top <= bottom)
	{
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
	
	black = 0xFF000000;
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

	wall_height = TILE_SIZE * WINDOW_HEIGHT / game->ray.length;
	wall_top = (WINDOW_HEIGHT / 2) - (wall_height / 2);
	if (wall_top < 0)
		wall_top = 0;
	wall_bottom = (WINDOW_HEIGHT / 2) + (wall_height / 2);
	if (wall_bottom > WINDOW_HEIGHT)
		wall_bottom = WINDOW_HEIGHT;
	draw_floor_ceiling(game, ray); // render earlier and save as a static image, since doesnt change
	draw_walls(game, wall_top, wall_bottom, ray); // here or somewhere else?
}
