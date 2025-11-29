# include "../includes/minihell.h"

void init_player(t_player *player)
{
	player->x = FIRSTMAP_X;
	player->y = FIRSTMAP_Y;
	player->move_cooldown = 0;
	player->direction = DIR_DOWN;
	player->texture_player_up = LoadTexture("0image/Fire Person_Up.png");
	player->texture_player_down = LoadTexture("0image/Fire Person_Down.png");
	player->texture_player_right = LoadTexture("0image/Fire Person_Right.png");
	player->texture_player_left = LoadTexture("0image/Fire Person_Left.png");
	player->texture_player_attack = LoadTexture("0image/Fireball.png");
}

void init_input(t_input *input)
{
	input->up = false;
	input->down = false;
	input->left = false;
	input->right = false;
	input->action = false;
	input->attack = false;
	input->menu = false;
}

void init_camera(Camera2D *camera, t_player *player)
{
	camera->target = (Vector2){player->x * TILE_SIZE, player->y * TILE_SIZE};
	camera->offset = (Vector2){WINDOW_X / 2, WINDOW_Y / 2};
	camera->rotation = 0.0f;
	camera->zoom = ZOOM_LEVEL;
}

void init_map(t_map *map, t_id map_id)
{
	map[map_id].render_grid = get_map(map[map_id].fname);
	print_list_2d(map[map_id].render_grid);
	convert_render_to_collision(&map[map_id]);
	map->texture_grass = LoadTexture("0image/grass.png");
	map->texture_wall = LoadTexture("0image/wall.png");
	map->texture_roundbush1 = LoadTexture("0image/Round Bush 1.png");
	map->texture_roundbush2 = LoadTexture("0image/Round Bush 2.png");
	map->texture_roundbush3 = LoadTexture("0image/Round Bush 3.png");
	map->texture_roundbush4 = LoadTexture("0image/Round Bush 4.png");

}

void init_app(t_app *app)
{
	app->map[MAP_TOWN_SERENITH].fname = strdup("maps/town_serenith.map");
	app->current_map = MAP_TOWN_SERENITH;
	init_map(app->map, app->current_map);
	init_player(&app->player);
	init_input(&app->input);
	init_camera(&app->camera, &app->player);

	



}

