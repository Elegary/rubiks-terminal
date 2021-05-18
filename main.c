#include <stdio.h>
#include "conio.h"
#include <windows.h>
#include "rubiks.h"

int main() {
    Face* cube;
    create_rubiks(&cube);
    init_rubiks(&cube);
    display_rubiks(&cube);
    //blanck_rubiks(&cube);
    //display_rubiks(&cube);
    fill_rubiks(&cube);
    display_rubiks(&cube);

   return 0;

}
