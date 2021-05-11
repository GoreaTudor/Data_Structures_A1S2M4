#include <stdio.h>
#include <stdlib.h>

typedef struct Static_Stack_Of_Integers{ //Static
    int* v;
    int MAX;
    int top;
} StaticStack;

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

/////

/////


int main(){
    ;
}
