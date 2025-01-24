/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:35:13 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/24 09:13:23 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    rendering(void * content)
{
    t_game  *game;
    game =  (t_game *)content;
    bool     movement;

    movement = controls(game);
    if (movement == true)
    {
        clear_line(game);
        raycasting(game);
        //draw_line(game);
    }
}
