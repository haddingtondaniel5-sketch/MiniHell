#ifndef MINIHELL_FUNCTIONS_H
# define MINIHELL_FUNCTIONS_H

# include "minihell_types.h"

// collision.c
witch check_collision(t_map *map, t_player *player, u32 direction, u32 offset);

// draw.c
void draw_map(t_map *map);
void draw_player(t_player *player);
void draw_player_attack(t_player *player, t_map *map);

// init.c
void init_map(t_map *map, t_id map_id);
void init_player(t_player *player);
void init_input(t_input *input);
void init_camera(Camera2D *camera, t_player *player);
void init_app(t_app *app);

// map.c
char **get_map(const char *map_filename);
void convert_render_to_collision(t_map *map);

// update.c
void update_input(t_input *input);
void update_player(t_player *player, t_input *input, t_map *map);
void update_camera(Camera2D *camera, t_player *player);


// utils.c
void print_list_2d(char **list);
u32	 numlen(int n);
char *itoa(int n);
char *strjoin_e(unsigned int c, ...);
char *get_next_line(int fd);

#endif