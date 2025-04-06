//=================================================================
// The main program file.
//
// Copyright 2025 Georgia Tech.  All rights reserved.
// The materials provided by the instructor in this course are for
// the use of the students currently enrolled in the course.
// Copyrighted course materials may not be further disseminated.
// This file must not be made publicly available anywhere.
//==================================================================

// External libs
#include <cstdio>
#include <stdlib.h>

// Project Includes
#include "globals.h"
#include "hardware.h"
#include "mbed_retarget.h"
#include "snake.h"
#include "items.h"
#include "doubly_linked_list.h"

#define TICK_RATE 2


int main()
{

    printf("Initialization starting\n");
    GameInputs inputs;
    ASSERT_P(hardware_init() == ERROR_NONE, -1);
    
    Timer t;
    t.start();

    // This is the text that prints on the start screen
    uLCD.printf("Press any button to start.\n");

    uLCD.locate(0,3);
    uLCD.printf("hint: implement read_inputs().\n");

    // This loop is for the start screen
    // While the user has not provided an input, the game should remain on the start screen
    while(1){
        // 2035TODO
        // you need to implement read_inputs to get past the start screen!!
        inputs = read_inputs();
        if (inputs.up || inputs.down || inputs.right || inputs.left || inputs.center || inputs.b1 || inputs.b2 || inputs.b3) {
            srand(t.elapsed_time().count()); // this line sets the random seed
            break;
        }
    }

    uLCD.cls();

    // 2035TODO
    // initialize the Snake and the Items

    uLCD.baudrate(115200);
    
    int tick = 0;
    // 2035TODO
    // Implement the main game loop
    while(1)
    {

        wait_us(40000); // Recovery time

        // 1. draw the items and the snake

        // 2. print the score and the snake's 'boosted' value at the top of the screen
            // check out uLCD.locate() and uLCD.printf()
        

        // 3. check for collision -> if a GAME-ENDING collision occurs, end the game with a game over screen
            // self collision
            // item collision
            // wall colliison

        // 4. check if the snake's score >= 10 -> if so end the game with a game win screen
            // for 3 and 4, check out uLCD.cls()

        // 5. read the user inputs and update the snake direction if necessary

        // 6. move the snake (you might not want the snake to move every loop)

        
        tick++;
        t.reset();
    }

    printf("out of main loop\n");
    destroyList(get_snake()->snake_list);
    destroyList(get_items()->items_list);

    return 0;
}