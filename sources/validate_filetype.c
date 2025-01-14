/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_filetype.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:15:06 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/14 09:36:54 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	validate_filetype(char *filename)
{
	while (*filename)
	{
		if (*filename == '.')
		{
			if (ft_strncmp(filename, ".cub", 5))
				error_exit("Invalid File: Invalid filetype");
		}
		filename++;
	}
}
