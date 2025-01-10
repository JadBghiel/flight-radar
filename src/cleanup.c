/*
** EPITECH PROJECT, 2024
** cleanup
** File description:
** cleanup the sprites
*/
#include "../include/my_radar.h"

static void cleanup_planes(planes_t *planes)
{
    planes_t *next_plane;

    while (planes) {
        if (planes->sprite)
            sfSprite_destroy(planes->sprite);
        if (planes->hitbox)
            sfRectangleShape_destroy(planes->hitbox);
        next_plane = planes->next;
        free(planes);
        planes = next_plane;
    }
}

static void cleanup_towers(tower_t *towers)
{
    tower_t *next_tower;

    while (towers) {
        if (towers->sprite)
            sfSprite_destroy(towers->sprite);
        if (towers->area)
            sfCircleShape_destroy(towers->area);
        next_tower = towers->next;
        free(towers);
        towers = next_tower;
    }
}

void cleanup(sfRenderWindow *window, sprites_t *sprites, planes_t *planes,
    tower_t *towers)
{
    if (sprites->background)
        sfSprite_destroy(sprites->background);
    if (sprites->plane_sprite)
        sfSprite_destroy(sprites->plane_sprite);
    if (sprites->tower_sprite)
        sfSprite_destroy(sprites->tower_sprite);
    if (window)
        sfRenderWindow_destroy(window);
    cleanup_planes(planes);
    cleanup_towers(towers);
}
