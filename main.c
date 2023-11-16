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

int handle_play(game_parts *game, target *d, sfText *text, int score)
{
    handle_move(d->sprite, d->rect, game->clock, score);
    render(game->window, d);
    sfRenderWindow_drawText(
        game->window, display_score(text, score), NULL);
    sfRenderWindow_display(game->window);
    return analyse_events(game, d->sprite);
}

int handle_menu(game_parts *game, target *menu)
{
    render_menu(game->window, menu);
    sfRenderWindow_display(game->window);
    return analyse_menu_events(game, menu);
}

int main(void)
{
    game_parts *game = init_game();
    target *d = init_duck();
    target *menu = init_menu();
    sfText* text = init_text();
    int score = 0;
    int state = 0;

    while (sfRenderWindow_isOpen(game->window)) {
        switch (state) {
            case 0:
                state = handle_menu(game, menu);
                break;
            case 1:
                score += handle_play(game, d, text, score);
                break;
        }
    }
    destroy(game, d);
    return 0;
}
