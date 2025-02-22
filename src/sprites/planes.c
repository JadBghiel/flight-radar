/*
** EPITECH PROJECT, 2024
** planes
** File description:
** planes spirit
*/
#include "../../include/my_radar.h"

static sfSprite *create_plane_sprite(void)
{
    sfTexture *texture = sfTexture_createFromFile("rsrc/plane.png", NULL);
    sfSprite *sprite = sfSprite_create();

    if (!texture || !sprite)
        my_put_error("failed to load plane texture\n");
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

static sfRectangleShape *create_hitbox(void)
{
    sfRectangleShape *hitbox = sfRectangleShape_create();

    if (!hitbox)
        my_put_error("failed to load hitbox\n");
    sfRectangleShape_setSize(hitbox, (sfVector2f){20, 20});
    sfRectangleShape_setFillColor(hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(hitbox, sfRed);
    sfRectangleShape_setOutlineThickness(hitbox, 1);
    return hitbox;
}

void initialize_plane(planes_t *plane)
{
    plane->sprite = create_plane_sprite();
    plane->hitbox = create_hitbox();
    if (!plane->sprite || !plane->hitbox) {
        my_put_error("failed to init plane(s)\n");
        return;
    }
    sfSprite_setPosition(plane->sprite, (sfVector2f){plane->departure_x,
        plane->departure_y});
    sfRectangleShape_setPosition(plane->hitbox, (sfVector2f){
            plane->departure_x, plane->departure_y});
}

static sfVector2f calculate_new_position(sfVector2f pos, sfVector2f direction,
    float speed, float delta_time)
{
    pos.x += direction.x * speed * delta_time;
    pos.y += direction.y * speed * delta_time;
    return pos;
}

static void calculate_direction_and_distance(sfVector2f pos,
    sfVector2f arrival, sfVector2f *direction, float *total_distance)
{
    direction->x = arrival.x - pos.x;
    direction->y = arrival.y - pos.y;
    *total_distance = sqrtf(direction->x * direction->x + direction->y *
        direction->y);
}

void update_plane_position(planes_t *plane, float delta_time)
{
    static float elapsed_time = 0;
    sfVector2f pos;
    sfVector2f direction;
    float total_distance;

    if (elapsed_time < plane->delay) {
        elapsed_time += delta_time;
        return;
    }
    pos = sfSprite_getPosition(plane->sprite);
    calculate_direction_and_distance(pos, (sfVector2f){plane->arrival_x,
        plane->arrival_y}, &direction, &total_distance);
    if (total_distance < 1)
        return;
    direction.x /= total_distance;
    direction.y /= total_distance;
    pos = calculate_new_position(pos, direction, plane->speed, delta_time);
    sfSprite_setPosition(plane->sprite, pos);
    sfRectangleShape_setPosition(plane->hitbox, pos);
}

static void destroy_planes(planes_t *planes)
{
    while (planes) {
        sfSprite_destroy(planes->sprite);
        sfRectangleShape_destroy(planes->hitbox);
        planes = planes->next;
    }
}
