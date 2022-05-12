/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** talk_boss
*/

#include "rpg.h"
#include "map.h"
#include "move_main_char.h"

void talk_boss(game_object_t *obj)
{
    char *res = "fight the boss to win the game !";

    obj->font = sfFont_createFromFile("assets/font/base_font.ttf");
    obj->text = sfText_create();
    sfText_setFont(obj->text, obj->font);
    sfText_setColor(obj->text, sfBlack);
    sfText_setCharacterSize(obj->text, 40);
    sfText_setPosition(obj->text, (sfVector2f){-160, 170});
    sfText_setString(obj->text, res);
    return;
}

void talk_arene(scene_t *scene, screen_t *screen)
{
    static bool has_talk = false;

    if (!scene || !screen)
        return;
    if (has_talk == false && scene->index == VIR_ARENE) {
        screen->scene_type = TEXT;
        scene->text = TEXT3;
        has_talk = true;
    }
    return;
}
