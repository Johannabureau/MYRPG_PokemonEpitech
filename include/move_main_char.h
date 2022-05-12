/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** move_main_char
*/

#ifndef MOVE_MAIN_CHAR_H_
    #define MOVE_MAIN_CHAR_H_
    #define SPSET_TEXRECT(x, y) sfSprite_setTextureRect(x->sprite, y->rect)
    #define DRAW_SP_WIN(x) sfRenderWindow_drawSprite(win, x->sprite, NULL)
    #define DRAW_SP_MOVE(x) sfSprite_move(x->sprite, i->vtc);
    #define COLCK_ELAPSE(x) sfClock_getElapsedTime(x)
    #define SP_GIRL_LEFT "assets/sprite/main_char/girl/girl_l.png"
    #define SP_GIRL_RIGHT "assets/sprite/main_char/girl/girl_r.png"
    #define SP_GIRL_DOWN "assets/sprite/main_char/girl/girl_d.png"
    #define SP_GIRL_UP "assets/sprite/main_char/girl/girl_u.png"
    #define SP_GIRL_NO_LEFT "assets/sprite/main_char/girl/l_girl.png"
    #define SP_GIRL_NO_RIGHT "assets/sprite/main_char/girl/r_girl.png"
    #define SP_GIRL_NO_DOWN "assets/sprite/main_char/girl/d_girl.png"
    #define SP_GIRL_NO_UP "assets/sprite/main_char/girl/u_girl.png"
    #define SP_ASH_LEFT "assets/sprite/main_char/ash/ash_l.png"
    #define SP_ASH_RIGHT "assets/sprite/main_char/ash/ash_r.png"
    #define SP_ASH_DOWN "assets/sprite/main_char/ash/ash_d.png"
    #define SP_ASH_UP "assets/sprite/main_char/ash/ash_u.png"
    #define SP_ASH_NO_LEFT "assets/sprite/main_char/ash/l_ash.png"
    #define SP_ASH_NO_RIGHT "assets/sprite/main_char/ash/r_ash.png"
    #define SP_ASH_NO_DOWN "assets/sprite/main_char/ash/d_ash.png"
    #define SP_ASH_NO_UP "assets/sprite/main_char/ash/u_ash.png"
    #define SP_NPC_PALLET_1 "assets/sprite/char/pallet_town/p1.png"
    #define SP_NPC_PALLET_2 "assets/sprite/char/pallet_town/p2.png"
    #define SP_NPC_PALLET_3 "assets/sprite/char/pallet_town/oak.png"
    #define SP_NPC_PALLET_4 "assets/sprite/char/pallet_town/mom.png"
    #define SP_POKEBALL_PALLET "assets/sprite/char/pallet_town/pokeball.png"
    #define SP_TEXT_FRAME "assets/sprite/frame/frame_poke.png"
    #define SP_MENU_FRAME "assets/sprite/frame/menu_frame.png"
    #define SP_NCP_VILAIN_1 "assets/sprite/char/road/vilain1.png"
    #define SP_NCP_VILAIN_2 "assets/sprite/char/road/vilain2.png"
    #define SP_NCP_VILAIN_3 "assets/sprite/char/road/vilain3.png"
    #define SP_BOSS "assets/sprite/char/boss_npc/boss_npc.png"
    #define PIX_UPDATE(x, y) sfTexture_updateFromPixels(x, y, 400, 400, 0, 0)
    #define PIX_MOVE(x) sfSprite_move(x->sprite, i->vtc);
    #define INIT_NPC(rect, sp, x) init_object(rect, sp, NULL,\
    scene->object[2][x]);
    #define DRAW_TEXT(x) sfRenderWindow_drawText(screen->window, x, NULL);
    #define MOVE_TEXT(x) sfText_move(x->text, i->vtc);
    #include <stdlib.h>
    #include <SFML/Graphics.h>
    #include "rpg.h"

typedef struct screen_s screen_t;
typedef struct game_object_s game_object_t;
typedef struct scene_s scene_t;
typedef struct game_s game_t;
typedef struct framebuffer_s framebuffer_t;

void move_main_char_right(scene_t *i, screen_t *screen);
void no_move_main_char(scene_t *all, screen_t *screen);
int create_sprites_peoples(scene_t *all, game_t *game);
void event_mouve(screen_t *screen, scene_t *scene);

game_object_t *sprite_main_char_left(game_t *game);
game_object_t *sprites_main_char_right(game_t *game);
game_object_t *sprites_main_char_dow(game_t *game);
game_object_t *sprites_main_char_up(game_t *game);

game_object_t *sprite_main_char_no_walk_r(game_t *game);
game_object_t *sprite_main_char_no_walk_l(game_t *game);
game_object_t *sprite_main_char_no_walk_d(game_t *game);
game_object_t *sprite_main_char_no_walk_u(game_t *game);

void draw_sprites_peoples(scene_t *all, sfRenderWindow *win);
void create_move(scene_t *i, screen_t *screen);

void clock_left_right(scene_t *all);
void clock_down_up(scene_t *all);

bool load_sprite(scene_t *scene);
int display_npc(scene_t *scene, screen_t *screen);

int clock_particle(scene_t *scene, screen_t *screen, game_t *game);
void my_put_pixel(framebuffer_t *framebuffer, int x, int y, sfColor color);
framebuffer_t *make_smoke_fireplace(framebuffer_t *fb, int width, int height);
void talk_boss(game_object_t *obj);
void talk_arene(scene_t *scene, screen_t *screen);

#endif /* !MOVE_MAIN_CHAR_H_ */
