#include <stdio.h>
#include <stdlib.h>

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


DynamicStack* newStack(){
    DynamicStack* stack = (DynamicStack*) malloc(sizeof(DynamicStack));
    stack->firstNode = NULL;
    stack->lastNode = NULL;
    stack->numberOfElements = 0;

    return stack;
}

Node* newNode(int value){
    Node* p = (Node*) malloc(sizeof(Node));
    p->next = NULL;
    p->prev = NULL;
    p->value = value;

    return p;
}

int EMPTYSTACK(DynamicStack* stack){
    if(stack){
        if(stack->firstNode == NULL || stack->numberOfElements == 0)
            return 1;
        
        return 0;
    }

    return -1; //no stack
}


void show(DynamicStack* stack){
    int i = 0;
    Node* p;

    printf("\n");
    if(stack){
        if(EMPTYSTACK(stack)){
            printf("\nThe stack is empty!");
        }else{
            printf("\nThe stack has %d elements.", stack->numberOfElements);         
            for(p = stack->firstNode; p != NULL; p = p->next){
                printf("\nindex %d (0x%.6x):  0x%.6x  %d  0x%.6x", i, p, p->prev, p->value, p->next);
                i++;
            }
        }
    }
}

void show_r(DynamicStack* stack){
    int i = stack->numberOfElements -1;
    Node* p;
    
    printf("\n");
    if(stack){
        if(EMPTYSTACK(stack)){
            printf("\nThe stack is empty!");
        }else{
            printf("\nThe stack has %d elements.", stack->numberOfElements);         
            for(p = stack->lastNode; p != NULL; p = p->prev){
                printf("\nindex %d (0x%.6x):  0x%.6x  %d  0x%.6x", i, p, p->prev, p->value, p->next);
                i--;
            }
        }
    }
}


int PUSH(DynamicStack* stack, int value){
    Node* p = NULL;
    p = newNode(value);

    if(p){
        //printf("allocation success!");

        if(stack->firstNode && stack->lastNode){
            stack->lastNode->next = p;
            p->prev = stack->lastNode;

            stack->lastNode = p;
            stack->numberOfElements ++;

        }else{
            stack->firstNode = p;
            stack->lastNode = p;
            stack->numberOfElements ++;
        }
        
        return 1; //push success
    }

    return 0; //push failed
}

int POP(DynamicStack* stack){
    if(stack){
        if(stack->firstNode){
            if(stack->firstNode == stack->lastNode){
                free(stack->lastNode);

                stack->firstNode = NULL;
                stack->lastNode = NULL;
                stack->numberOfElements = 0;

            }else{
                stack->lastNode = stack->lastNode->prev;
                
                free(stack->lastNode->next);
                stack->lastNode->next = NULL;
                stack->numberOfElements --;
            }

            return 1; //POP success
        }

        return 0; //POP failed
    }

    return 0; //POP failed
}

/////

/////


int main(){
    DynamicStack* st = newStack();

    for(int i = 1; i<=5; i++)
        PUSH(st, i);

    show(st);
    show_r(st);

    POP(st);

    show(st);
    show_r(st);
}
