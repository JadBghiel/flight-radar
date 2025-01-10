/*
** EPITECH PROJECT, 2024
** towers
** File description:
** towers spirit
*/
#include "../../include/my_radar.h"

static sfSprite* create_tower_sprite(void)
{
    sfTexture *texture = sfTexture_createFromFile("rsrc/tower.png", NULL);
    sfSprite *sprite = sfSprite_create();

    if (!texture || !sprite) {
        my_put_error("failed to load tower texture\n");
    }
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

static sfCircleShape* create_tower_area(int radius)
{
    sfCircleShape *area = sfCircleShape_create();

    if (!area) {
        my_put_error("failed to create tower area\n");
    }
    sfCircleShape_setRadius(area, radius);
    sfCircleShape_setFillColor(area, sfTransparent);
    sfCircleShape_setOutlineColor(area, sfWhite);
    sfCircleShape_setOutlineThickness(area, 3);
    return area;
}

void initialize_tower(tower_t *tower)
{
    tower->sprite = create_tower_sprite();
    tower->area = create_tower_area(tower->radius);
    if (!tower->sprite || !tower->area) {
        my_put_error("failed to initialize tower\n");
        return;
    }
    sfSprite_setPosition(tower->sprite, (sfVector2f){tower->pos_x,
        tower->pos_y});
    sfCircleShape_setPosition(tower->area, (sfVector2f){tower->pos_x -
        tower->radius, tower->pos_y - tower->radius});
}
