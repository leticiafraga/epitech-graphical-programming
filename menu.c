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
        if (d->rect->left != 143) {
            position_rect(d->rect, 143);
            sfSprite_setTextureRect(d->sprite, *(d->rect));
            sfRenderWindow_drawSprite(game->window, d->sprite, NULL);
        }
        set_cursor_target(game, mouse);
        return 1;
    }
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

void render_menu(sfRenderWindow *window, target **menu)
{
    sfRenderWindow_clear(window, sfBlue);
    for (int i = 0; i < 2; i++) {
        sfRenderWindow_drawSprite(window, menu[i]->sprite, NULL);
    }
}

int handle_menu(game_parts *game)
{
    target **menu = init_menu();
    int state = analyse_menu_events(game, menu);

    render_menu(game->window, menu);
    sfSprite_setTexture(menu[0]->sprite, menu[0]->texture, sfTrue);
    sfSprite_setTextureRect(menu[0]->sprite, *(menu[0]->rect));
    sfRenderWindow_drawSprite(game->window, menu[0]->sprite, NULL);
    handle_cursor(game, menu);
    sfRenderWindow_display(game->window);
    state = analyse_menu_events(game, menu);
    for (int i = 0; i < 2; i++)
        destroy_target(menu[i]);
    return state;
}
