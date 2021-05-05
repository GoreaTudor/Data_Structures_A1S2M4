#include <stdio.h>
#include <stdlib.h>

//A node as a structure
typedef struct Int_Dubly_Linked_List_Node{
    int val;
    struct Int_Dubly_Linked_List_Node* next;
    struct Int_Dubly_Linked_List_Node* pred;
} Nod;

//The list as a structure
typedef struct Dubly_Linked_List{
    size_t size;  //size of the list
    Nod* head; //first element
    Nod* last; //last element
} LDI;



///// BASE OPERATIONS /////

//Allocation of memory for one node
Nod* newNod(int val){
    Nod* p = (Nod*) malloc(sizeof(Nod));
    p->val = val;
    p->next = NULL;
    p->pred = NULL;

    return p;
}

//Allocation of memory for one list
LDI* newList(){
    LDI* list = (LDI*) malloc(sizeof(LDI));
    if(list){
        list->size = 0;
        list->head = NULL;
        list->last = NULL;

        printf("List created (0x%x):  %d  0x%x  0x%x \n\n", list, list->size, list->head, list->last);
        return list;
    }

    printf("List was not created!");
    return NULL;
}



//Displays list from FIRST to LAST node
void display(LDI* list){
    if(list){
        printf("\nThe list has %d elements", list->size);
        printf("\nNormal Display: ");

        if(list->head){
            int i=0;
            Nod* p;

            for(p = list->head; p != NULL; p = p->next)
                printf("\nindex %d: %d", i++, p->val);
        }

        printf("\n");
    }
}

//Displays list from LAST to FIRST node
void display_r(LDI* list){
    if(list){
        printf("\nThe list has %d elements", list->size);
        printf("\nReverse Display: ");

        if(list->last){
            int i = list->size - 1;
            Nod *p;

            for(p = list->last; p != NULL; p = p->pred)
                printf("\nindex %d: %d ", i--, p->val);
        }

        printf("\n");
    }
}



//Returns a node on a specific index
Nod* getListItem(LDI* list, int index){
    Nod* p;
    if(list){
        if(list->head){
            if(index >= 0 && index < list->size){
                p = list->head;

                for(int i=0; i < index && p != NULL; i++)
                    p = p->next;
                
                return p;
            }

            return NULL; //invalid index
        }

        return NULL; //list empty
    }

    return NULL; //there is no list
}

//Changes the value of a node on a specific index
void setListElement(LDI* list, int index, int val){
    Nod* p;
    if(list){
        if(list->head){
            if(index >= 0 && index < list->size){
                p = list->head;

                for(int i=0; i < index && p != NULL; i++)
                    p = p->next;

                p->val = val;
                return;
            }

            return; //invalid index
        }

        return; //empty list
    }

    return; //there is no list
}



//Insert node at the begining of the list
LDI* insert_begin(LDI* list, int val){
    Nod* p;
    if(list){
        if(list->head){
            p = newNod(val);

            p->next = list->head;
            list->head->pred = p;

            list->head = p;

            list->size ++;
            return list;
        }

        p = newNod(val);
        list->head = p;
        list->last = p;

        list->size = 1;
        return list;
    }

    return NULL;
}

//Insert node at the end of the list
LDI* insert_end(LDI* list, int val){
    Nod *p;
    if(list){
        if(list->last){
            p = newNod(val);

            list->last->next = p;
            p->pred = list->last;

            list->last = p;

            list->size ++;
            return list;
        }

        p = newNod(val);
        list->head = p;
        list->last = p;
        list->size = 1;

        return list;
    }

    return NULL;
}

//Insert a node on a specific index
LDI* insert_node(LDI* list, int index, int val){
    Nod *p, *q;
    if(list){
        if(index >=0 && index <= list->size){
            if(list->head){
                if(index == 0){
                    return insert_begin(list, val);
                }

                if(index == list->size){
                    return insert_end(list, val);
                }

                p = getListItem(list, index -1);
                q = newNod(val);

                q->next = p->next; 
                q->pred = p;

                q->next->pred = q;
                p->next = q;

                list->size ++;
                return list;
            }

            p = newNod(val);
            list->head = p;
            list->last = p;

            list->size = 1;
            return list;
        }

        return list; //invalid index
    }

    return NULL;
}


//Delete the FIRST node
LDI* delete_first(LDI* list){
    Nod* p;

    if(list){
        if(list->head){
            if(list->head == list->last){ //there is only one element
                free(list->head);
                list->head = NULL;
                list->last = NULL;

                list->size = 0;
                return list;
            }

            p = list->head;

            list->head = p->next;
            p->next->pred = NULL;

            free(p);

            list->size --;
            return list;
        }

        return NULL; //list empty
    }

    return NULL; //there is no list
}

//Delete the LAST node
LDI* delete_last(LDI* list){
    Nod* p;

    if(list){
        if(list->head){
            if(list->head == list->last){ //there is only one element
                free(list->last);
                list->head = NULL;
                list->last = NULL;
                
                list->size = 0;
                return list;
            }

            p = list->last;

            list->last = p->pred;
            p->pred->next = NULL;

            free(p);

            list->size --;
            return list;

        }

        return NULL; //list empty
    }

    return NULL; //there is no list
}

