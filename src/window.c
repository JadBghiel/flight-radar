/*
** EPITECH PROJECT, 2024
** window
** File description:
** handle the window and event
*/
#include "../include/my_radar.h"

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "My Radar",
        sfResize | sfClose, NULL);

    if (window)
        sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

static void handle_close_event(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

static void toggle_visibility(int key_code, int *hitboxes_visible,
    int *sprites_visible)
{
    if (key_code == sfKeyL) {
        *hitboxes_visible = !(*hitboxes_visible);
    } else if (key_code == sfKeyS) {
        *sprites_visible = !(*sprites_visible);
    }
}

static void handle_key_pressed_event(sfEvent event, int *hitboxes_visible,
    int *sprites_visible)
{
    if (event.type == sfEvtKeyPressed) {
        toggle_visibility(event.key.code, hitboxes_visible, sprites_visible);
    }
}

void handle_events(sfRenderWindow *window, int *hitboxes_visible,
    int *sprites_visible)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        handle_close_event(window, event);
        handle_key_pressed_event(event, hitboxes_visible, sprites_visible);
    }
}
