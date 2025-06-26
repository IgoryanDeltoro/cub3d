#include "../../includes/cub3d.h"

void draw_vertical_line(t_game *game, int x, int start, int end, int color)
{
    for (int y = start; y <= end; y++)
        mlx_pixel_put(game->mlx, game->win, x, y, color);
}

int	render_map(void *param)
{
    t_game *game = (t_game *)param;
	int x = 0;
	while (x < WIDTH)
	{
		double camera_x = 2 * x / (double)WIDTH - 1;
		double ray_dir_x = game->player.dir_x + game->player.plane_x * camera_x;
		double ray_dir_y = game->player.dir_y + game->player.plane_y * camera_x;

		int map_x = (int)game->player.x;
		int map_y = (int)game->player.y;

		double side_dist_x;
		double side_dist_y;

		double delta_dist_x = fabs(1 / ray_dir_x);
		double delta_dist_y = fabs(1 / ray_dir_y);
		double perp_wall_dist;

		int step_x;
		int step_y;

		int hit = 0;
		int side;

		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (game->player.x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - game->player.x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (game->player.y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - game->player.y) * delta_dist_y;
		}

		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (game->map[map_y][map_x] == '1')
				hit = 1;
		}

		if (side == 0)
			perp_wall_dist = (map_x - game->player.x + (1 - step_x) / 2) / ray_dir_x;
		else
			perp_wall_dist = (map_y - game->player.y + (1 - step_y) / 2) / ray_dir_y;

		int line_height = (int)(HEIGHT / perp_wall_dist);
		int draw_start = -line_height / 2 + HEIGHT / 2;
		if (draw_start < 0) draw_start = 0;
		int draw_end = line_height / 2 + HEIGHT / 2;
		if (draw_end >= HEIGHT) draw_end = HEIGHT - 1;

		// Pick color (you can replace with texture later)
		int color = (side == 1) ? 0xAAAAAA : 0xFFFFFF;

		int y = 0;
		while (y < HEIGHT)
		{
			if (y < draw_start)
				mlx_pixel_put(game->mlx, game->win, x, y, game->ceiling_color);
			else if (y > draw_end)
				mlx_pixel_put(game->mlx, game->win, x, y, game->floor_color);
			else
				mlx_pixel_put(game->mlx, game->win, x, y, color);
			y++;
		}
		x++;
	}
	return (0);
}