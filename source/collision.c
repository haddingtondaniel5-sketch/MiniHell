#include "../includes/minihell.h"

witch check_collision(t_map *map, t_player *player, int direction)
{
	if (direction == DIR_UP)
	{
		if (map->collision_grid[player->y - 1][player->x] == 'C')
			return false; 
	}
	else if (direction == DIR_DOWN)
	{
		if (map->collision_grid[player->y + 1][player->x] == 'C')
			return false; 
	}
	else if (direction == DIR_LEFT)
	{
		if (map->collision_grid[player->y][player->x - 1] == 'C')
			return false; 
	}
	else if (direction == DIR_RIGHT)
	{
		if (map->collision_grid[player->y][player->x + 1] == 'C')
			return false; 
	}
	return true ;
}