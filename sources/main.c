/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:07:19 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/20 16:53:53 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_number_of_arguments(int n)
{
	if (n != 2)
		error_exit("Invalid number of arguments");	
}

static void	initialize_variables(t_game *game)
{
    game->map = NULL;
	game->file = NULL;
    game->path_to_north_texture = NULL;
	game->path_to_south_texture = NULL;
	game->path_to_west_texture = NULL;
	game->path_to_east_texture = NULL;
	game->floor_R = -1;
	game->floor_G = -1;
	game->floor_B = -1;
	game->ceiling_R = -1;
	game->ceiling_G = -1;
	game->ceiling_B = -1;
	game->found_floor_rgb = 0;
	game->found_ceiling_rgb = 0;
	game->mlx = NULL;
	game->floor_img = NULL;
	game->floor_texture = NULL;
	game->wall_img = NULL;
	game->wall_texture = NULL;
	game->width = TILE_SIZE * 20;
	game->height = TILE_SIZE * 10;
	game->image_size = TILE_SIZE;
	game->starting_direction = 0;
}

int	main(int argc, char *argv[])
{
	t_game game;

	//Init and parsing --------------------------------------------------------
	initialize_variables(&game);
	check_number_of_arguments(argc);
	validate_filetype(argv[1]);
	create_copy_of_file(&game, argv[1]);
	parse_file(&game);

	//MLX ---------------------------------------------------------------------
	// game.mlx = mlx_init(game.width, game.height, "cub3d", true);
	// if (!(game.mlx))
	// 	error_exit_and_free(&game, "MLX failed to initialize");
	// create_textures(&game);
	// create_images(&game);
	// resize_images(&game);
	// display_map(&game);
	// mlx_loop_hook(game.mlx, &controls, &game);
	// mlx_loop(game.mlx);
	free_all(&game);
	return (0);
}
