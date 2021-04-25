#include <stdio.h>
#include <stdlib.h>

typedef struct Integer_Linked_List{
    int val;
    struct Integer_Linked_List* next;
} Nod;
int list_size; //static value


//Base operations
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

void display(Nod* head){
    Nod *p;
    int i=0;

    printf("\nThe list has %d elements", list_size);
    printf("\nThe list elements are:\n");
    if(head){
        p = head;
        while(p){
            printf("\nindex %d:  %d ", i, p->val);
            p = p->next;
            i++;
        }
        printf("\nCan add element at index %d", i);
    }
}


Nod* getListItem(Nod* head, int pos){
    if(pos < 0 || pos >= list_size)
        return NULL;

    Nod* p = head;
    for(int i=0; i<pos; i++)
        p = p->next;

    return p;
}

Nod* setListItem(Nod* head, int pos, int val){
    if(head){
        if(pos < 0 || pos >= list_size)
            return head;

        Nod* p = getListItem(head, pos);
        p->val = val;

        return head;
    }

    return NULL;
}


Nod* insert_begin(Nod* head, int val){
    if(head){
        Nod* p = newNod(val);
        if(p){
            p->next = head;
            list_size++;
            return p;
        }

        return NULL;
    }

    head = newNod(val);
    list_size = 1;
    return head;
}

Nod* insert_end(Nod* head, int val){
    Nod *p, *q;
    if(head){
        p = head;
        while(p->next != NULL) p = p->next;

        
        q = newNod(val);
        // printf("q: %x %d %x\n", q, q->val, q->next);
        p->next = q;

        // printf("p: %x %d %x\n\n", p, p->val, p->next);
        list_size++;
        return head;

    }else{
        head = newNod(val);
        // printf("head: %x %d %x\n\n", head, head->val, head->next);

        list_size = 1;
        return head;
    }
}

Nod* insert_node(Nod* head, int index, int val){
    Nod *p, *q;
    if(head){
        if(index >= 0 && index <= list_size){
            if(index == 0){
                printf("\nInserting at begining.");
                return insert_begin(head, val);
            }

            if(index == list_size){
                printf("\nInserting at end.");
                return insert_end(head, val);
            }

            printf("\nInserting at index %d.", index);
            p = getListItem(head, index -1);
            q = newNod(val);

            q->next = p->next;
            p->next = q;

            list_size ++;
            return head;
        }

        return head; //invalid index
    }

    return insert_end(head, val);
}


Nod* delete_first(Nod* head){
    if(head){
        Nod* p = head->next;
        free(head);
        list_size--;

        return p;
    }

    return NULL;
}

Nod* delete_last(Nod* head){
    Nod *p;

    if(head){
        if(head->next == NULL){
            free(head);
            list_size--;

            return NULL;
        }

        p = head;
        while(p->next->next != NULL) p = p->next;

        free(p->next);
        p->next = NULL;

        list_size--;
        return head;
    }

    return NULL;
}

Nod* delete_node(Nod* head, int index){
    Nod *p, *q; 
    if(head){
        if(index >= 0 && index < list_size){
            if(index == 0){
                printf("\nDeleting first element.");
                return delete_first(head);
            }

            if(index == list_size -1){
                printf("\nDeleting last element.");
                return delete_last(head);
            }

            printf("\nDeleting element at index %d", index);
            p = getListItem(head, index -1);

            q = p->next;
            p->next = q->next;

            free(q);

            list_size --;
            return head;
        }

        return head; //invalid index
    }

    return NULL; //empty list
}

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


//Advanced operations
void swapItemsByIndex(Nod* head, int p1, int p2){
    if((0 > p1 || p1 >= list_size) || (0 > p2 || p2 >= list_size)) //not a valid value
        return;

    if(p1 == p2) //no need to swap
        return;

    //for different values
    Nod* a = getListItem(head, p1);
    Nod* b = getListItem(head, p2);
    
    if(a != NULL && b != NULL){
        Nod* p = a->next;
        Nod* q = b->next;
        Nod* temp = newNod(0);

        *temp = *a;

        *a = *b;
        a->next = p;

        *b = *temp;
        b->next = q;

        free(temp);
    }

}

Nod* sort_list(Nod* head){
	Nod* par_i;
	Nod* par_j;
    int i, j;

    for(i=0; i<list_size-1; i++){
        for(j=i+1; j<list_size; j++){
            par_i = getListItem(head, i);
            par_j = getListItem(head, j);

            if(par_i->val > par_j->val)
                swapItemsByIndex(head, i, j);
        }
    }

	return head;
}



int main(){
    int opt, val, poz, ok=1;
    Nod* list1 = NULL;

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
            }break;


            case 2:{ //Insert
                printf("Index: ");
                scanf("%d", &poz);

                printf("Value: ");
                scanf("%d", &val);

                if(poz < 0 || poz > list_size){
                    printf("Invalid index!");

                }else{
                    list1 = insert_node(list1, poz, val);
                }
            }break;


            case 3:{ //Delete
                printf("Index: ");
                scanf("%d", &poz);

                if(poz < 0 || poz >= list_size){
                    printf("Invalid index!");

                }else{
                    list1 = delete_node(list1, poz);
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
                scanf("%d", &poz);

                if(poz < 0 || poz >= list_size){
                    printf("Invalid index!");

                }else{
                    Nod* p = getListItem(list1, poz);
                    printf("The element on index %d is: %d", poz, p->val);
                }
            }break;


            case 6:{ //SET
                printf("Index: ");
                scanf("%d", &poz);

                printf("Value: ");
                scanf("%d", &val);

                if(poz < 0 || poz >= list_size){
                    printf("Invalid index!");

                }else{
                    printf("Set element.");
                    list1 = setListItem(list1, poz, val);
                }
            }break;


            case 7:{ //Swap
                printf("Index 1: ");
                scanf("%d", &poz);

                printf("Index 2: ");
                scanf("%d", &val);

                if(poz < 0 || poz >= list_size){
                    printf("Invalid index 1!");

                }else if(val < 0 || val >= list_size){
                    printf("Invalid index 2!");

                }else{
                    printf("Swapped elements.");
                    swapItemsByIndex(list1, poz, val);
                }
            }break;


            case 8:{ //Sort
                list1 = sort_list(list1);
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
}