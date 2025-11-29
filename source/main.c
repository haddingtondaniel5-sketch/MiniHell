
#include "../includes/minihell.h"


int main(void)
{
    InitWindow(WINDOW_X, WINDOW_Y, "MiniHell - An RPG (cough)");
    SetTargetFPS(60);
	t_app *app = malloc(sizeof(t_app));
	init_app(app);
	


    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
		update_input(&app->input);
		update_player(&app->player, &app->input, app->map);
		update_camera(&app->camera, &app->player);
		
		

		BeginMode2D(app->camera);
		draw_map(&app->map[app->current_map]);
		draw_player(&app->player);
		draw_player_attack(&app->player, &app->map[app->current_map]);

		update_map(&app->player, &app->map[app->current_map]);
		
		EndMode2D();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}