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

static int initialize_window_and_sprites(sfRenderWindow **window,
    sprites_t *sprites)
{
    *window = create_window();
    if (!*window) {
        my_put_error("failed to create window\n");
        return 84;
    }
    if (setup_sprites(*window, sprites)) {
        return 84;
    }
    return 0;
}

static void initialize_planes(planes_t *planes)
{
    planes_t *current_plane = planes;

    while (current_plane) {
        initialize_plane(current_plane);
        current_plane = current_plane->next;
    }
}

static void initialize_towers(tower_t *towers)
{
    tower_t *current_tower = towers;

    while (current_tower) {
        initialize_tower(current_tower);
        current_tower = current_tower->next;
    }
}

static int initialize_game_resources(const char *script, planes_t **planes,
    tower_t **towers, sfRenderWindow **window, sprites_t *sprites)
{
    if (validate_script(script) == 84) {
        my_put_error("invalid script file\n");
        return 84;
    }
    extract_data_from_script(script, planes, towers);
    if (initialize_window_and_sprites(window, sprites) == 84) {
        return 84;
    }
    initialize_planes(*planes);
    initialize_towers(*towers);
    return 0;
}

static void start_game_loop(sfRenderWindow *window, sprites_t *sprites,
    planes_t *planes, tower_t *towers)
{
    sfClock *clock = sfClock_create();
    int hitboxes_visible = 1;
    float delta_time;
    planes_t *current_plane;

    while (sfRenderWindow_isOpen(window)) {
        handle_events(window, &hitboxes_visible);
        delta_time = sfTime_asSeconds(sfClock_restart(clock));
        current_plane = planes;
        while (current_plane) {
            update_plane_position(current_plane, delta_time);
            current_plane = current_plane->next;
        }
        sfRenderWindow_clear(window, sfBlack);
        draw_sprites(window, sprites->background);
        draw_planes(window, planes, hitboxes_visible);
        draw_towers(window, towers, hitboxes_visible);
        sfRenderWindow_display(window);
    }
    sfClock_destroy(clock);
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
    if (initialize_game_resources(argv[1], &planes, &towers, &window,
        &sprites) == 84)
        return 84;
    start_game_loop(window, &sprites, planes, towers);
    cleanup(window, &sprites, planes, towers);
    return 0;
}
