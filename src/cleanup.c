/*
** EPITECH PROJECT, 2024
** cleanup
** File description:
** cleanup the sprites
*/
#include "../include/my_radar.h"

static void cleanup_planes(planes_t *planes)
{
    while (planes) {
        if (planes->sprite)
            sfSprite_destroy(planes->sprite);
        if (planes->hitbox)
            sfRectangleShape_destroy(planes->hitbox);
        planes = planes->next;
    }
}

void cleanup(sfRenderWindow *window, sprites_t *sprites, planes_t *planes)
{
    if (sprites->background)
        sfSprite_destroy(sprites->background);
    if (window)
        sfRenderWindow_destroy(window);
    cleanup_planes(planes);
}


// below old cleanup function outdated

//void cleanup(sfRenderWindow *window, sprites_t *sprites)
//{
//    if (sprites->background)
//        sfSprite_destroy(sprites->background);
//    if (sprites->plane_sprite)
//        sfSprite_destroy(sprites->plane_sprite);
//    if (sprites->tower_sprite)
//        sfSprite_destroy(sprites->tower_sprite);
//    if (window)
//        sfRenderWindow_destroy(window);
//}
