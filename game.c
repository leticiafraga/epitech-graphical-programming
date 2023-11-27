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

static int move_target(target *t, sfIntRect *rect, int score)
{
    sfVector2f offset = {40 + score * 2, 0};
    sfFloatRect pos = sfSprite_getGlobalBounds(t->sprite);

    move_rect(rect, 110, 330);
    if (t->reverse)
        offset.x *= -1;
    sfSprite_move(t->sprite, offset);
    if ((!t->reverse && pos.left > 700)
        || (t->reverse && pos.left < 0)) {
            reinit_target(t);
            return 1;
    }
    return 0;
}

int handle_move(target *t, sfIntRect *rect, sfClock *clock, int score)
{
    sfTime time;
    sfSprite *sprite = t->sprite;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.2) {
        sfClock_restart(clock);
        if (move_target(t, rect, score))
            return 1;
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
        score += analyse_events(game, d);
        l->n -= handle_move(d, d->rect, game->clock, score);
    }
    sfRenderWindow_clear(game->window, sfBlue);
    destroy_life(l);
    sfText_destroy(text_score);
    return 3;
}
