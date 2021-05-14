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


// Create a new dynamic Stack
DynamicStack* newStack(){
    DynamicStack* stack = (DynamicStack*) malloc(sizeof(DynamicStack));
    stack->firstNode = NULL;
    stack->lastNode = NULL;
    stack->numberOfElements = 0;

    return stack;
}

// Create a new node for the stack
Node* newNode(int value){
    Node* p = (Node*) malloc(sizeof(Node));
    p->next = NULL;
    p->prev = NULL;
    p->value = value;

    return p;
}

// Verify if the stack is empty
int EMPTYSTACK(DynamicStack* stack){
    if(stack){
        if(stack->firstNode == NULL || stack->numberOfElements == 0)
            return 1;
        
        return 0;
    }

    return -1; //no stack
}

// Display the stack
void show(DynamicStack* stack){
    int i = 0;
    Node* p;
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

// Display the stack in reverse
void show_r(DynamicStack* stack){
    int i = stack->numberOfElements -1;
    Node* p;
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

// Add a new node at the end of the list (top of the stack)
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

// Delete the last node (top of the stack)
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

// Delete the entire stack
void deleteStack(DynamicStack* stack){
    ;
}


///////////////////////////////////////////////////////////////////////////////

int main(){
    int ok=1, opt;

    while(ok){
        printf("\n1 - Show stack");
        printf("\n2 - Show stack - reverse");
        printf("\n3 - PUSH");
        printf("\n4 - POP");
        printf("\n5 - Delete all");
        printf("\n6 - EMPTYSTACK");
        printf("\n0 - EXIT");

        printf("\n\nOption: ");
        scanf("%d", &opt);

        switch(opt){
            case 1: { //show
                ;
            } break;


            case 2: { //show reverse
                ;
            } break;


            case 3: { //push
                ;
            } break;


            case 4: { //pop
                ;
            } break;


            case 5: { //delete all
                ;
            } break;


            case 6: { //empty stack
                ;
            } break;


            case 0: {
                printf("Bye."); ok = 0;
            }break;

            default: printf("\nInvalid option!");
        }

        printf("\n\n");
    } 
}