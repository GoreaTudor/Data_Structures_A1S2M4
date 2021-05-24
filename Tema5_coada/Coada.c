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



//Create a new queue
DynamicQueue newQueue(){
    DynamicQueue queue = NULL;
    queue = (DynamicQueue) malloc(sizeof(struct IntegerLinkedList));
    if(queue){
        queue->numberOfElements = 0;
        queue->firstNode = NULL;
        queue->lastNode = NULL;

        return queue;
    }

    return NULL;
}

//Create a new node 
Node newNode(int value){
    Node p = NULL;
    p = (Node) malloc(sizeof(struct IntegerLinkedListNode));
    if(p){
        p->priority = LOW;
        p->value = value;
        p->next = NULL;

        return p;
    }

    return NULL;
}


//Verify if the queue is empty
int EMPTYQUEUE(DynamicQueue queue){
    if(queue){
        if(queue->firstNode)
            return 0;

        return 1; //empty queue
    }

    return 0; //no queue
}

//Display the queue
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


//Push element with low priority
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

//Push element with custom priority
int PUSHP(DynamicQueue queue, int value, queuePriorities pr){
    if(queue){
        if(queue->firstNode){
            Node p = newNode(value);
            p->priority = pr;

            queue->lastNode->next = p;
            queue->lastNode = p;
            queue->numberOfElements ++;

            return 1;
        }

        queue->firstNode = newNode(value);
        queue->firstNode->priority = pr;

        queue->lastNode = queue->firstNode;
        queue->numberOfElements = 1;

        return 1;
    }

    return 0;
}


//Pop element, priority doesn't matter
int POP(DynamicQueue queue){
    if(queue){
        if(queue->firstNode){
            if(queue->firstNode == queue->lastNode){ //there is only one node
                free(queue->firstNode);
                queue->firstNode = NULL;
                queue->lastNode = NULL;
                queue->numberOfElements = 0;

                return 1;
            }

            Node p = queue->firstNode;
            queue->firstNode = queue->firstNode->next;

            free(p);
            queue->numberOfElements --;

            return 1;
        }

        return 0;
    }

    return 0;
}

//Pop the first High Priority element, if there are no HP, return 0
int POPP(DynamicQueue queue){
    if(queue){
        if(queue->firstNode){
            if(queue->firstNode == queue->lastNode){ //there is only one node in the queue
                if(queue->firstNode->priority == HIGH){
                    free(queue->firstNode);
                    queue->firstNode = NULL;
                    queue->lastNode = NULL;
                    queue->numberOfElements = 0;

                    return 1;
                }

                return 0; //the element is not of high priority (HP)

            }else{ //there are more elements in the queue
                if(queue->firstNode->priority == HIGH){
                    Node p = queue->firstNode->next;
                    free(queue->firstNode);
                    queue->firstNode = p;
                    queue->numberOfElements --;

                    return 1;

                }else{
                    Node p = queue->firstNode;

                    while(p->next && p->next->priority != HIGH){ //inside the list
                        p = p->next;
                    }

                    if(p->next && p->next->priority == HIGH){
                        if(p->next == queue->lastNode)
                            queue->lastNode = p;

                        Node q = p->next;
                        p->next = q->next;
                        free(q);
                        queue->numberOfElements --;
                        
                        return 1;
                    }

                    return 0; //no HP node found
                }
            }
        }

        return 0; //empty queue
    }

    return 0; //there is no queue
}



//////////////////////////////////////////////////////////////////////



int main(){
    DynamicQueue queue = newQueue();
    int ok=1, opt, n, e, pr;

    while(ok){
        printf("\n1 - Display queue");
        printf("\n2 - Push");
        printf("\n3 - Push with priority");
        printf("\n4 - Pop");
        printf("\n5 - Pop first High priority");
        printf("\n6 - Is empty");
        printf("\n0 - EXIT");

        printf("\n\nOption: ");
        scanf("%d", &opt);
        printf("\n");

        switch(opt){
            case 1:{ //Display
                show(queue);
            } break;


            case 2:{ //Push
                printf("Value to be pushed: ");
                scanf("%d", &n);

                e = PUSH(queue, n);

                if(e)
                    printf("Pushed.");
                else
                    printf("PUSH error!");
            } break;


            case 3:{ //Push -p
                printf("Value to be pushed: ");
                scanf("%d", &n);

                printf("Priority (0-LOW / 1-HIGH): ");
                scanf("%d", &pr);

                if(pr == 1){
                    e = PUSHP(queue, n, HIGH);
                }else if(pr == 0){
                    e = PUSHP(queue, n, LOW);
                }else {
                    printf("Invalid option!");
                    continue;
                }

                if(e)
                    printf("Pushed.");
                else
                    printf("PUSHP error!");
            } break;


            case 4:{ //Pop
                e = POP(queue);

                if(e)
                    printf("Popped.");
                else
                    printf("POP error!");
            } break;


            case 5:{ //Pop -p
                e = POPP(queue);

                if(e)
                    printf("Popped.");
                else
                    printf("No such element!");
            } break;


            case 6:{ //empty
                e = EMPTYQUEUE(queue);

                if(e)
                    printf("The queue is empty.");
                else
                    printf("The queue is not empty.");
            } break;


            case 0:{ //EXIT
                printf("Bye.");
                ok = 0;
            } break;

            default: printf("Not a valid option!");
        }

        printf("\n\n");
    }

    return 0;
}