#include <stdio.h>
#include <stdlib.h>

typedef struct Integer_Linked_List{
    int val;
    struct Integer_Linked_List* next;
} Nod;
int list_size;


//Base operations
void display(Nod* head){
    Nod *p;
    int idx = 0;
    printf("\nThe list has %d elements", list_size);
    printf("\nThe list elements are:\n");
    if(head){
        p = head;
        while(p){
            printf("index %d (0x%.6x):  %d  0x%.6x\n", idx, p, p->val, p->next);
            p = p->next;
            idx++;
        }
        printf("Can add element at index %d\n", idx);
    }
}

Nod* newNod(int val){
    Nod *p;
    p = (Nod*) malloc(sizeof(Nod));
    if(p){
        p->val = val;
        p->next = NULL;

        return p;
    }

    return NULL;
}

Nod* getListItem(Nod* head, int pos){
    if(pos < 0 || pos >= list_size)
        return NULL;

    Nod* p = head;
    for(int i=0; i<pos; i++)
        p = p->next;

    return p;
}

Nod* insert_end(Nod* head, int val){
    Nod *p, *q;

    if(head){
        p = head;
        while(p->next != NULL) p = p->next;

        
        q = newNod(val);
        // printf("q: %x %d %x\n", q, q->val, q->next);
        p->next = q;

        //printf("p: %x %d %x\n", p, p->val, p->next); //printf("\n");
        list_size++;
        return head;

    }else{
        head = newNod(val);
        //printf("head: %x %d %x\n", head, head->val, head->next); //printf("\n");

        list_size = 1;
        return head;
    }
}



//////
Nod* delete_all(Nod* head){
    Nod* p;
    if(head){
        while(head){
            p = head;
            head = head->next;

            free(p);
        }

        list_size = 0;
        return NULL;
    }

    return NULL;
}
//////



int main(){
    Nod* list1 = NULL;

    for(int i=1; i<=7; i++)
        list1 = insert_end(list1, i);
    display(list1);

    list1 = delete_all(list1);

    printf("\n");
    display(list1);

    return 0;
}