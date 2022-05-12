/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** begin
*/

#include "move_main_char.h"
#include "rpg.h"
#include "map.h"
#include <SFML/Window/Keyboard.h>

int begin_game(scene_t *scene, screen_t *screen, game_t *game)
{
    static bool init_game = false;

    if (scene == NULL || screen == NULL || game == NULL)
        return 84;
    if (init_game == false) {
        if (initialize_map(game, scene) == 84 || !malloc_text(scene) ||
            create_sprites_peoples(scene, game) == 84 || !load_sprite(scene))
            return 84;
        init_game = true;
    }
    if (!mouve_player_in_map(scene, game, screen) ||
    display_map(scene, screen) != 0 || clock_particle(scene, screen, game))
        return 84;
    draw_sprites_peoples(scene, screen->window);
    create_move(scene, screen);
    check_fight_png(screen, scene, game);
    display_npc(scene, screen);
    return 0;
}
