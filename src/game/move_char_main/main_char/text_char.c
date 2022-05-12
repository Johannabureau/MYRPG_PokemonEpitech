/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** text_char
*/

#include "rpg.h"
#include "move_main_char.h"

void talk_char_in_labo(game_object_t *obj)
{
    char *res = "choose your pokemon !\
    \n1:tortipouss (the best)\
    \n2:salameche\
    \n3:kaiminus";

    obj->font = sfFont_createFromFile("assets/font/base_font.ttf");
    obj->text = sfText_create();
    sfText_setFont(obj->text, obj->font);
    sfText_setColor(obj->text, sfBlack);
    sfText_setCharacterSize(obj->text, 40);
    sfText_setPosition(obj->text, (sfVector2f){-160, 170});
    sfText_setString(obj->text, res);
    return;
}

void talk_heal_poke(game_object_t *obj)
{
    char *res = "Yours pokemons has been healed";

    obj->font = sfFont_createFromFile("assets/font/base_font.ttf");
    obj->text = sfText_create();
    sfText_setFont(obj->text, obj->font);
    sfText_setColor(obj->text, sfBlack);
    sfText_setCharacterSize(obj->text, 40);
    sfText_setPosition(obj->text, (sfVector2f){-160, 170});
    sfText_setString(obj->text, res);
    return;
}

void warning_talk(game_object_t *obj)
{
    char *res = "go see prof in labo !!";

    obj->font = sfFont_createFromFile("assets/font/base_font.ttf");
    obj->text = sfText_create();
    sfText_setFont(obj->text, obj->font);
    sfText_setColor(obj->text, sfBlack);
    sfText_setCharacterSize(obj->text, 40);
    sfText_setPosition(obj->text, (sfVector2f){-160, 170});
    sfText_setString(obj->text, res);
    return;
}

bool malloc_text(scene_t *scene)
{
    scene->object[3] = malloc(sizeof(game_t *) * 10);
    if (scene->object[3] == NULL)
        return false;
    for (int i = 0; i < 9; i++) {
        scene->object[3][i] = malloc(sizeof(game_t));
        if (scene->object[3][i] == NULL)
            return false;
        scene->object[3][i]->sprite = NULL;
        scene->object[3][i]->music = NULL;
        scene->object[3][i]->clock = NULL;
        scene->object[3][i]->texture = NULL;
    }
    scene->object[4] = NULL;
    talk_char_in_labo(scene->object[3][0]);
    warning_talk(scene->object[3][1]);
    talk_boss(scene->object[3][2]);
    talk_heal_poke(scene->object[3][3]);
    return true;
}

int text_char(scene_t *scene, screen_t *screen)
{
    sfRenderWindow *win = screen->window;

    if (!scene || !screen || !scene->object[3])
        return 84;
    talk_arene(scene, screen);
    if (screen->scene_type == TEXT) {
        DRAW_SP_WIN(scene->object[2][3]);
        if (scene->text == TEXT1)
            DRAW_TEXT(scene->object[3][0]->text);
        if (scene->text == TEXT2)
            DRAW_TEXT(scene->object[3][1]->text);
        if (scene->text == TEXT3)
            DRAW_TEXT(scene->object[3][2]->text);
        if (scene->text == TEXT4)
            DRAW_TEXT(scene->object[3][3]->text);
    }
    return 0;
}
