/*
** EPITECH PROJECT, 2022
** include
** File description:
** my
*/

#ifndef include_m
    #define include_m
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>
    #include "move_main_char.h"

enum text_e {
    TEXT1,
    TEXT2,
    TEXT3,
    TEXT4,
};

enum move_e {
    LEFT,
    RIGHT, DOWN, UP,
    NO_MOVE_RIGHT,
    NO_MOVE_LEFT,
    NO_MOVE_DOWN,
    NO_MOVE_UP,
};

enum fight {
    FI_CHOICE,
    FI_ATK,
    FI_BAG,
    FI_POKEMON,
    FI_RUN
};

typedef enum type_s {
    NORMAL = 0,
    FIGHTING = 1,
    FLYING = 2,
    POISON = 3,
    GROUND = 4,
    ROCK = 5,
    BUG = 6,
    GHOST = 7,
    STEEL = 8,
    FIRE = 9,
    WATER = 10,
    GRASS = 11,
    ELECTRIC = 12,
    PSY = 13,
    ICE = 14,
    DARK = 15,
    NONE
} type_t;

enum {
    INTRO = 0,
    START_G = 1,
    GAME = 2,
    FIGHT = 3,
    START = 4,
    TEXT = 5,
    MENU = 6,
    NB_SCENE = 7
};

enum stat_t {
    S_PDV = 0,
    S_ATK = 1,
    S_DEF = 2,
    S_SPEATK = 3,
    S_SPEDEF = 4,
    S_SPEED = 5
};

enum menu_idle_e {
    TO_CANCEL,
    TO_OPTION,
    TO_INV,
    TO_MENU,
    TO_QUIT,
    TO_NEW,
    TO_HELP,
    TO_QUIT2,
    TO_START,
    TO_NOWERE,
};

typedef enum intro_s {
    INTRO_1 = 0,
    INTRO_2 = 1
} intro_t;

typedef enum intro_g_s {
    INTRO_G_NAME = 0,
    INTRO_G_GENDER = 1,
    INTRO_G2 = 2
} intro_g_t;

typedef struct framebuffer_s {
    unsigned int width;
    unsigned int height;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2i center;
    sfVector2i center2;
    sfVector2i count1;
    sfVector2i count2;
    sfUint8 *pixels;
} framebuffer_t;

typedef struct atk_s {
    char *name;
    int type;
    int dmg;
    sfText *text;
    sfFont *font;
} atk_t;

typedef struct pokemon_s {
    char *name;
    int index;
    int pdv;
    int f_stat[6];
    int stat_level[6];
    int stat[6];
    int lv;
    char *object;
    int xp;
    type_t type[2];
    atk_t atk[4];
    sfText *text[4];
    sfFont *font;
    sfTexture *texture;
    sfSprite *sprite;
} pokemon_t;

typedef struct obj_s {
    char *name;
    int nb;
} obj_t;

typedef struct inv_s {
    obj_t pokeball[4];
    obj_t ct[4];
    obj_t special[4];
} inv_t;

typedef struct start_s {
    pokemon_t pokemon_inv[6];
    pokemon_t pokemon_box[30];
    int money;
    inv_t *inv;
    char *player_name;
    int nb_badges;
} start_t;

typedef struct game_s {
    int index;
    char ***map;
    start_t *start;
    char *player_sprite;
    bool is_a_boy;
    bool as_a_pokemon;
    bool your_turn;
    sfVector2i player_pos;
    sfVector2i player_start;
    pokemon_t enemy[6];
} game_t;

typedef struct screen_s {
    sfEvent event;
    sfView *view;
    float scaling_x;
    float scaling_y;
    sfVideoMode mode;
    sfRenderWindow *window;
    int scene_type;
    sfClock *clock;
    sfTime time;
    framebuffer_t *fb;
    framebuffer_t *fb_smoke;
} screen_t;

typedef struct game_object_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock;
    sfMusic *music;
    sfTime time;
    sfIntRect rect;
    sfText *text;
    sfFont *font;
    int left;
    int top;
} game_object_t;

typedef struct scene_s {
    game_object_t ***object;
    sfMusic *music;
    sfClock *clock;
    sfTime time;
    bool is_initialized;
    bool is_music_stop;
    bool choose[3];
    enum move_e move;
    int index;
    int old;
    enum menu_idle_e menu_index;
    enum text_e text;
    sfVector2f vtc;
} scene_t;

typedef struct map_params_s {
    int row;
    int col;
    int tmp;
    int scale;
} map_params_t;

int check_env(char **env);
int begin_rpg(char *filepath);
int load_intro(scene_t *scene);
int begin_intro(scene_t *scene, screen_t *screen);
int intro_handling(scene_t *scene, screen_t *screen);
int scene_handling(scene_t **scene, screen_t *screen, game_t *game);
int init_object(sfIntRect rect, char *sprite_path, char *song
        ,game_object_t *object);
void draw_sprite(sfSprite *sprite, screen_t *screen);
void stop_my_rpg(screen_t *screen);
int intro_1_handling(scene_t *scene, screen_t *screen);
int begin_game(scene_t *scene, screen_t *screen, game_t *game);
void destroy_all(scene_t **scene, screen_t *screen, game_t *game);
void destroy_game_object(game_object_t *object);
void destroy_scene(scene_t *scene);
int load_intro_g(scene_t *scene, game_t *game);
int init_game(game_t *game);
int init_inv(inv_t *inv);
int begin_intro_game(scene_t *scene, screen_t *screen, game_t *game);
int intro_g_handling(scene_t *scene, game_t *game, screen_t *screen);
int key_handling(scene_t *scene, screen_t *screen, game_t *game, int *state);
int begin_fight(scene_t *scene, screen_t *screen, game_t *game);
int load_fight(scene_t *scene);
int fight_handling
(scene_t *scene, game_t *game, screen_t *screen);
int draw_fight(scene_t *scene, game_t *game, screen_t *screen);
framebuffer_t *rand_pixel(framebuffer_t *fb, int width, int height);
framebuffer_t *clear_frame(framebuffer_t *fb);
int load_particle(screen_t *screen, scene_t *scene, game_t *game);
bool check_type(pokemon_t *pokemon, char *type);
int check_atk(pokemon_t *pokemon, char **atks);
int read_poke_dir(pokemon_t *pokemon, char *filename);
void check_png_talk(screen_t *screen, scene_t *scene);
int text_char(scene_t *scene, screen_t *screen);
int choose_option_f(game_t *game, scene_t *scene, screen_t *screen,
        int *status);
bool change_to_pallet_bis(scene_t *scene, game_t *game, char ch);
bool malloc_text(scene_t *scene);
int choose_atk_f(game_t *game, scene_t *scene, screen_t *screen, int *status);
int choose_option_f
(game_t *game, scene_t *scene, screen_t *screen, int *status);
int multiple_pkm_strat(game_t *game);
int single_pkm_strat(game_t *game);
int switch_pkm(pokemon_t *pokemon_1, pokemon_t *pokemon_2);
bool check_efficacity_f(int def, int atk);
int begin_ai(game_t *game);
int multiple_pkm_strat(game_t *game);
int single_pkm_strat(game_t *game);
char *my_int_to_str(unsigned int nb);
int atk_player(game_t *game, atk_t *atk);
int init_framebuffer(screen_t *screen);
int display_end_menu(screen_t *screen, scene_t **scene, game_t *game);
int is_the_boss_fight(int index);
int end_fight(scene_t *scene, game_t *game, screen_t *screen, bool good_end);
int check_heal_pokemon(screen_t *screen, scene_t *scene, game_t *game);

#endif /* include_m */
