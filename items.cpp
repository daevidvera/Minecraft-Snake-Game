// ============================================
// The Items class file
//
// Copyright 2025 Georgia Tech. All rights reserved.
// The materials provided by the instructor in this course are for
// the use of the students currently enrolled in the course.
// Copyrighted course materials may not be further disseminated.
// This file must NOT be made publicly available anywhere.
//==================================================================



#include "items.h"
#include "snake.h"
#include "globals.h"
#include "graphics.h"
#include "doubly_linked_list.h"
#include <cstdlib>

Items* items;

// 2035TODO
// This function should initialize the Items struct and populate its linked list with 10 Item.
void items_init(void)
{
    // we first have to allocate the items 
    items = malloc(sizeof(Items));
    if (items == NULL) {
        return; 
    }
    

    // 
    // locations should be RANDOMLY GENERATED
    // locations should NOT overlap with other items or the snake
    for (int i = 0; i < NUM_ITEMS; i++) {
        
    }
}


// 2035TODO
// This function should check if the snake's head collides with any items and handle each possible collision accordingly
// Should return 1 for a GAME-ENDING collision, 0 otherwise
bool check_item_collision() {
    // If an item is eaten, it should be replaced at a new location

    return 0;
}

// 2035TODO
// This function should delete and replace an item that was eaten by the snake
void replace_item(LLNode* current_item) {

}

//2035TODO
// This function should draw all of the items in the Items linked list
// This should be VERY similar to the draw_snake() function
void draw_items(void) {
    
}

Items* get_items(void) {
    return items;
}