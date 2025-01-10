/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** header file for my_radar project
*/
#ifndef MY_RADAR
    #define MY_RADAR
    #include "my.h"
    #include "common_lib.h"

typedef struct {
    sfSprite *background;
    sfSprite *plane_sprite;
    sfSprite *tower_sprite;
} sprites_t;

typedef struct planes_s {
    int departure_x;
    int departure_y;
    int arrival_x;
    int arrival_y;
    int speed;
    int delay;
    sfSprite *sprite;
    sfRectangleShape *hitbox;
    struct planes_s *next;
} planes_t;

typedef struct tower_s {
    int pos_x;
    int pos_y;
    int radius;
    sfSprite *sprite;
    sfCircleShape *area;
    struct tower_s *next;
} tower_t;

//window.c:
sfRenderWindow *create_window(void);
void handle_events(sfRenderWindow *window, int *hitboxes_visible);

//init_sprites:
sfSprite* create_sprite(const char *texture_file);
int setup_sprites(sfRenderWindow *window, sprites_t *sprites);
void draw_sprites(sfRenderWindow *window, sfSprite *background);
void draw_planes(sfRenderWindow *window, planes_t *planes,
    int hitboxes_visible);
void draw_towers(sfRenderWindow *window, tower_t *towers,
    int hitboxes_visible);

//validate_script.c:
int is_valid_integer(const char *str);
int validate_aircraft_line(char *line);
int validate_tower_line(char *line);
int validate_line(char *line);
int validate_script(const char *filename);

//extract_data.c:
void extract_data_from_script(const char *filename, planes_t **planes,
    tower_t **towers);

//planes.c:
void initialize_plane(planes_t *plane);
void update_plane_position(planes_t *plane, float delta_time);

//towers.c:
void initialize_tower(tower_t *tower);

//cleanup.c:
void cleanup(sfRenderWindow *window, sprites_t *sprites, planes_t *planes,
    tower_t *towers);

#endif /* MY_RADAR */
