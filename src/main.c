/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:31:03 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/10/13 02:08:23 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// #define ERR_MLX "Mlx: Startup error"
// #define ERR_MLX_WIN "Mlx: Window error"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (print_error(ERR_USAGE), 1);
	init_data(&data);
	if (parsing(&data, av) == FAILURE)
		return (free_data(&data), FAILURE);
	init_mlx(&data);
	init_textures(&data);
	render_images(&data);
	get_input(&data);
	mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_loop(data.mlx_ptr);
	return (free_data(&data), SUCCESS);
}
