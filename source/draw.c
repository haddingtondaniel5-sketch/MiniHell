#include "../includes/minihell.h"



void draw_player(t_player *player)
{
	if (player->direction == DIR_UP)
		DrawTexture(player->texture_player_up, player->x * TILE_SIZE, player->y * TILE_SIZE, WHITE);
	if (player->direction == DIR_DOWN)
		DrawTexture(player->texture_player_down, player->x * TILE_SIZE, player->y * TILE_SIZE, WHITE);	
	if (player->direction == DIR_RIGHT)
		DrawTexture(player->texture_player_right, player->x * TILE_SIZE, player->y * TILE_SIZE, WHITE);	
	if (player->direction == DIR_LEFT)
		DrawTexture(player->texture_player_left, player->x * TILE_SIZE, player->y * TILE_SIZE, WHITE);
}

void draw_map(t_map *map)
{
	u32 x = 0;
	u32 y = 0;
	while (map->render_grid[y])
	{
		x = 0;
		u32 max_width = strlen(map->render_grid[y]);
		while (x < max_width)
		{
			Color color = LIGHTGRAY;
			Texture2D texture;
			switch (map->render_grid[y][x])
			{
				case '#': texture = map->texture_wall; color = RAYWHITE; break ;
				case 'T': texture = map->texture_roundbush1; color = DARKGREEN; break ;
				case 't': texture = map->texture_roundbush2; color = DARKGREEN; break ;
				case 'B': texture = map->texture_roundbush3; color = DARKGREEN; break ;
				case 'b': texture = map->texture_roundbush4; color = DARKGREEN; break ;
				case '.': texture = map->texture_grass; color = GREEN; break ;
			}
			DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, color);
			DrawTexture(texture, x * TILE_SIZE, y * TILE_SIZE, color);
			x += 1;
		}
		y += 1;
	}
}