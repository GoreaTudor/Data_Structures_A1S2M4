#include <stdio.h>
#include <stdlib.h>

///// STATIC /////

typedef struct Static_Stack_Of_Integers{ //Static
    int* v;
    int MAX;
    int top;
} StaticStack;


// Create a new static Stack
StaticStack* newStaticStack(){
    StaticStack* stack = (StaticStack*) malloc(sizeof(StaticStack));
    stack->v = NULL;
    stack->MAX = 0;
    stack->top = -1;

    return stack;
}

// Allocate memory to the stack
void static_MemAlloc(StaticStack stack, int value){
    ;
}

// Verify if the stack is full
int static_FULLSTACK(StaticStack stack){
    ;
}

// Verify if the stack is empty
int static_EMPTYSTACK(StaticStack stack){
    ;
}

// Add an element to the top of the stack
void static_PUSH(StaticStack stack, int value){
    ;
}

// Delete the top of the stack
void static_POP(StaticStack stack){
    ;
}



///// Dynamic /////

typedef struct IntegerLinkedListNode{
    int value;
    struct IntegerLinkedListNode* next;
    struct IntegerLinkedListNode* prev;
} Node;

typedef struct IntegerLinkedList{ //Dynamic
    int numberOfElements;
    Node* firstNode;
    Node* lastNode;
} DynamicStack;


// Create a new dynamic Stack
DynamicStack* newDynamicStack(){
    DynamicStack* stack = (DynamicStack*) malloc(sizeof(DynamicStack));
    stack->firstNode = NULL;
    stack->lastNode = NULL;
    stack->numberOfElements = 0;

    return stack;
}

// Create a new node for the stack
void dynamic_newNode(DynamicStack stack, int value){
    ;
}

// Verify if the stack is empty
void dynamic_EMPTYSTACK(DynamicStack stack){
    ;
}

// Add a new node at the end of the list (top of the stack)
void dynamic_PUSH(DynamicStack stack, int value){
    ;
}

// Delete the last node (top of the stack)
void dynamic_POP(DynamicStack stack){
    ;
}


/////////////////////////////////////////////////////////////////////////////////


int main(){
    ;
}
