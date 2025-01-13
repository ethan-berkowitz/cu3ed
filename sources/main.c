/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:07:19 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/10 17:37:24 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cu3ed.h"

static void	check_number_of_arguments(int n)
{
	if (n != 2)
		error_exit("Invalid number of arguments");	
}

static void	initialize_variables(t_main *main)
{
    main->map = NULL;
	main->file = NULL;
    main->path_to_north_texture = NULL;
	main->path_to_south_texture = NULL;
	main->path_to_west_texture = NULL;
	main->path_to_east_texture = NULL;
    main->floor_rgb = NULL;
	main->ceiling_rgb = NULL;
}

int	main(int argc, char *argv[])
{
	t_main main;

	initialize_variables(&main);
	check_number_of_arguments(argc);
	validate_filetype(argv[1]);
	create_copy_of_file(&main, argv[1]);
	parse_file(&main);
}
