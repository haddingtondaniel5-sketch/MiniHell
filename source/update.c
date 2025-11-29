# include "../includes/minihell.h"

void update_input(t_input *input)
{
	input->up    = IsKeyDown(KEY_UP);
	input->down  = IsKeyDown(KEY_DOWN);
	input->right = IsKeyDown(KEY_RIGHT);
	input->left  = IsKeyDown(KEY_LEFT);
	input->attack = IsKeyDown(KEY_SPACE);
}

void update_player(t_player *player, t_input *input, t_map *map)
{

	if (player->move_cooldown > 0)
	{
		player->move_cooldown--;
		return ;
	}
	if (input->up)
		player->direction = DIR_UP;
	if (input->down)
		player->direction = DIR_DOWN; 
	if (input->right) 
		player->direction = DIR_RIGHT;
	if (input->left)
		player->direction = DIR_LEFT;


	if (input->up && check_collision(map, player, DIR_UP, 0)) { 
		player->y -= 1; player->move_cooldown = MOVE_DELAY; player->direction = DIR_UP; 

	}
	if (input->down && check_collision(map, player, DIR_DOWN, 0)) {
		player->y += 1; player->move_cooldown = MOVE_DELAY;  player->direction = DIR_DOWN; 

	}
	if (input->right && check_collision(map, player, DIR_RIGHT, 0)) { 
		player->x += 1; player->move_cooldown = MOVE_DELAY;  player->direction = DIR_RIGHT; 

	}
	if (input->left && check_collision(map, player, DIR_LEFT, 0)) {
		player->x -= 1; player->move_cooldown = MOVE_DELAY;  player->direction = DIR_LEFT; 

	}
}

void update_camera(Camera2D *camera, t_player *player)
{
	camera->target = (Vector2){player->x * TILE_SIZE, player->y * TILE_SIZE};
}

void update_map(t_player *player, t_map *map)
{

	switch (player->direction)
	{
		case DIR_DOWN:
		if (map->render_grid[player->y + 1 + player->attack_point][player->x] != '#')
			map->render_grid[player->y + 1 + player->attack_point][player->x] = '.';
			break;
		case DIR_LEFT:
		if (map->render_grid[player->y][player->x - 1 - player->attack_point] != '#')
			map->render_grid[player->y][player->x - 1 - player->attack_point] = '.';
			break;
		case DIR_RIGHT:
		if (map->render_grid[player->y][player->x + 1 + player->attack_point] != '#')
			map->render_grid[player->y][player->x + 1 + player->attack_point] = '.';
			break;
		case DIR_UP:
		if (map->render_grid[player->y - 1 - player->attack_point][player->x] != '#')
			map->render_grid[player->y - 1 - player->attack_point][player->x] = '.';
			break;
	}
	convert_render_to_collision(map);
	player->attack_point = 0;
	
}