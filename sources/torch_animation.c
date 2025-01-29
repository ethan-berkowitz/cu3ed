/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torch_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:33:42 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/29 13:29:35 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void torch_animation(t_game *game)
{
	game->frame_counter = (game->frame_counter + 1) % 33;
	ft_memcpy(game->torch_img->pixels, game->torch_animation_images[game->frame_counter / 6]->pixels, FLAME_SIZE * FLAME_SIZE * 4);
}
