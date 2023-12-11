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
#include "include/radar.h"

int render_cursor_go(game_parts *game, target *d)
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

void render_go(game_parts *game, spr *bg, spr *title, target *ok)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, bg->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, title->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, ok->sprite, NULL);
}

target *init_ok_btn(void)
{
    target *menu = malloc(sizeof(spr));
    sfVector2f init_sprite = {400 - 65, 300};

    menu->sprite = sfSprite_create();
    sfSprite_setPosition(menu->sprite, init_sprite);
    init_sprite.y += 55;
    menu->texture = sfTexture_createFromFile("assets/ok.png", NULL);
    sfSprite_setTexture(menu->sprite, menu->texture, sfTrue);
    menu->rect = display_rect_dim(143, 44);
    sfSprite_setTextureRect(menu->sprite, *(menu->rect));
    return menu;
}

int handle_go(game_parts *game)
{
    int state = 3;
    spr *bg = init_basic_sprite("assets/lock-screen.png", 0, 0);
    spr *title = init_basic_sprite("assets/go.png", 400 - 250, 155);
    target *ok = init_ok_btn();

    while (sfRenderWindow_isOpen(game->window) && state != 0) {
        render_go(game, bg, title, ok);
        render_cursor_go(game, ok);
        sfRenderWindow_display(game->window);
        state = analyse_go_events(game, ok);
    }
    destroy_sprite(bg);
    return state;
}
