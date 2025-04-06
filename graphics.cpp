// ============================================
// The Graphics file
//
// Copyright 2025 Georgia Tech. All rights reserved.
// The materials provided by the instructor in this course are for
// the use of the students currently enrolled in the course.
// Copyrighted course materials may not be further disseminated.
// This file must NOT be made publicly available anywhere.
//==================================================================


#include "graphics.h"
#include "globals.h"


#define WHITE 0xFFFFFF
#define BLACK 0x000000
#define RED   0xFF0000
#define GREEN 0x00FF00
#define BLUE  0x0000FF
#define LGREY 0xBFBFBF
#define DGREY 0x5F5F5F
#define YELLOW 0xFFFF00
#define BROWN  0xD2691E
#define ORANGE 0xFFA500
#define PURPLE 0xA020F0
#define SKIN 0xFFE0B2 // light skin tone 
#define SHIRT 0x00CED1   // Steve’s shirt (turquoise)
#define PANTS 0x00008B   // Dark blue pants

#include <stdint.h>


// 2035TODO
// You should create your own sprite, but feel free to use this one while setting up your game!
const char* fruit_img =
    "PPPPPPPP"
    "PEWPWPEP"
    "PPPPPPPP"
    "PPDPDPPP"
    "PDDPPDPP"
    "PDPDPDPP"
    "PPPPPPPP"
    "PPPPPPPP"; // this is suppose to be a minecraft pig lol 

const char* poison_img = 
    "GGGGGGGG"
    "GDBGGD00"
    "GBBXDG0G"
    "GGXX0GGG"
    "DGXX0GGG"
    "DXXXDG00"
    "GDXGGXGG"
    "GGGGGGGG"; // creeper awww man


const char* boost_img = 
    "00BYYB00"  
    "0BYYYYB0"
    "BYYWYYYB"
    "BYYYYYYB"
    "BYYYYYYB"
    "0BYYYYB0"
    "00BYSB00"
    "000B0000";  // golden apple

const char* snake_head = 
    "HHHHHHHH"
    "HSSSSSSH"
    "HSEBBESH"
    "HSSSSSSH"
    "HSSSSSSH"
    "HSSSSSSH"
    "HSSSSSSH"
    "HHHHHHHH"; // steve


const char* snake_body =
    "00TTTT00"
    "0TTTTTT0"
    "TTSSTSTT"
    "TTTTTTTT"
    "0TPPPTT0"
    "0TPPPTT0"
    "00TTTT00"
    "00000000"; // steves body 


// This takes a location (x,y) and const char* as input, and prints a sprite onto the screen
void draw_img(int x, int y, const char* img) {
    int colors[CELL_SIZE*CELL_SIZE];
    for (int i = 0; i < CELL_SIZE*CELL_SIZE; i++)
    {
        switch(img[i]) {
            case 'R':
                colors[i] = RED;
                break;
            case 'Y':
                colors[i] = YELLOW;
                break;
            case 'B':
                colors[i] = BROWN;
                break;
            case 'G':
                colors[i] = GREEN;
                break;
            case '0':
                colors[i] = BLACK;
                break;
            case 'S':
                colors[i] = SKIN;
                break;
            case 'T':
                colors[i] = SHIRT; // steve shirt
                break;
            case 'P':
                colors[i] = PANTS; // steve pants
                break;
            case 'H':
                colors[i] = BROWN;  // steve hair
                break;
            case 'E':
                colors[i] = WHITE;  //  white eyes
                break;
            default:
                colors[i] = BLACK;
        }
    }
    uLCD.BLIT(x*CELL_SIZE, y*CELL_SIZE, CELL_SIZE, CELL_SIZE, colors);
    wait_us(250); // Recovery time!
}

// 2035TODO
void draw_fruit(int x, int y)
{
        
    draw_img(x, y, fruit_img); // drawing the fruit (minecraft pigs)

}

// 2035TODO
// the remainder of these functions should be handled the same way as draw_fruit
void draw_poison(int x, int y)
{
 draw_img(x, y, poison_img); // drawing the poision (creeper face)
}

void draw_boost(int x, int y)
{
    draw_img(x, y, boost_img); // drawing the boost (golden apple)
}


void draw_snake_body(int x, int y)
{
    draw_img( x,  y, snake_body); // drawing the body of steve D)
}

void draw_snake_head(int x, int y)
{
    draw_img(x,  y, snake_head); // drawing the head (steve)
}


void draw_nothing(int x, int y)
{

}
