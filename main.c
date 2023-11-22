/*
** EPITECH PROJECT, 2023
** CSFML
** File description:
** CSFML exp
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/hunter.h"

int handle_move(sfSprite *sprite, sfIntRect *rect, sfClock *clock, int score)
{
    sfTime time;
    sfVector2f offset = {30 + score, 0};
    sfFloatRect pos = sfSprite_getGlobalBounds(sprite);
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.2) {
        sfClock_restart(clock);
        move_rect(rect, 110, 330);
        sfSprite_move(sprite, offset);
        if (pos.left > 700) {
            init_sprite(sprite);
            return 1;
        }
    }
    return 0;
}

int handle_play(game_parts *game, int score)
{
    target *d = init_duck();
    sfFont *font = sfFont_createFromFile("arial.ttf");
    sfText *text_score = init_text(font);
    sfText *text_lives = init_text_lives(font);
    int lives = 3;

    while (sfRenderWindow_isOpen(game->window) && lives > 0) {
        lives -= handle_move(d->sprite, d->rect, game->clock, score);
        render(game, d);
        display_score(game->window, text_score, score);
        //display_lives(game->window, text_lives, lives);
        sfRenderWindow_display(game->window);
        score += analyse_events(game, d->sprite);
    }
    sfRenderWindow_clear(game->window, sfBlue);
    destroy_target(d);
    sfText_destroy(text_score);
    sfFont_destroy(font);
    return 0;
}

int handle_menu(game_parts *game)
{
    spr *menu = init_menu();
    int state = analyse_menu_events(game, menu);

    render_menu(game->window, menu);
    render_cursor(game, menu);
    sfRenderWindow_display(game->window);
    state = analyse_menu_events(game, menu);
    destroy_sprite(menu);
    return state;
}

static int validate_args(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        if (my_strcmp(av[i], "-h") == 0) {
            mini_printf("MY HUNTER\nUsage: ./my_hunter [OPTION]\n");
            mini_printf("Duck Hunt game.\n");
            mini_printf("With no OPTION, open game.\n");
            mini_printf("  -h \t\t Shows description and options\n");
            return 1;
        }
    }
    return 0;
}

static int start_game(void)
{
    game_parts *game = init_game();
    int score = 0;
    int state = 0;

    while (sfRenderWindow_isOpen(game->window)) {
        switch (state) {
            case 0:
                state = handle_menu(game);
                break;
            case 1:
                state = handle_play(game, score);
                break;
        }
    }
    destroy(game);
}

int main(int ac, char **av)
{
    if (validate_args(ac, av))
        return 0;
    else
        return start_game();
    return 0;
}
