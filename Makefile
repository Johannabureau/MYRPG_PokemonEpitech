##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile antman
##

SRC	=	src/start_rpg.c \
		src/check_env.c \
		src/switch_pkm.c \
		src/int_to_char.c \
		src/scene/scene_handling.c \
		src/intro/load_intro.c \
		src/intro/begin_intro.c \
		src/intro/intro_handling.c \
		src/intro_game/init_inv.c \
		src/intro_game/init_game.c \
		src/intro_game/load_intro_g.c \
		src/intro_game/into_g_handling.c \
		src/intro_game/keybord_handling.c \
		src/intro_game/begin_intro_game.c \
		src/game/begin.c \
		src/game/npc/load_npc.c \
		src/game/map/free_map.c \
		src/game/npc/talk_boss.c \
		src/game/npc/check_fight.c \
		src/game/npc/display_npc.c \
		src/game/map/display_map.c \
		src/game/npc/heal_pokemon.c \
		src/game/map/load/load_map.c \
		src/game/map/move_map_spite.c \
		src/game/menu/ini/load_menu.c \
		src/game/menu/ini/init_text.c \
		src/game/menu/ini/init_menu.c \
		src/game/player/get_player_pos.c \
		src/game/menu/event/event_menu.c \
		src/game/player/move_player_up.c \
		src/game/map/change_map/oak_lab.c \
		src/game/menu/event/buttun_event.c \
		src/game/player/check_can_change.c \
		src/game/player/move_player_left.c \
		src/game/menu/ini/init_move_menu.c \
		src/game/player/move_player_down.c \
		src/game/menu/ini/init_stat_text.c \
		src/game/player/move_player_right.c \
		src/game/menu/display/option_menu.c \
		src/game/map/load/load_map_sprite.c \
		src/game/map/change_map/ash_hoose.c \
		src/game/menu/display/display_help.c \
		src/game/menu/display/display_menu.c \
		src/game/map/load/file_load_in_mem.c \
		src/game/map/change_map/change_map.c \
		src/game/menu/display/display_start.c \
		src/game/map/change_map/rival_hooose.c \
		src/game/map/load/init_move_map_spite.c \
		src/game/menu/display/display_pokemon.c \
		src/game/map/change_map/pokemon_center.c \
		src/game/menu/event/third_buttun_state.c \
		src/game/map/change_map/mart_pokememon.c \
		src/game/menu/display/display_poke_stat.c \
		src/game/map/change_map/change_ash_hose.c \
		src/game/map/change_map/viridian_hooses.c \
		src/game/move_char_main/main_char/draw_all.c \
		src/game/move_char_main/main_char/text_char.c \
		src/game/move_char_main/particles/rand_pixel.c \
		src/game/move_char_main/particles/load_particle.c \
		src/game/move_char_main/main_char/analyse_event.c \
		src/game/move_char_main/particles/clock_particle.c \
		src/game/move_char_main/main_char/move_main_char.c \
		src/game/move_char_main/main_char/sprites_peoples.c \
		src/game/move_char_main/main_char/clock_main_char.c \
		src/game/move_char_main/main_char/sprites_main_char.c \
		src/game/move_char_main/particles/create_framebuffer.c \
		src/fight/draw_fight.c \
		src/fight/load_fight.c \
		src/fight/begin_fight.c \
		src/fight/fight_handling.c \
		src/fight/check_efficacity_f.c \
		src/fight/choose_atk_f.c \
		src/fight/choose_option_f.c \
		src/fight/att_player.c \
		src/fight/parsing/read_file.c \
		src/fight/parsing/check_poke.c \
		src/fight/ai_enemy/begin_ai.c \
		src/fight/ai_enemy/single_pkm_strat.c \
		src/fight/ai_enemy/multiple_pkm_strat.c \
		src/general_function/screen_function/draw_sprite.c \
		src/general_function/screen_function/stop_screen.c	\
		src/general_function/destroy_function/destroy_all.c \
		src/general_function/destroy_function/destroy_scene.c \
		src/general_function/game_object/game_objet_creation.c \
		src/general_function/destroy_function/destroy_game_object.c \
		src/main.c

SRC_TEST	=	src/start_my_defender.c	\
				src/general_function/check_size_screen.c	\

OBJ	=	$(SRC:.c=.o)

SRC_TESTS	=	tests/test.c

OBJ_TESTS	=	$(SRC_TESTS:.c=.o)

NAME	=	my_rpg

NAME_T	=	unit_test

CFLAGS	=	-ggdb3 -Wall -Wextra

CPPFLAGS	=	-I./include/

CRITERIONS	=	-lcriterion --coverage -lgcov

GRAPHICS	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

LIB	=	lib/my/libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(CFLAGS) $(OBJ) $(CPPFLAGS) \
		$(GRAPHICS) $(LIB)

tests_run:
	rm -f $(OBJ)
	gcc -o $(NAME_T) $(SRC_TESTS) $(SRC_LS) $(CRITERIONS) $(LDFLAGS) $(LDLIBS)
	-./unit_test
	gcovr

clean:
	make clean -C lib/my
	rm -f $(OBJ) $(OBJ_TESTS)
	rm -f tests/*.gc*
	rm -f src/*.gc*
	rm -f *.gc*

fclean:	clean
	rm -f $(NAME)
	make fclean -C lib/my

re:	fclean all clean
