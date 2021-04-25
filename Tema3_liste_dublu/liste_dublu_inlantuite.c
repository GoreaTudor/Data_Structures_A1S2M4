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



//Displays list from FIRST to LAST element
void display(LDI* list){
    if(list){
        printf("\nThe list has %d elements", list->size);
        printf("\nNormal Display: ");

        if(list->head){
            int i=0;
            Nod* p;

            for(p = list->head; p != NULL; p = p->next)
                printf("\nindex %d (0x%.6x):  0x%.6x  %d  0x%.6x", i++, p, p->pred, p->val, p->next);
        }

        printf("\n");
    }
}

//Displays list from LAST to FIRST element
void display_r(LDI* list){
    if(list){
        printf("\nThe list has %d elements", list->size);
        printf("\nReverse Display: ");

        if(list->last){
            int i = list->size - 1;
            Nod *p;

            for(p = list->last; p != NULL; p = p->pred)
                printf("\nindex %d (0x%.6x):  0x%.6x  %d  0x%.6x", i--, p, p->pred, p->val, p->next);
        }

        printf("\n");
    }
}



//Returns an element on a specific index
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

//Changes the value of an element on a specific index
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



//Insert element at the begining of the list
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

//Insert element at the end of the list
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



//Deletes the FIRST element
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

//Deletes the LAST element
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



///// ADVANCED OPERATIONS /////



int main(){
    LDI* list1 = newList();
    

    return 0;
}