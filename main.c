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

void handle_move(sfSprite *sprite, sfIntRect *rect, sfClock *clock, int score)
{
    sfTime time;
    sfVector2f offset = {10 + score, 0};
    sfFloatRect pos = sfSprite_getGlobalBounds(sprite);
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.2) {
        sfClock_restart(clock);
        move_rect(rect, 110, 330);
        sfSprite_move(sprite, offset);
        if (pos.left > 700)
            init_sprite(sprite);
    }
}

int main(void)
{
    game_parts *game = init_game();
    duck *d = init_duck();
    sfText* text = init_text();
    int score = 0;

    while (sfRenderWindow_isOpen(game->window)) {
        handle_move(d->sprite, d->rect, game->clock, score);
        render(game->window, d);
        sfRenderWindow_drawText(
            game->window, display_score(text, score), NULL);
        sfRenderWindow_display(game->window);
        score += analyse_events(game->window, game->event, d->sprite);
    }
    destroy(game, d);
    return 0;
}
