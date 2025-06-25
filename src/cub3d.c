#include "../includes/cub3d.h"

int main(int ac, char *av[])
{
    t_game game;

    (void)ac;
    if (ac != 2)
        return (printf("There are not right args!\n"), 1);
    
    read_map(&game, av);
    // check inputs map
    // init game
    // read map (&game, av)
    // validate map
    // init mlx
    // call action 
    return (0);
}