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
        exit(84);
    }
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

void setup_sprites(sfRenderWindow *window, sprites_t *sprites)
{
    sprites->background = create_sprite("rsrc/world_map.jpg");
    sprites->plane_sprite = create_sprite("rsrc/plane.png");
    sprites->tower_sprite = create_sprite("rsrc/tower.png");
}

void draw_sprites(sfRenderWindow *window, sfSprite *background)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, background, NULL);
    sfRenderWindow_display(window);
}
