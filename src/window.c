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

void handle_events(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}
