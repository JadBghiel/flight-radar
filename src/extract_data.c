/*
** EPITECH PROJECT, 2024
** extract_data
** File description:
** extract data from script
*/
#include "../include/my_radar.h"

static planes_t *create_plane(char **tokens)
{
    planes_t *plane = malloc(sizeof(planes_t));

    if (!plane)
        return NULL;
    plane->departure_x = my_atoi(tokens[0]);
    plane->departure_y = my_atoi(tokens[1]);
    plane->arrival_x = my_atoi(tokens[2]);
    plane->arrival_y = my_atoi(tokens[3]);
    plane->speed = my_atoi(tokens[4]);
    plane->delay = my_atoi(tokens[5]);
    plane->next = NULL;
    return plane;
}

static tower_t *create_tower(char **tokens)
{
    tower_t *tower = malloc(sizeof(tower_t));

    if (!tower)
        return NULL;
    tower->pos_x = my_atoi(tokens[0]);
    tower->pos_y = my_atoi(tokens[1]);
    tower->radius = my_atoi(tokens[2]);
    tower->next = NULL;
    return tower;
}

static void add_plane(planes_t **planes, planes_t *new_plane)
{
    if (!new_plane)
        return;
    new_plane->next = *planes;
    *planes = new_plane;
}

static void add_tower(tower_t **towers, tower_t *new_tower)
{
    if (!new_tower)
        return;
    new_tower->next = *towers;
    *towers = new_tower;
}

static void tokenize_line(char *copy, char *tokens[], int *count)
{
    *count = 0;
    tokens[*count] = my_strtok(copy, " \t");
    if (!tokens[*count]) {
        return;
    }
    (*count)++;
    tokens[*count] = my_strtok(NULL, " \t");
    while (tokens[*count] && *count < 6) {
        (*count)++;
        tokens[*count] = my_strtok(NULL, " \t");
    }
}

static void process_tokens(char *tokens[], int count, planes_t **planes,
    tower_t **towers)
{
    if (tokens[0][0] == 'A' && count == 6) {
        add_plane(planes, create_plane(tokens + 1));
    } else if (tokens[0][0] == 'T' && count == 4) {
        add_tower(towers, create_tower(tokens + 1));
    }
}

static void process_line_for_data(char *line, planes_t **planes,
    tower_t **towers)
{
    char *copy;
    char *tokens[6];
    int count;

    copy = my_strdup(line);
    if (!copy) {
        return;
    }
    tokenize_line(copy, tokens, &count);
    if (!tokens[0]) {
        free(copy);
        return;
    }
    process_tokens(tokens, count, planes, towers);
    free(copy);
}

void extract_data_from_script(const char *filename, planes_t **planes,
    tower_t **towers)
{
    FILE *file;
    char *line;
    size_t len;
    ssize_t read;

    file = fopen(filename, "r");
    line = NULL;
    len = 0;
    if (!file) {
        my_put_error("failed to open script file\n");
        return;
    }
    read = getline(&line, &len, file);
    while (read != -1) {
        process_line_for_data(line, planes, towers);
        read = getline(&line, &len, file);
    }
    free(line);
    fclose(file);
}
