/*
** EPITECH PROJECT, 2024
** init_sprites
** File description:
** init the sprites
*/
#include "../../include/my_radar.h"

sfSprite* create_sprite(const char *texture_file)
{
    sfTexture *texture = sfTexture_createFromFile(texture_file, NULL);
    sfSprite *sprite;

    if (!texture) {
        my_put_error("failed to load texture\n");
    }
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

int setup_sprites(sfRenderWindow *window, sprites_t *sprites)
{
    sprites->background = create_sprite("rsrc/world_map.jpg");
    sprites->plane_sprite = create_sprite("rsrc/plane.png");
    sprites->tower_sprite = create_sprite("rsrc/tower.png");
    if (!sprites->background || !sprites->plane_sprite ||
        !sprites->tower_sprite) {
        my_put_error("failed to load one or more textures\n");
        return 1;
    }
    return 0;
}

void draw_sprites(sfRenderWindow *window, sfSprite *background)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, background, NULL);
}

void draw_planes(sfRenderWindow *window, planes_t *planes)
{
    while (planes) {
        sfRenderWindow_drawSprite(window, planes->sprite, NULL);
        sfRenderWindow_drawRectangleShape(window, planes->hitbox, NULL);
        planes = planes->next;
    }
}

void draw_towers(sfRenderWindow *window, tower_t *towers)
{
    while (towers) {
        sfRenderWindow_drawSprite(window, towers->sprite, NULL);
        sfRenderWindow_drawCircleShape(window, towers->area, NULL);
        towers = towers->next;
    }
}
