/*
** EPITECH PROJECT, 2022
** map.h
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_
    #include "rpg.h"

    #define MAP_PELLET_VIRIDIAN "assets/sprite/map/map_pellet_viridian"
    #define CHAMBRE_START "assets/sprite/map/chambre_start"
    #define R2_FOREST "assets/sprite/map/route_deux_forest"
    #define R2_PEWTER "assets/sprite/map/route_deux_pewter"
    #define SALON_RIVAL "assets/sprite/map/salon_rival"
    #define SALON_START "assets/sprite/map/salon_start"
    #define OAK_LAB "assets/sprite/map/prof_oak"
    #define ARENE_MAP "assets/sprite/map/arene_viridian"
    #define VIRIDIAN_FOREST "assets/sprite/map/viridian_forest"
    #define VIRIDIAN_HOOSE1 "assets/sprite/map/viridian_hoose1"
    #define VIRIDIAN_HOOSE2 "assets/sprite/map/viridian_hoose2"
    #define VIRIDIAN_MART "assets/sprite/map/viridian_mart"
    #define VIRIDIAN_PC_DOWN "assets/sprite/map/viridian_pc_down"
    #define VIRIDIAN_PC_UP "assets/sprite/map/viridian_pc_up"
    #define VIRIDIAN_PEWTER "assets/sprite/map/viridian_pewter"
    #define VIRIDIAN_ARENE "assets/sprite/map/arene_viridian.png"
    #define VIRIDIAN_HOUSE_SP "assets/sprite/map/virridian_house.png"
    #define PALLET_VIRIDIAN_SP "assets/sprite/map/Pallet_VIridian.png"
    #define PALLET_SP "assets/sprite/map/pallet.png"
    #define PALLET_VIRIDIAN_TOI_SP "assets/sprite/map/Pallet_VIridian_toit.png"
    #define START_FRAME_SP "assets/sprite/frame/start_frame.png"
    #define DRAW_SP_MAP(x) sfRenderWindow_drawSprite(screen->window,\
                                                            x->sprite, NULL)
    #define INIT_MAP(rect, sp, x) init_object(rect, sp, NULL, \
                                                        scene->object[0][x]);
    #define SET_COLOR(x) sfText_setFillColor(x, sfBlue)
    #define DRAW_TEXT(x) sfRenderWindow_drawText(screen->window, x, NULL);
    #define INIT_TXT(x, y, z) init_text(scene->object[1][x], y, z);

typedef enum pallet_viridian {
    MAP,
    START_HOUSE,
    RIVAL_HOUSE,
    LE_VIEUX_LA,
    POKEMON_CENTER,
    MART_POKEMON,
    VIRIDIAN_SCOOL,
    VIRIDIAN_HOOSE,
    ROAD2,
    CHAMBER_START,
    POKEMON_CENTER_UP,
    ARENE,
    END_ENUM = -1
} pallet_viridian_e;

typedef enum sprite_map {
    PALLET_VIRIDIAN,
    START_CHAMBER,
    START_SALON,
    RIVAL_SALON,
    OAK_LABORATORY,
    VIRIDIAN_1,
    VIRIDIAN_2,
    VIRIDIAN_3,
    VIRIDIAN_4,
    VIRIDIAN_5,
    VIR_ARENE,
    PALLET_VIRIDIAN_TOIT,
    NB_SPRITE,
} sprite_map_e;

enum menus_e {
    BASIC_MENU,
    OPTION_MENU,
    INV_MENU,
    HELP_MENU,
    START_MENU,
    WIN_MENU,
    LOOSE_MENU
};

typedef struct my_vector_s {
    int x;
    int y;
} my_vector_t;

int initialize_map(game_t *game, scene_t *scene);
int destroy_map(game_t *game);
bool load_sprite_map(scene_t *scene);
bool mouve_sprite_map(scene_t *scene);
int display_map(scene_t *scene, screen_t *screen);
bool mouve_player_in_map(scene_t *scene, game_t *game, screen_t *screen);
sfVector2i get_player_pos(game_t *game);
bool move_player_up(scene_t *scene, game_t *game, sfVector2i pos, screen_t *s);
bool move_player_right(scene_t *scene, game_t *gam, sfVector2i p, screen_t *s);
bool move_player_down(scene_t *scene, game_t *game, sfVector2i p, screen_t *s);
bool move_player_left(scene_t *scene, game_t *game, sfVector2i p, screen_t *s);
bool call_move_player(scene_t *scene, game_t *game, sfVector2i p, screen_t *s);
char **my_load_inmem_array(char *file);
bool change_map_hosse_ash(scene_t *scene, game_t *game, char ch);
bool change_to_ash_hoose(game_t *game, scene_t *scene);
bool from_upstair(scene_t *scene, game_t *game, char ch);
bool change_map(scene_t *scene, game_t *game, char ch);
bool change_to_oak(game_t *game, scene_t *scene);
bool change_from_oak(scene_t *scene, game_t *game, char ch);
bool change_to_rival(game_t *game, scene_t *scene);
bool change_from_rival(scene_t *scene, game_t *game, char ch);
bool change_pokemon_center(scene_t *scene, game_t *game, char ch);
bool change_to_pc_down(game_t *game, scene_t *scene);
bool from_pc_upstair(scene_t *scene, game_t *game, char ch);
bool check_pokemon(scene_t *scene, game_t *game, screen_t *screen);
bool change_from_mart(scene_t *scene, game_t *game, char ch);
bool change_to_mart(game_t *game, scene_t *scene);
bool change_to_pallet(scene_t *scene, game_t *game, char ch);
bool change_to_hose4(game_t *game, scene_t *scene);
bool change_to_hose3(game_t *game, scene_t *scene);
bool change_to_arene(game_t *game, scene_t *scene);
void check_menu_event(screen_t *screen, scene_t **scene);
bool init_menu(scene_t *scene);
bool init_pos(scene_t *scene);
int display_menu(screen_t *screen, scene_t **scene, game_t *game);
int load_menu(screen_t *screen, scene_t **scene, game_t *game);
int display_option(screen_t *screen, scene_t **scene, game_t *game);
int check_buttons_state(screen_t *screen, scene_t **scene);
bool init_all_text(scene_t *scene);
int display_start(screen_t *screen, scene_t **scene, game_t *game);
int check_menu_button(screen_t *screen, scene_t **scene);
int display_help(screen_t *screen, scene_t **scene, game_t *game);
int check_fight_png(screen_t *screen, scene_t *scene, game_t *game);
int display_pokemon_menu(screen_t *screen, scene_t **scene, game_t *game);
int init_stat_text(scene_t *scene);
int display_stat_poke(screen_t *screen, scene_t **scene, game_t *game);
int set_index_menu(int index);
int set_old_scene(int index);

#endif /* !MAP_H_ */
