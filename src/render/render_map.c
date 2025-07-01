#include "../../includes/cub3d.h"

int rgb_to_int(int r, int g, int b)
{
    return (r << 16 | g << 8 | b);
}
void put_pixel(t_game *game, int x, int y, int color)
{
	if (!game)
		return ;
	mlx_pixel_put(game->mlx, game->win, x, y, color);
}
void  calculate_ray_dir(t_game *game, int x) //Calculate ray direction for each screen column
{
	double 	x_dir;
	double 	y_dir;
	double 	camera_x;

	x_dir = 0;
	y_dir = 0;
	camera_x = 2 * x / (double)WIDTH - 1;
	x_dir = game->player.dir_x + game->player.plane_x * camera_x;
	y_dir = game->player.dir_y + game->player.plane_y * camera_x;
	game->ray_c.ray_dir_x = x_dir;
	game->ray_c.ray_dir_y = y_dir;
}

void take_player_position(t_game *game) // Find the player’s position in the map grid
{
	game->ray_c.map_x = (int)game->player.x;
	game->ray_c.map_y = (int)game->player.y;
}

void calculate_dist(t_game *game) // Calculate distances the ray must travel to cross x/y grid lines
{
	game->ray_c.delta_dist_x = fabs(1 / game->ray_c.ray_dir_x);
	game->ray_c.delta_dist_y = fabs(1 / game->ray_c.ray_dir_y);
}

void define_rey_step_and_dist(t_game *game) //Decide ray step direction and side distance
{
	if (game->ray_c.ray_dir_x < 0)
	{
		game->ray_c.step_x = -1;
		game->ray_c.side_dist_x = (game->player.x - game->ray_c.map_x) * game->ray_c.delta_dist_x;
	}
	else
	{
		game->ray_c.step_x = 1;
		game->ray_c.side_dist_x = (game->ray_c.map_x + 1.0 - game->player.x) * game->ray_c.delta_dist_x;
	}
	if (game->ray_c.ray_dir_y < 0)
	{
		game->ray_c.step_y = -1;
		game->ray_c.side_dist_y = (game->player.y - game->ray_c.map_y) * game->ray_c.delta_dist_y;
	}
	else
	{
		game->ray_c.step_y = 1;
		game->ray_c.side_dist_y = (game->ray_c.map_y + 1.0 - game->player.y) * game->ray_c.delta_dist_y;
	}
}

void analyze_pleyer_movement(t_game *game, int *hit) // DDA Loop: Traverse the grid. DDA = Digital Differential Analyzer
{
	while (!*hit)
	{
		if (game->ray_c.side_dist_x < game->ray_c.side_dist_y)
		{
			game->ray_c.side_dist_x += game->ray_c.delta_dist_x;
			game->ray_c.map_x += game->ray_c.step_x;
			game->ray_c.side = 0;
		}
		else
		{
			game->ray_c.side_dist_y += game->ray_c.delta_dist_y;
			game->ray_c.map_y += game->ray_c.step_y;
			game->ray_c.side = 1;
		}
		if (game->map[game->ray_c.map_y][game->ray_c.map_x] == '1')
			*hit = 1;
	}
}

void calculate_perp_wall_dist(t_game *game) //Calculate perpendicular wall distance
{
	int y;
	int x;

	if (game->ray_c.side == 0)
	{
		x = (game->ray_c.map_x - game->player.x + (1 - game->ray_c.step_x) / 2);
		game->ray_c.perp_wall_dist =  x / game->ray_c.ray_dir_x;
	}
	else
	{
		y = (game->ray_c.map_y - game->player.y + (1 - game->ray_c.step_y) / 2);
		game->ray_c.perp_wall_dist = y / game->ray_c.ray_dir_y;
	}
}

void calculate_wall_slice_height(t_game *game) //Calculate height of wall slice
{
	game->ray_c.line_height = (int)(HEIGHT / game->ray_c.perp_wall_dist);
	game->ray_c.draw_start = -game->ray_c.line_height / 2 + HEIGHT / 2;
	if (game->ray_c.draw_start < 0)
		game->ray_c.draw_start = 0;
	game->ray_c.draw_end = game->ray_c.line_height / 2 + HEIGHT / 2;
	if (game->ray_c.draw_end >= HEIGHT)
		game->ray_c.draw_end = HEIGHT - 1;
}

void select_texture(t_game *game) //Select texture index
{
	if (game->ray_c.side == 0)
	{
		if (game->ray_c.ray_dir_x > 0)
			game->ray_c.tex_index = 2;
		else	
			game->ray_c.tex_index = 3;
	}
	else
	{
		if (game->ray_c.ray_dir_x > 0)
			game->ray_c.tex_index = 1;
		else	
			game->ray_c.tex_index = 0;
	}
}

void get_texture_coord(t_game *game, t_textures *tex)//Get the texture coordinate (x)
{
	if (game->ray_c.side == 0)
	{
		game->ray_c.wall_x = game->player.y + game->ray_c.perp_wall_dist * game->ray_c.ray_dir_y;
	}else
	{
		game->ray_c.wall_x = game->player.x + game->ray_c.perp_wall_dist * game->ray_c.ray_dir_x;
	}
	game->ray_c.wall_x -= floor(game->ray_c.wall_x);
	game->ray_c.tex_x = (int)(game->ray_c.wall_x * tex->width);
	if ((game->ray_c.side == 0 && game->ray_c.ray_dir_x > 0) || (game->ray_c.side == 1 && game->ray_c.ray_dir_y < 0))
		game->ray_c.tex_x = tex->width - game->ray_c.tex_x - 1;
}

void draw_vertical_line(t_game *game, t_textures *tex, int x)
{
	int y;
	int d;
	int *color;
	int tex_y;

	y = 0;
	while (y < HEIGHT)
	{
		if (y < game->ray_c.draw_start)
		{
			color = game->ceiling_color;
			put_pixel(game, x, y, rgb_to_int(color[0], color[1], color[2]));
		}
		else if (y >= game->ray_c.draw_start && y <= game->ray_c.draw_end)
		{
			d = y * 256 - HEIGHT * 128 + game->ray_c.line_height * 128;
			tex_y = ((d * tex->height) / game->ray_c.line_height) / 256;
			mlx_pixel_put(game->mlx, game->win, x, y, tex->data[tex->width * tex_y + game->ray_c.tex_x]);
		}
		else
		{
			color = game->floor_color;
			put_pixel(game, x, y, rgb_to_int(color[0], color[1], color[2]));
		}
		y++;
	}
}

int	render_map(void *param)
{
	t_game *game = (t_game *)param;
	int x;
	int hit;
	t_textures *tex;

	x = 0;
	while (x < WIDTH)
	{
		hit = 0;
		calculate_ray_dir(game, x);
		take_player_position(game);
		define_rey_step_and_dist(game);
		analyze_pleyer_movement(game, &hit);
		calculate_perp_wall_dist(game);
		calculate_wall_slice_height(game);
		select_texture(game);
		tex = &game->textures[game->ray_c.tex_index];
		get_texture_coord(game, tex);
		draw_vertical_line(game, tex, x);
		x++;
	}
	return (0);
}
