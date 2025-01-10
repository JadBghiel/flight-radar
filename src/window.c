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

static void handle_event_logic(sfEvent event, sfRenderWindow *window,
    int *hitboxes_visible)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    } else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyL) {
        *hitboxes_visible = !(*hitboxes_visible);
    }
}

void handle_events(sfRenderWindow *window, int *hitboxes_visible)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        handle_event_logic(event, window, hitboxes_visible);
    }
}
