/*
** EPITECH PROJECT, 2023
** init
** File description:
** init
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/hunter.h"

static sfIntRect *display_rect_dim(int w, int h)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->top = 0;
    rect->left = 0;
    rect->width = w;
    rect->height = h;
    return rect;
}

static sfIntRect *display_rect(void)
{
    return display_rect_dim(110, 110);
}

game_parts *init_game(void)
{
    game_parts *game = malloc(sizeof(game_parts));
    sfVideoMode mode = {800, 600, 32};
    sfVector2f init_bg = {0, 0};

    game->clock = sfClock_create();
    game->window = sfRenderWindow_create(
        mode, "ducks", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 100);
    game->font = sfFont_createFromFile("arial.ttf");
    game->bg = malloc(sizeof(spr));
    game->bg->sprite = new_sprite();
    game->bg->texture = sfTexture_createFromFile("assets/bg.png", NULL);
    game->t = init_duck();
    sfSprite_setPosition(game->bg->sprite, init_bg);
    sfSprite_setTexture(game->bg->sprite, game->bg->texture, sfTrue);
    return game;
}

target *init_duck(void)
{
    return init_duck_img("assets/duck.png");
}

target *init_duck_img(const char *img)
{
    target *d = malloc(sizeof(target));

    d->rect = display_rect();
    d->texture = sfTexture_createFromFile(img, NULL);
    d->sprite = new_sprite();
    return d;
}

target **init_menu(void)
{
    target **menu = malloc(sizeof(spr *) * 2);
    sfVector2f init_sprite = {400 - 65, 300 - 55};

    for (int i = 0; i < 2; i++) {
        menu[i] = malloc(sizeof(spr));
        menu[i]->sprite = sfSprite_create();
        sfSprite_setPosition(menu[i]->sprite, init_sprite);
        init_sprite.y += 55;
    }
    menu[0]->texture = sfTexture_createFromFile("assets/start-btn.png", NULL);
    menu[1]->texture = sfTexture_createFromFile(
        "assets/options-btn.png", NULL);
    for (int i = 0; i < 2; i++) {
        sfSprite_setTexture(menu[i]->sprite, menu[i]->texture, sfTrue);
        menu[i]->rect = display_rect_dim(143, 44);
        sfSprite_setTextureRect(menu[i]->sprite, *(menu[i]->rect));
    }
    return menu;
}

spr *init_cursor(game_parts *game)
{
    spr *d = malloc(sizeof(spr));
    sfSprite *sprite = sfSprite_create();

    d->texture = sfTexture_createFromFile("assets/target.png", NULL);
    d->sprite = sprite;
    return d;
}
