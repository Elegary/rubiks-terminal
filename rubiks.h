//
// Created by Senesys on 18/05/2021.
//

#ifndef RUBIKS_CUBE_RUBIKS_H
#define RUBIKS_CUBE_RUBIKS_H

typedef enum {FRONT=0, BACK=1, UP=2, DOWN=3, RIGHT=4, LEFT=5} T_SIDE;
typedef enum {R, B, G, W, Y, O, LG} T_COLOR;

typedef struct {
    T_COLOR color;
} Cell;

typedef struct {
    Cell data[3][3];
    T_SIDE side;
} Face;

// Functions for the enums types
// TODO: Change returned type

char select_color(T_COLOR color);
void change_text_color(T_COLOR color);
/*
 // Decided to not use this way
int side_to_index(T_SIDE side);
*/

// Funtions for the cube
void create_rubiks(Face **cube);

void init_rubiks(Face *cube);

void display_rubiks(Face *cube);
void display_line(Cell*);
void display_border_face(Cell*);

void blanck_rubiks(Face *cube);

//TODO
void fill_rubiks(Face *cube);
void scramble_rubiks(Face *cube);
void free_rubiks(Face *cube);

void reset_color();

#endif //RUBIKS_CUBE_RUBIKS_H
