#include <stdio.h>
#include <stdlib.h>

typedef enum{
    LOW = 0, HIGH
}queuePriorities;

struct IntegerLinkedListNode{
    int value;
    queuePriorities priority;
    struct IntegerLinkedListNode* next;
};
typedef struct IntegerLinkedListNode* Node;

struct IntegerLinkedList{
    int numberOfElements;
    Node firstNode;
    Node lastNode; 
};
typedef struct IntegerLinkedList* DynamicQueue;



DynamicQueue newQueue(){
    DynamicQueue queue = (DynamicQueue) malloc(sizeof(struct IntegerLinkedList));
    queue->numberOfElements = 0;
    queue->firstNode = NULL;
    queue->lastNode = NULL;

    return queue;
}

Node newNode(int value){
    Node p = (Node) malloc(sizeof(struct IntegerLinkedListNode));
    p->priority = LOW;
    p->value = value;
    p->next = NULL;

    return p;
}

int EMPTYQUEUE(DynamicQueue queue){
    if(queue){
        if(queue->firstNode)
            return 0;

        return 1; //empty queue
    }

    return 0; //no queue
}

void show(DynamicQueue queue){
    if(queue){
        if(queue->firstNode == NULL){
            printf("\nThe Queue is empty!");

        } else{
            printf("\nThe queue has %d elements:", queue->numberOfElements);
            int i = 0;
            for(Node p = queue->firstNode; p != NULL; p = p->next){
                printf("\n  index %d (0x%.6x):  %d  0x%.6x, priority: ", i, p, p->value, p->next);

                if(p->priority == HIGH)
                    printf("High");
                else
                    printf("Low");

                i++;
            }          
        }
    }
}

int PUSH(DynamicQueue queue, int value){
    if(queue){
        if(queue->firstNode){
            Node p = newNode(value);
            queue->lastNode->next = p;
            queue->lastNode = p;
            queue->numberOfElements ++;

            return 1;
        }

        queue->firstNode = newNode(value);
        queue->lastNode = queue->firstNode;
        queue->numberOfElements = 1;

        return 1;
    }

    return 0;
}



int main(){
    DynamicQueue queue = newQueue();



    for(int i=1; i<=5; i++)
        PUSH(queue, i);

    show(queue);

    return 0;
}