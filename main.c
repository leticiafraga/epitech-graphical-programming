/*
** EPITECH PROJECT, 2023
** MY_HUNTER
** File description:
** MY_HUNTER
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

static int display_infos(
    sfRenderWindow *window, sfText *text_score, int score, life *l)
{
    display_score(window, text_score, score);
    display_lives(window, l);
}

int handle_play(game_parts *game)
{
    target *d = game->t;
    sfText *text_score = init_text(game->font);
    life *l = init_life(game->font);
    int score = 0;

    while (sfRenderWindow_isOpen(game->window) && l->n > 0) {
        render(game, d);
        display_infos(game->window, text_score, score, l);
        sfRenderWindow_display(game->window);
        score += analyse_events(game, d->sprite);
        l->n -= handle_move(d->sprite, d->rect, game->clock, score);
    }
    sfRenderWindow_clear(game->window, sfBlue);
    destroy_life(l);
    sfText_destroy(text_score);
    return 0;
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
    int state = 0;

    while (sfRenderWindow_isOpen(game->window)) {
        switch (state) {
            case 0:
                state = handle_menu(game);
                break;
            case 1:
                state = handle_play(game);
                break;
            case 2:
                state = handle_options(game);
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
}
