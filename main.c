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

sfIntRect *display_rect(void)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->top = 0;
    rect->left = 0;
    rect->width = 110;
    rect->height = 110;
    return rect;
}

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

game_parts *init_game(void)
{
    game_parts *game = malloc(sizeof(game_parts));
    sfVideoMode mode = {800, 600, 32};

    game->clock = sfClock_create();
    game->window = sfRenderWindow_create(
        mode, "ducks", sfDefaultStyle, NULL);
    return game;
}

int main(void)
{
    game_parts *game = init_game();
    sfIntRect *rect = display_rect();
    sfTexture *texture = sfTexture_createFromFile("assets/duck.png", NULL);
    sfSprite *sprite = new_sprite();
    sfText* text = init_text();
    int score = 0;

    while (sfRenderWindow_isOpen(game->window)) {
        handle_move(sprite, rect, game->clock, score);
        render(game->window, sprite, texture, rect);
        sfRenderWindow_drawText(
            game->window, display_score(text, score), NULL);
        sfRenderWindow_display(game->window);
        score += analyse_events(game->window, game->event, sprite);
    }
    destroy(sprite, texture, game->window, rect);
    return 0;
}
