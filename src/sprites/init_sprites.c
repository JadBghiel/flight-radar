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

void draw_planes(sfRenderWindow *window, planes_t *planes,
    int hitboxes_visible, int sprites_visible)
{
    planes_t *current_plane = planes;

    while (current_plane) {
        if (sprites_visible) {
            sfRenderWindow_drawSprite(window, current_plane->sprite, NULL);
        }
        if (hitboxes_visible) {
            sfRenderWindow_drawRectangleShape(window, current_plane->hitbox,
                NULL);
        }
        current_plane = current_plane->next;
    }
}

void draw_towers(sfRenderWindow *window, tower_t *towers, int hitboxes_visible,
    int sprites_visible)
{
    tower_t *current_tower = towers;

    while (current_tower) {
        if (sprites_visible) {
            sfRenderWindow_drawSprite(window, current_tower->sprite, NULL);
        }
        if (hitboxes_visible) {
            sfRenderWindow_drawCircleShape(window, current_tower->area, NULL);
        }
        current_tower = current_tower->next;
    }
}
