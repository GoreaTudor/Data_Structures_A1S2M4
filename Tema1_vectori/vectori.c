#include <stdio.h>
#include <stdlib.h>

/* Errors:
    -1 allocation fail
    -2 vector not found
    -3 vector full
    -4 vector empty
    -5 value not valid

    1 - success
*/

typedef struct Integer{
    int* vect;
    size_t nrel;
    size_t lmax;
} Vector;


//Base Operations

Vector* init(){ //Constructor
    Vector* v = (Vector*) malloc(sizeof(Vector));
    v->vect = NULL;
    v->lmax = 0;
    v->nrel = 0;

    return v;
}

int v_alloc(Vector* v, int NrOfElements){ //allocating memory for array
    if(NrOfElements > 0){
        v->vect = (int*) malloc(NrOfElements * sizeof(int));

        if(v->vect){ //if space was allocated
            v->lmax = NrOfElements;
            return 1; //allocation success
        }

        return -1; //memory was not allocated
    }
    
    return -5; //Not a valid value
}


int insert(Vector* v, int value){
    if(v->vect){
        if(v->nrel == v->lmax)
            return -3; //full memory

        v->vect[v->nrel++] = value;
        return 1; //insertion success
    }

    return -2; //vector not found
}


int delete_by_index(Vector* v, int index){
    if(v->vect){
        if(v->nrel == 0)
            return -4; //vector empty

        if(index > v->nrel-1 || index < 0)
            return -5; //invalid value for index

        if(index == v->nrel-1)
            v->vect[index] = 0;
        else
            for(int j=index+1; j<v->nrel; j++)
                v->vect[j-1] = v->vect[j];

        v->nrel--;
        return 1; //deletion success
    }

    return -2; //vector not found
}


int search(Vector* v, int value){
    if(v->vect){
        if(v->nrel == 0)
            return -4; //vector empty

        for(int i=0; i<v->nrel; i++)
            if(v->vect[i] == value)
                return i; //return the first index found

        return -1; //NOT an Error, element was not found
    }

    return -2; //vector not found
}


int update(Vector* v, int index, int value){
    if(v->vect){
        if(v->nrel == 0)
            return -4; //vector empty

        if(index < 0 || index >= v->nrel)
            return -5; //invalid index

        v->vect[index] = value;
        return 1; //update success
    }

    return -2; //vector not found
}


void del(Vector* v){
    if(v->vect)
        free(v->vect);
    v->vect = NULL;
    v->lmax = 0;
    v->nrel = 0;
}


int display(Vector* v){
    if(v->vect){
        printf("Array elements:\n");
        for(int i=0; i<v->nrel; i++)
            printf("%d ", v->vect[i]);

        printf("\nNumber of elements: %d", v->nrel);
        printf("\nMaximum length: %d", v->lmax);
        printf("\n");

        return 1; //display success
    }

    return -2; //there is no vector
}


int main(){
    int n, poz, opt, e, ok=1;

    Vector* a = init();

    while(ok==1){
        printf("1 - for allocation of  memory\n");
        printf("2 - for displaying the vector\n");
        printf("3 - for inserting  an  element\n");
        printf("4 - for deleting   an  element\n");
        printf("5 - for searching  an  element\n");
        printf("6 - for updating   an  element\n");
        printf("7 - for deleting   the vector\n");
        printf("0 - EXIT\n");

        printf("\n\nEnter option: ");
        scanf("%d", &opt);
        printf("\n");

        switch(opt){
            case 1: { //allocation
                printf("Memory to allocate: ");
                scanf("%d", &n);

                e = v_alloc(a, n);
                if(e == -1) printf("Memory was not allocated!");
                if(e == -5) printf("Not a valid value!");
                if(e == 1) printf("Allocation Success!");
            } break;


            case 2: { //display
                if(display(a) == -2)
                    printf("There is no vector!");
            } break;


            case 3: { //insert
                printf("Value to be entered: ");
                scanf("%d", &n);

                e = insert(a, n);
                if(e == -2) printf("There is no vector!");
                if(e == -3) printf("Vector full!");
                if(e == 1) printf("Insertion Success!");
            } break;


            case 4: { //delete
                printf("Index to be deleted: ");
                scanf("%d", &n);

                e = delete_by_index(a, n);
                if(e == -2) printf("Vector not found!");
                if(e == -4) printf("Vector empty!");
                if(e == -5) printf("Invalid index value!");
                if(e == 1) printf("Deletion Success!");
            } break;


            case 5: { //search
                printf("Value to be searched for: ");
                scanf("%d", &n);

                e = search(a, n);
                if(e == -1) printf("Element not found!");
                if(e == -2) printf("Vector not found!");
                if(e == -4) printf("Vector is empty!");
                if(0 <= e && e < a->nrel) printf("Element on index: %d", e);
            } break;


            case 6: { //update
                printf("Index of the value to update: ");
                scanf("%d", &poz);
                printf("New value: ");
                scanf("%d", &n);

                e = update(a, poz, n);
                if(e == -2) printf("Vector not found!");
                if(e == -4) printf("Vector empty!");
                if(e == -5) printf("Invalid index value!");
                if(e == 1) printf("Update Success!");
            } break;


            case 7: { //free
                del(a);
                printf("Deletion Success!");
            } break;


            case 0: {
                printf("Bye.");
                del(a);
                ok = 0;
            } break;


            default: printf("Not a valid option, please try again.");
        }

        printf("\n\n\n");
    }

    return 0;
}