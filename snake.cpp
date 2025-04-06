// ============================================
// The Snake class file
//
// Copyright 2025 Georgia Tech. All rights reserved.
// The materials provided by the instructor in this course are for
// the use of the students currently enrolled in the course.
// Copyrighted course materials may not be further disseminated.
// This file must NOT be made publicly available anywhere.
//==================================================================


#include "snake.h"
#include "doubly_linked_list.h"
#include "hardware.h"
#include <cstdlib>
#include <string>
#include <typeinfo>
#include "graphics.h"

Snake* snake;
DLinkedList* SnakeDLL = NULL;

// 2035TODO
// This function should initialize the Snake struct and populate its linked list with 10 SnakeItems.
void snake_init()
{

    snake =  malloc(sizeof(Snake));

    if (snake == NULL) { // safety check
        return;
    }

    // we are initializing the snake
    snake->score =  0;
    snake->direction = 0;
    snake->length = 3;
    snake->previous_tail_position = (point) {0, 0}; 


    // Take a look at snake.h to see how the Snake and SnakeItem structs work!
    for (int i = 0; i < snake->length; i++) {


    }
}

// 2035TODO
// This function updates the location of the SnakeItems in the Snake's DLL
void move_snake() {
    // Hint: you'll want to use previous_tail_position for this function

}

// 2035TODO
// This function should check if the Snake has collided with a wall, returns 1 on collision
// Note that the left and top of the uLCD are x=0 and y=0, respectively
// The right and bottom of the screen are SIZE_X/CELL_SIZE and SIZE_Y/CELL_SIZE, respectively
bool check_wall_collision() {

    return 0;
}


// 2035TODO
// This function should check if the Snake has collided with itself, returns 1 on collision
bool check_self_collision() {
    return 0;
}

// 2035TODO
// This function should increase the physical length of the Snake.
void grow_snake()
{
    
}

// 2035TODO
// This function should draw all the SnakeItems in the Snake linked list
void draw_snake(void) {
    
}

Snake* get_snake(void) {
    return snake;
}

point get_snake_head_location(void) {

    LLNode* head = SnakeDLL->head;
    return ((SnakeItem*)head->data)->position;
}


