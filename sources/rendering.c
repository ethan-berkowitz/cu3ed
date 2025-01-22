/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:35:13 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/22 11:44:20 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void draw_pixel(t_game *game)
{
    float pixel_x = game->player.x + 10 * cos(game->player.angle_radian);
    float pixel_y = game->player.y + 10 * sin(game->player.angle_radian);
    int   color = 0xFF0000;
    mlx_put_pixel(game->minimap_img, pixel_x, pixel_y, color);
}

void rendering(void * content)
{
    t_game  *game;
    game =  (t_game *)content;
    bool     movement;

    movement = controls(game);
    if (movement == true)
    {
        //draw_pixel(game);
        raycasting(game);
        draw_line(game);
    }
}
