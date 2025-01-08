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
    my_putstr("The program takes as input a script containing the informatio");
    my_putstr("n about the entities, once executed it start automatically.\n");
    my_putstr("Planes move from their source to their destination,\n");
    my_putstr("If they collide with each other they crash, except if");
    my_putstr("they are within a control tower area\n");
    my_putstr("Press 'L' to toggle visibility of hitboxes and areas\n");
    my_putstr("Press 'S' to toggle visibility of entities's sprites\n");
}

static int init_game(const char *script, planes_t **planes, tower_t **towers,
    sfRenderWindow **window, sprites_t *sprites)
{
    if (validate_script(script) == 84) {
        my_put_error("invalid script file\n");
        return 84;
    }
    extract_data_from_script(script, planes, towers);

    *window = create_window();
    if (!*window) {
        my_put_error("failed to create window\n");
        return 84;
    }
    setup_sprites(*window, sprites);
    
    planes_t *current_plane = *planes;
    while (current_plane) {
        initialize_plane(current_plane);
        current_plane = current_plane->next;
    }

    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(*window)) {
        handle_events(*window);
        
        float delta_time = sfTime_asSeconds(sfClock_restart(clock));

        current_plane = *planes;
        while (current_plane) {
            update_plane_position(current_plane, delta_time);
            current_plane = current_plane->next;
        }

        draw_sprites(*window, sprites->background);
        draw_planes(*window, *planes);
    }

    sfClock_destroy(clock);
    return 0;
}

int main(int argc, char **argv)
{
    planes_t *planes = NULL;
    tower_t *towers = NULL;
    sfRenderWindow *window = NULL;
    sprites_t sprites = {0};

    if (argc != 2) {
        my_put_error("usage: ./my_radar <script_file>\n");
        return 84;
    }
    if (my_strcmp(argv[1], "-h") == 0) {
        display_usage();
        return 0;
    }
    if (init_game(argv[1], &planes, &towers, &window, &sprites) == 84)
        return 84;

    cleanup(window, &sprites, planes);
    return 0;
}
