#include "../includes/minihell.h"

witch check_collision(t_map *map, t_player *player, u32 direction, u32 offset)
{
	if (direction == DIR_UP)
	{
		if (map->collision_grid[player->y - 1 - offset][player->x] == 'C')
			return false; 
	}
	else if (direction == DIR_DOWN)
	{
		if (map->collision_grid[player->y + 1 + offset][player->x] == 'C')
			return false; 
	}
	else if (direction == DIR_LEFT)
	{
		if (map->collision_grid[player->y][player->x - 1 - offset] == 'C')
			return false; 
	}
	else if (direction == DIR_RIGHT)
	{
		if (map->collision_grid[player->y][player->x + 1 + offset] == 'C')
			return false; 
	}
	return true ;
}