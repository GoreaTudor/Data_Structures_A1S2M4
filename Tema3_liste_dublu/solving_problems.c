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
    int size;
    Nod* head; //first element
    Nod* last; //last element
} LDI;


//Base Operations
Nod* newNod(int val){
    Nod* p = (Nod*) malloc(sizeof(Nod));
    p->val = val;
    p->next = NULL;
    p->pred = NULL;

    return p;
}

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


LDI* insert_last(LDI* list, int val){
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


////////

////////


int main(){
    LDI* list1 = newList();

    for(int i=1; i<=5; i++)
        list1 = insert_last(list1, i);

    display(list1);
    //display_r(list1);

    setListElement(list1, 4, 7);
    
    printf("\n\n");
    display(list1);
    //display_r(list1);

    return 0;
}