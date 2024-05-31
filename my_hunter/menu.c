/*
** EPITECH PROJECT, 2023
** menu
** File description:
** menu
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/hunter.h"

int render_cursor_menu(game_parts *game, target *d)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfFloatRect pos = sfSprite_getGlobalBounds(d->sprite);

    if (sfFloatRect_contains(&pos, mouse.x, mouse.y)) {
        position_rect(d->rect, 143);
        sfSprite_setTextureRect(d->sprite, *(d->rect));
        sfRenderWindow_drawSprite(game->window, d->sprite, NULL);
        set_cursor_target(game, mouse);
        return 1;
    }
    position_rect(d->rect, 0);
    sfSprite_setTextureRect(d->sprite, *(d->rect));
    sfRenderWindow_drawSprite(game->window, d->sprite, NULL);
    set_cursor_target(game, mouse);
    return 0;
}

static void handle_cursor(game_parts *game, target **menu)
{
    for (int i = 0; i < 2; i++) {
        if (render_cursor_menu(game, menu[i]))
            break;
    }
}

void render_menu(game_parts *game, target **menu, spr *bg, spr *title)
{
    sfRenderWindow_clear(game->window, sfBlue);
    sfRenderWindow_drawSprite(game->window, bg->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, title->sprite, NULL);
    for (int i = 0; i < 2; i++) {
        sfRenderWindow_drawSprite(game->window, menu[i]->sprite, NULL);
    }
}

int handle_menu(game_parts *game)
{
    target **menu = init_menu();
    int state = analyse_menu_events(game, menu);
    spr *bg = init_basic_sprite("assets/lock-screen.png", 0, 0);
    spr *title = init_basic_sprite("assets/logo.png", 400 - 250, 100);

    while (sfRenderWindow_isOpen(game->window) && state == 0) {
        render_menu(game, menu, bg, title);
        handle_cursor(game, menu);
        sfRenderWindow_display(game->window);
        state = analyse_menu_events(game, menu);
    }
    for (int i = 0; i < 2; i++)
        destroy_target(menu[i]);
    free(menu);
    destroy_sprite(bg);
    return state;
}
