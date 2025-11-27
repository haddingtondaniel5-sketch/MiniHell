#include "../includes/minihell.h"


char **get_map(const char *map_filename)
{
	int fd = open(map_filename, O_RDONLY);
	u32 line_count = 1;
	char ch = 'A';

	while (read(fd, &ch, 1) > 0)
	{
		if (ch == '\n')
			line_count += 1;
	}
	if (lseek(fd, 0, SEEK_SET) == -1)
	{
		close(fd);
		return NULL;
	}

	char **map;
	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
	{
		close(fd);
		return NULL;
	}
	u32 i = 0;
	while (i < line_count)
	{
		map[i] = get_next_line(fd);
		i += 1;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void convert_render_to_collision(t_map *map)
{
	u32 y = 0;
	u32 x = 0;
	u32 line_count = 0;

	while (map->render_grid[line_count])
		line_count += 1;

	map->collision_grid = malloc(sizeof(char *) * (line_count + 1)); 	
	while (y < line_count)
	{
		x = 0;
		u32 row_width = strlen(map->render_grid[y]);
		map->collision_grid[y] = malloc(sizeof(char) * (row_width + 1));
		while (x < row_width)
		{
			if (map->render_grid[y][x] != '.' && map->render_grid[y][x] != '-' && map->render_grid[y][x] != '_')
				map->collision_grid[y][x] = 'C';
			else
				map->collision_grid[y][x] = '0';
			x += 1;
		}
		map->collision_grid[y][x] = '\0';
		y += 1;
	}
	map->collision_grid[y] = NULL;
}