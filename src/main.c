/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/
#include "../include/my_radar.h"

void display_usage(void)
{
    my_putstr("Welcome to MY_RADAR, a flight radar simulator !\n");
    my_putstr("The program takes as input a script containing the information");
    my_putstr("about the entities, once executed it start automatically.\n");
    my_putstr("Planes move from their source to their destination,\n");
    my_putstr("If they collide with each other they crash, except if");
    my_putstr("they are within a control tower area\n");
    my_putstr("Press 'L' to toggle visibility of hitboxes and areas\n");
    my_putstr("Press 'S' to toggle visibility of entities's sprites\n");
}

void cleanup(sfRenderWindow *window, sprites_t *sprites)
{
    if (sprites->background)
        sfSprite_destroy(sprites->background);
    if (sprites->plane_sprite)
        sfSprite_destroy(sprites->plane_sprite);
    if (sprites->tower_sprite)
        sfSprite_destroy(sprites->tower_sprite);
    if (window)
        sfRenderWindow_destroy(window);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        my_put_error("usage: ./my_radar <script_file>\n");
        return 84;
    }
    if (my_strcmp(argv[1], "-h") == 0) {
        display_usage();
        return 0;
    }
    if (validate_script(argv[1]) == 84) {
        my_put_error("invalid script file\n");
        return 84;
    }
    sfRenderWindow *window = create_window();
    if (!window) {
        my_put_error("failed to create window\n");
        return 84;
    }
    sprites_t sprites = {0};
    setup_sprites(window, &sprites);
    while (sfRenderWindow_isOpen(window)) {
        handle_events(window);
        draw_sprites(window, sprites.background);
    }
    cleanup(window, &sprites);
    return 0;
}
