//
// Created by Senesys on 18/05/2021.
//

#include <malloc.h>
#include <stdio.h>
#include "rubiks.h"
#include "conio.h"


// Functions for the enums types
// Decided to not use this function
/*
int side_to_index(T_SIDE side){

} */

// To associate faces and colors
T_COLOR colors[7] = {G, B, W, Y, R, O, LG};
// OLD WAY : char str_colors[6] = {'R', 'B', 'G', 'W', 'Y', 'O', 'LG'};
// NEW WAY: Ascii filled character makes it more easy to read and user friendly
char str_colors[7] = {((char)254u), ((char)254u), ((char)254u), ((char)254u), ((char)254u), ((char)254u), ((char)254u)};

char select_color(T_COLOR color){
    return str_colors[color];
}

void change_text_color(T_COLOR color){
    switch (color) {
        case R:
            c_textcolor(RED);
            break;
        case B:
            c_textcolor(BLUE);
            break;
        case G:
            c_textcolor(GREEN);
            break;
        case W:
            c_textcolor(WHITE);
            break;
        case Y:
            c_textcolor(YELLOW);
            break;
        case O:
            // Seems orange in terminal
            c_textcolor(BROWN);
            break;
        case LG:
            c_textcolor(DARKGRAY);
            break;
        default:
            c_textcolor(LIGHTGRAY);
            break;
    }
    
}

void reset_color(){
    c_textcolor(LIGHTGRAY);
}

void display_border_face(Cell* face){
    char long_space[] = "      ";
    for (int i = 0; i < 3; ++i) {
        printf("%s", long_space);
        display_line(&face[i]);
        printf("\n");
    }
}

void display_line(Cell* line){
    for (int i = 0; i < 3; ++i) {
        change_text_color(line[i].color);
        printf("%c ", str_colors[line[i].color]);
    }
}

void display_rubiks(Face *cube){
    display_border_face((Cell *) cube[UP].data);

    for (int i = 0; i < 3; ++i) {
        display_line(cube[LEFT].data[i]);
        display_line(cube[FRONT].data[i]);
        display_line(cube[RIGHT].data[i]);
        display_line(cube[BACK].data[i]);
        printf("\n");
    }

    display_border_face((Cell *) cube[DOWN].data);

    reset_color();
}




// Functions for the cube
//TODO: Dynamic allocation
void create_rubiks(Face **cube){
    *cube = (Face*) malloc(6 * sizeof(Face));
}

void init_rubiks(Face *cube){
    for (int face = FRONT; face <= LEFT; ++face) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cube[face].data[i][j].color = colors[face];
            }
        }
        cube[face].side = (T_SIDE) face;
    }
}

void blanck_rubiks(Face *cube){
    for (int face = FRONT; face <= LEFT; ++face) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cube[face].data[i][j].color = LG;
            }
        }
        cube[face].side = (T_SIDE) face;
    }
}

void free_rubiks(Face *cube){
    free(cube);
}

void fill_rubiks(Face *cube){
    int face, col, row, color;
    //TODO: check user input
    printf("\nPlease enter the face to be edited : ");
    scanf("%d", &face);
    printf("\nPlease enter the col : ");
    scanf("%d", &col);
    printf("\nPlease enter the row : ");
    scanf("%d", &row);
    printf("\nPlease enter the color : ");
    scanf("%d", &color);
    printf("\n");

    cube[face].data[col][row].color = color;

}