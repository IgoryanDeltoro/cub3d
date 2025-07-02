// #include "../../includes/cub3d.h"

// int rgb_to_int(int r, int g, int b)
// {
//     return (r << 16 | g << 8 | b);
// }
// int	render_map(void *param)
// {
// 	t_game *game = (t_game *)param;
// 	int x = 0;

// 	while (x < WIDTH)
// 	{
// 		double camera_x = 2 * x / (double)WIDTH - 1;
// 		double ray_dir_x = game->player.dir_x + game->player.plane_x * camera_x;
// 		double ray_dir_y = game->player.dir_y + game->player.plane_y * camera_x;

// 		int map_x = (int)game->player.x;
// 		int map_y = (int)game->player.y;

// 		double delta_dist_x = fabs(1 / ray_dir_x);
// 		double delta_dist_y = fabs(1 / ray_dir_y);
// 		double side_dist_x, side_dist_y;
// 		int step_x, step_y, hit = 0, side;

// 		if (ray_dir_x < 0)
// 		{
// 			step_x = -1;
// 			side_dist_x = (game->player.x - map_x) * delta_dist_x;
// 		}
// 		else
// 		{
// 			step_x = 1;
// 			side_dist_x = (map_x + 1.0 - game->player.x) * delta_dist_x;
// 		}
// 		if (ray_dir_y < 0)
// 		{
// 			step_y = -1;
// 			side_dist_y = (game->player.y - map_y) * delta_dist_y;
// 		}
// 		else
// 		{
// 			step_y = 1;
// 			side_dist_y = (map_y + 1.0 - game->player.y) * delta_dist_y;
// 		}

// 		while (!hit)
// 		{
// 			if (side_dist_x < side_dist_y)
// 			{
// 				side_dist_x += delta_dist_x;
// 				map_x += step_x;
// 				side = 0;
// 			}
// 			else
// 			{
// 				side_dist_y += delta_dist_y;
// 				map_y += step_y;
// 				side = 1;
// 			}
// 			if (game->map[map_y][map_x] == '1')
// 				hit = 1;
// 		}

// 		double perp_wall_dist = (side == 0)
// 			? (map_x - game->player.x + (1 - step_x) / 2) / ray_dir_x
// 			: (map_y - game->player.y + (1 - step_y) / 2) / ray_dir_y;

// 		int line_height = (int)(HEIGHT / perp_wall_dist);
// 		int draw_start = -line_height / 2 + HEIGHT / 2;
// 		if (draw_start < 0) draw_start = 0;
// 		int draw_end = line_height / 2 + HEIGHT / 2;
// 		if (draw_end >= HEIGHT) draw_end = HEIGHT - 1;

// 		// Pick texture
// 		int tex_index = (side == 0)
// 			? (ray_dir_x > 0 ? 2 : 3)
// 			: (ray_dir_y > 0 ? 1 : 0);

// 		t_textures *tex = &game->textures[tex_index];

// 		// Calculate exact wall hit point
// 		double wall_x = (side == 0)
// 			? game->player.y + perp_wall_dist * ray_dir_y
// 			: game->player.x + perp_wall_dist * ray_dir_x;
// 		wall_x -= floor(wall_x);
// 		int tex_x = (int)(wall_x * tex->width);
// 		if ((side == 0 && ray_dir_x > 0) || (side == 1 && ray_dir_y < 0))
// 			tex_x = tex->width - tex_x - 1;

// 		// Draw the vertical stripe
// 		for (int y = 0; y < HEIGHT; y++)
// 		{
// 			int *f_color = game->floor_color;
// 			int *c_color = game->ceiling_color;

// 			if (y < draw_start)
// 				mlx_pixel_put(game->mlx, game->win, x, y, rgb_to_int(c_color[0], c_color[1], c_color[2]));
// 			else if (y >= draw_start && y <= draw_end)
// 			{
// 				int d = y * 256 - HEIGHT * 128 + line_height * 128;
// 				int tex_y = ((d * tex->height) / line_height) / 256;
// 				int color = tex->data[tex->width * tex_y + tex_x];
// 				mlx_pixel_put(game->mlx, game->win, x, y, color);
// 			}
// 			else
// 				mlx_pixel_put(game->mlx, game->win, x, y, rgb_to_int(f_color[0], f_color[1], f_color[2]));
// 		}

// 		x++;
// 	}
// 	return (0);
// }
