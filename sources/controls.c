/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:41:04 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/17 16:33:54 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	move_up(t_game *game)
{
	t_box	ghost_box;
	int		x;
	int		new_y;

	x = game->player.x;
	new_y = game->player.y - MOVE_SPEED;
	ghost_box = (t_box){x, new_y, MOVE_SIZE, MOVE_SIZE};
	if (!is_wall(game, ghost_box.x, ghost_box.y)
		&& !is_wall(game, ghost_box.x + MOVE_SIZE, ghost_box.y))
	{
		// game->player.x += (cos(game->player.angle_radian) * MOVE_SPEED);
		// game->player.y += (sin(game->player.angle_radian) * MOVE_SPEED);
		game->player.x += (sin(game->player.angle_radian) * MOVE_SPEED);
		game->player.y -= (cos(game->player.angle_radian) * MOVE_SPEED); //THESE DONT ALL MAKE SENSE, APPARENTLY COS OF THE DIFFERENCE BETWEEN 0 DEGREE IN MATH AND 0 DEGREE IN NAVIGATION
		game->player.player_img->instances[0].x = game->player.x;
		game->player.player_img->instances[0].y = game->player.y;
		return ;
	}
	else
		return ;
}

static void	move_down(t_game *game)
{
	t_box	ghost_box;
	int		x;
	int		new_y;

	x = game->player.x;
	new_y = game->player.y + MOVE_SPEED;
	ghost_box = (t_box){x, new_y, MOVE_SIZE, MOVE_SIZE};
	if (!is_wall(game, ghost_box.x, ghost_box.y + MOVE_SIZE)
		&& !is_wall(game, ghost_box.x + MOVE_SIZE, ghost_box.y + MOVE_SIZE))
	{
		// game->player.x -= (cos(game->player.angle_radian) * MOVE_SPEED);
		// game->player.y -= (sin(game->player.angle_radian) * MOVE_SPEED);
		game->player.x -= (sin(game->player.angle_radian) * MOVE_SPEED);
		game->player.y += (cos(game->player.angle_radian) * MOVE_SPEED);
		game->player.player_img->instances[0].x = game->player.x;
		game->player.player_img->instances[0].y = game->player.y;
		return ;
	}
	else
		return ;
}

static void	move_left(t_game *game)
{
	t_box	ghost_box;
	int		new_x;
	int		y;

	y = game->player.y;
	new_x = game->player.x - MOVE_SPEED;
	ghost_box = (t_box){new_x, y, MOVE_SIZE, MOVE_SIZE};
	if (!is_wall(game, ghost_box.x, ghost_box.y)
		&& !is_wall(game, ghost_box.x, ghost_box.y + MOVE_SIZE))
	{
		// game->player.x += (sin(game->player.angle_radian) * MOVE_SPEED);
		// game->player.y -= (cos(game->player.angle_radian) * MOVE_SPEED);
		game->player.x -= (cos(game->player.angle_radian) * MOVE_SPEED);
		game->player.y -= (sin(game->player.angle_radian) * MOVE_SPEED); 
		game->player.player_img->instances[0].x = game->player.x;
		game->player.player_img->instances[0].y = game->player.y;
	}
	else
		return ;
}

static void	move_right(t_game *game)
{
	t_box	ghost_box;
	int		new_x;
	int		y;

	y = game->player.y;
	new_x = game->player.x + MOVE_SPEED;
	ghost_box = (t_box){new_x, y, MOVE_SIZE, MOVE_SIZE};
	if (!is_wall(game, ghost_box.x + MOVE_SIZE, ghost_box.y)
		&& !is_wall(game, ghost_box.x + MOVE_SIZE, ghost_box.y + MOVE_SIZE))
	{
		// game->player.x -= (sin(game->player.angle_radian) * MOVE_SPEED);
		// game->player.y += (cos(game->player.angle_radian) * MOVE_SPEED);
		game->player.x += (cos(game->player.angle_radian) * MOVE_SPEED);
		game->player.y += (sin(game->player.angle_radian) * MOVE_SPEED);
		game->player.player_img->instances[0].x = game->player.x;
		game->player.player_img->instances[0].y = game->player.y;
		return ;
	}
	else
		return ;
}

static void	rotate_left(t_game *game)
{
	//game->ray.angle -= ROTATE_SPEED; //do this in raycasting.c
	game->player.angle_radian -= ROTATE_SPEED;
	if (game->player.angle_radian < 0)
		game->player.angle_radian += (2 * PI); // or += ???
	game->player.dx = cos(game->player.angle_radian); //* ROTATE_SPEED;
	game->player.dy = sin(game->player.angle_radian); //* ROTATE_SPEED;
	determine_ray_direction(game);
	return ;
}

static void	rotate_right(t_game *game)
{
	//game->ray.angle += ROTATE_SPEED; //determine this in raycasting.c
	game->player.angle_radian += ROTATE_SPEED;
	if (game->player.angle_radian > (2 * PI))
		game->player.angle_radian -= (2 * PI); // or += 2 * PI???
	game->player.dx = cos(game->player.angle_radian);// * ROTATE_SPEED;
	game->player.dy = sin(game->player.angle_radian);// * ROTATE_SPEED;
	determine_ray_direction(game);
	return ;
}

void	controls(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		free_all(game);
		exit (EXIT_SUCCESS);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_up(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_down(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_right(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_right(game);
}
