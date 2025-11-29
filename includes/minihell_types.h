#ifndef MINIHELL_TYPES_H
# define MINIHELL_TYPES_H

# include "minihell.h"

typedef unsigned int t_id;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef bool witch;

typedef enum {
	DIR_DOWN,
	DIR_RIGHT,
	DIR_UP,
	DIR_LEFT
} Direction;

typedef enum {
	MAP_TOWN_SERENITH,
	MAP_COUNT
} MapID;

typedef struct s_player {
	u32 x;
	u32 y;
	u32 move_cooldown;
	Direction direction;
	Texture2D texture_player_up;
	Texture2D texture_player_down;
	Texture2D texture_player_right;
	Texture2D texture_player_left;
	Texture2D texture_player_attack;
} t_player;

typedef struct s_map {
	const char *fname;
	char **render_grid;
	char **collision_grid;
	Texture2D texture_grass;
	Texture2D texture_wall;
	Texture2D texture_roundbush1;
	Texture2D texture_roundbush2;
	Texture2D texture_roundbush3;
	Texture2D texture_roundbush4;
} t_map;

typedef struct s_input {
	witch up, down, left, right;
	witch action, attack, menu;
} t_input;

typedef struct s_app {
	t_player player;
	t_map map[MAP_COUNT];
	t_id current_map;
	t_input input;
	Camera2D camera;

} t_app;

#endif