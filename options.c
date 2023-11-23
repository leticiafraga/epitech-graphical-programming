/*
** EPITECH PROJECT, 2023
** options
** File description:
** options
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/hunter.h"
#include "include/imgs.h"

static int handle_move_opt(target **opts, sfClock *clock)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.2) {
        sfClock_restart(clock);
        for (int i = 0; i < NUM_OPTS; i++) {
            move_rect(opts[i]->rect, 110, 330);
        }
    }
    return 0;
}

static void handle_cursor(game_parts *game, target **menu)
{
    spr cur;

    for (int i = 0; i < 2; i++) {
        cur.sprite = menu[i]->sprite;
        cur.texture = menu[i]->texture;
        if (render_cursor(game, &cur))
            break;
    }
}

static void render_opt(sfRenderWindow *window, target **menu)
{
    sfRenderWindow_clear(window, sfBlue);
    for (int i = 0; i < NUM_OPTS; i++) {
        sfSprite_setTexture(menu[i]->sprite, menu[i]->texture, sfTrue);
        sfSprite_setTextureRect(menu[i]->sprite, *(menu[i]->rect));
        sfRenderWindow_drawSprite(window, menu[i]->sprite, NULL);
    }
}

static target **init_opt(void)
{
    target **menu = malloc(sizeof(spr *) * NUM_OPTS);
    sfVector2f pos = {50, 100};

    for (int i = 0; i < NUM_OPTS; i ++) {
        menu[i] = init_duck_img(IMGS[i]);
        sfSprite_setPosition(menu[i]->sprite, pos);
        pos.x += 150;
    }
    return menu;
}

static int manage_opt_click(sfMouseButtonEvent event, target **menu)
{
    sfFloatRect pos;

    for (int i = 0; i < NUM_OPTS; i++) {
        pos = sfSprite_getGlobalBounds(menu[i]->sprite);
        if (sfFloatRect_contains(&pos, event.x, event.y) == sfTrue) {
            return i + 1;
        }
    }
    return 0;
}

static int analyse_opt_events(game_parts *game, target **menu)
{
    while (sfRenderWindow_pollEvent(game->window, &(game->event))) {
        if (game->event.type == sfEvtClosed)
            close_window(game->window);
        if (game->event.type == sfEvtMouseButtonPressed)
            return manage_opt_click(game->event.mouseButton, menu);
    }
    return 0;
}

int handle_options(game_parts *game)
{
    target **menu = init_opt();
    int chosen = 0;

    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    while (sfRenderWindow_isOpen(game->window) && !chosen) {
        render_opt(game->window, menu);
        handle_move_opt(menu, game->clock);
        sfRenderWindow_display(game->window);
        chosen = analyse_opt_events(game, menu);
    }
    sfTexture_destroy(game->t->texture);
    game->t->texture = sfTexture_createFromFile(IMGS[chosen - 1], NULL);
    for (int i = 0 ; i < NUM_OPTS; i++) {
        destroy_target(menu[i]);
    }
    free(menu);
    return 0;
}