//Delete a node on a specific index
LDI* delete_node(LDI* list, int index){
    Nod* p;
    if(list){
        if(list->head){
            if(index >=0 && index < list->size){
                if(index == 0){
                    return delete_first(list);
                }

                if(index == list->size -1){
                    return delete_last(list);
                }

                p = getListItem(list, index);

                p->pred->next = p->next;
                p->next->pred = p->pred;

                free(p);

                list->size --;
                return list;
            }

            return list; //invalid index
        }

        return list; //empty list
    }

    return NULL; //there is no list
}

//Delete all the nodes of a list
LDI* delete_all(LDI* list){
    Nod* p;
    if(list){
        if(list->head){
            while(list->head){
                p = list->head;
                list->head = list->head->next;

                free(p);
            }

            list->head = NULL;
            list->last = NULL;
            list->size = 0;

            return list;
        }

        return list; //list empty -no need to delete
    }

    return NULL; //there is no list
}



///// ADVANCED OPERATIONS /////

//Swaps two nodes by their index
LDI* swapItemsByIndex(LDI* list, int idx1, int idx2){
    if(list){
        if(list->head){
            if((idx1 >= 0 && idx1 < list->size) && (idx2 >= 0 && idx2 < list->size)){
                Nod* p = getListItem(list, idx1);
                Nod* p1 = p->pred;
                Nod* p2 = p->next;

                Nod* q = getListItem(list, idx2);
                Nod* q1 = q->pred;
                Nod* q2 = q->next;

                Nod* temp = newNod(0);
                *temp = *p;

                *p = *q;
                p->pred = p1;
                p->next = p2;

                *q = *temp;
                q->pred = q1;
                q->next = q2;

                free(temp);
                return list;
            }

            return list; //invalid idx1 or idx2
        }

        return list; //list empty
    }

    return NULL; //there is no list
}

LDI* sortList(LDI* list){
    Nod *p, *q;
    int i, j;

    if(list){
        if(list->head){
            for(i=0; i < list->size; i++){
                p = getListItem(list, i);

                for(j=i+1; j < list->size; j++){
                    q = getListItem(list, j);

                    if(p->val > q->val)
                        swapItemsByIndex(list, i, j);
                }
            }

            return list;
        }

        return list; //empty list
    }

    return NULL; //there is no list
}



int main(){
    int pos, val, opt, ok=1;
    LDI* list1 = newList();

    while(ok == 1){
        printf("\n1 - Display list");
        printf("\n2 - Insert new element");
        printf("\n3 - Delete an element");
        printf("\n4 - Delete all elements");
        printf("\n5 - Get an element");
        printf("\n6 - Set an element");
        printf("\n7 - Swap two elemnts");
        printf("\n8 - Sort list");
        printf("\n0 - EXIT");

        printf("\n\nYour option: ");
        scanf("%d", &opt);
        printf("\n");

        switch(opt){
            case 1:{ //Display
                display(list1);
                display_r(list1);
            }break;


            case 2:{ //Insert
                printf("Index: ");
                scanf("%d", &pos);

                printf("Value: ");
                scanf("%d", &val);

                if(pos < 0 || pos > list1->size){
                    printf("Invalid index!");

                }else{
                    list1 = insert_node(list1, pos, val);
                }
            }break;


            case 3:{ //Delete
                printf("Index: ");
                scanf("%d", &pos);

                if(pos < 0 || pos >= list1->size){
                    printf("Invalid index!");

                }else{
                    list1 = delete_node(list1, pos);
                }
            }break;


            case 4:{ //Delete All
                printf("Are you sure? This action can not be undone. (1 for yes)");
                printf("\nYour option: ");
                scanf("%d", &val);
                
                if(val == 1){
                    list1 = delete_all(list1);
                    printf("List Deleted.");
                }else{
                    printf("The list was not deleted.");
                }
            }break;


            case 5:{ //GET
                printf("Index: ");
                scanf("%d", &pos);

                if(pos < 0 || pos >= list1->size){
                    printf("Invalid index!");

                }else{
                    Nod* p = getListItem(list1, pos);
                    printf("The element on index %d is: %d", pos, p->val);
                }
            }break;


            case 6:{ //SET
                printf("Index: ");
                scanf("%d", &pos);

                printf("Value: ");
                scanf("%d", &val);

                if(pos < 0 || pos >= list1->size){
                    printf("Invalid index!");

                }else{
                    printf("Set element.");
                    setListElement(list1, pos, val);
                }
            }break;


            case 7:{ //Swap
                printf("Index 1: ");
                scanf("%d", &pos);

                printf("Index 2: ");
                scanf("%d", &val);

                if(pos < 0 || pos >= list1->size){
                    printf("Invalid index 1!");

                }else if(val < 0 || val >= list1->size){
                    printf("Invalid index 2!");

                }else{
                    printf("Swapped elements.");
                    swapItemsByIndex(list1, pos, val);
                }
            }break;


            case 8:{ //Sort
                list1 = sortList(list1);
                printf("Sorted.");
            }break;

            
            case 0:{ //EXIT
                printf("Bye!");
                ok = 0;
            }break;


            default:
                printf("\nNot a valid option!");
        }

        printf("\n\n");
    }

    return 0;
}