//=================================================================
// Implementation for DLL module.
//
// Copyright 2025 Georgia Tech.  All rights reserved.
// The materials provided by the instructor in this course are for
// the use of the students currently enrolled in the course.
// Copyrighted course materials may not be further disseminated.
// This file must not be made publicly available anywhere.
//=================================================================
#include <stdlib.h>
#include <stdio.h>
#include "doubly_linked_list.h"

LLNode* create_llnode(void* data) {

    LLNode* newNode  = (LLNode*)malloc(sizeof(LLNode)); // allocating space for the new node
    if (newNode != NULL) {
      newNode->next = NULL; // initializing next
      newNode->prev = NULL; // initializing prev
      newNode->data = data; // we set the data 
    }

     return newNode; 
}

DLinkedList* create_dlinkedlist(void) {
    DLinkedList* newList = (DLinkedList*)malloc(sizeof(DLinkedList));
    newList->head = NULL;
    newList->tail = NULL;
    newList->size = 0;
    return newList;
}

int getSize(DLinkedList* dLinkedList){
  if (dLinkedList == NULL) {
    return 0;
  }
  int size = dLinkedList->size;
  return size; // we get the size of the double linked list 
}

LLNode* getHead(DLinkedList* dLinkedList){

  return dLinkedList->head; // we return the head
}

LLNode* getTail(DLinkedList* dLinkedList){

  return dLinkedList->tail; // we return the tail
}

LLNode* getNext(LLNode* node){
  return node->next; // we return the next node
}

LLNode* getPrev(LLNode* node){
  return node->prev; //  we return the previous node
}

void* getData(LLNode* node){
  return node->data; // we return the data of the node
}

void insertAfter(DLinkedList* dLinkedList, LLNode* prev_node, void* data){
  if (prev_node == NULL) {
    printf("the given previous node cannot be NULL");
    return;
  }

  LLNode* newNode = create_llnode(data); // we create the new node we want to insert after
  if (newNode == NULL) {
    printf("Failed to allocate memory");
    return;
  }

  newNode->next = prev_node->next; // New Node == > PrevNodeNext
  newNode->prev = prev_node; // prevNode < === New Node
  

  if (prev_node->next != NULL) {
    prev_node->next->prev = newNode; // New Node < == PrevNodeNext
  }
  
  prev_node->next = newNode; // prevNode == > Node 

  if (dLinkedList->tail == prev_node) {
    dLinkedList->tail = newNode; // we check if we are inserting after the tail
  }
  dLinkedList->size++;
  return;
}

void insertBefore(DLinkedList* dLinkedList, LLNode* next_node, void* data){
  if (next_node == NULL) {
    printf("the given next node cannot be NULL");
    return;
  }

  LLNode* newNode = create_llnode(data); 
  if (newNode == NULL) {
    printf("Failed to allocate memory");
    return;
  }


   newNode->next = next_node; // newNode  == > Next Node 
   newNode->prev = next_node->prev; // nextNodePrev < ==  newNode  

   if (next_node->prev != NULL) {
    next_node->prev->next = newNode; // NextNodePrev  == > New Node
   }

   next_node->prev = newNode; // Newnode < == next Node 

   if (next_node == dLinkedList->head) {
    dLinkedList->head = newNode; 

  }

   dLinkedList->size++; // size ++
  return;
}

void insertHead(DLinkedList* dLinkedList, void* data){
  if(dLinkedList->head == NULL){
    LLNode* newNode = create_llnode(data);
    dLinkedList->head = newNode;
    dLinkedList->tail = newNode;
    dLinkedList->size++;  // size ++
  }else {
     insertBefore(dLinkedList, dLinkedList->head, data); // we insert it before the head
  }
}

void insertTail(DLinkedList* dLinkedList, void* data){
  if (dLinkedList->tail == NULL) {
    LLNode* newNode = create_llnode(data);
    dLinkedList->head = newNode;
    dLinkedList->tail = newNode;
    dLinkedList->size++;  // size ++
  } else {
    insertAfter(dLinkedList, dLinkedList->tail, data); // we insert the tail
  }
}

void deleteNode(DLinkedList* dLinkedList, LLNode* Node){
  // in the header says we assume the node to not be null so I wouldn't check for it

  if (dLinkedList->size == 0) {
    return;
  }

  // we check if we delete a node in the head
  if (dLinkedList->head == Node) {
     dLinkedList->head = Node->next; // we set the head pointer to our next node NODE  == HEAD
     if (dLinkedList->head != NULL) {
      dLinkedList->head->prev = NULL; // we set our prev head to null NULL <== HEAD
     } else {
       dLinkedList->tail = NULL; // list is empty lol
     }

  } else if (dLinkedList->tail == Node) {
    dLinkedList->tail = Node->prev; // we set the tail to the previous node PREV == TAIL
    if (dLinkedList->tail != NULL) {
      dLinkedList->tail->next = NULL; // we set the tail next PREV === > NULL
    }
  } 
  else {
    Node->prev->next = Node->next; // NODE PREV == > NODE NEXT
    Node->next->prev = Node->prev;  // NODE PREV < == NODE NEXT
  }
    free(Node->data);
    free(Node);
   dLinkedList->size--; 
}

void destroyList(DLinkedList* dLinkedList){

  if (dLinkedList == NULL) {
    return;
  }

  LLNode* current = dLinkedList->head;
    while (current != NULL) {
        LLNode* next = current->next; 
        free(current->data);
        free(current);                // free the current node
        current = next;               
    }
    dLinkedList->head = NULL;
    dLinkedList->tail = NULL;
    dLinkedList->size = 0;
    free(dLinkedList); // we free the List now 
} 

DLinkedList* split(DLinkedList* dLinkedList, LLNode* Node) {

  if (Node == dLinkedList->tail) {
    return NULL;
  }

  DLinkedList* newList = create_dlinkedlist();
  
    //new list 
    newList->head = Node->next;   
    newList->tail = dLinkedList->tail; // NODE  ==== > TAIL 

    //update the pointers
    dLinkedList->tail = Node; // HEAD ==== > NODE
    Node->next->prev = NULL;   // breaking ties 
    Node->next = NULL;  // set to null since now our node is the tail

    Node->next = newList->head; // we assign to our new list head
    while (Node->next != NULL) {
      newList->size++;
      Node->next = Node->next->next;
    }

    //update the OG dLinked size
    dLinkedList->size -= newList->size; 
    return newList; 
}
