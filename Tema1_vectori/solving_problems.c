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

int v_alloc(Vector* v, int NrOfElements){ //allocating memory for array
    if(NrOfElements > 0){
        v->vect = (int*) calloc(NrOfElements , sizeof(int));

        if(v->vect){ //if space was allocated
            v->lmax = NrOfElements;
            return 1; //allocation success
        }

        return -1; //memory was not allocated
    }
    
    return -5; //Not a valid value
}

int display(Vector* v){
    if(v->vect){
        //printf("Array elements:\n");
        for(int i=0; i<v->nrel; i++)
            printf("%d ", v->vect[i]);

        printf("\nNumber of elements: %d", v->nrel);
        printf("\nMaximum length: %d", v->lmax);
        printf("\n\n");

        return 1; //display success
    }

    return -2; //there is no vector
}


/////////
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
/////////


int main(){
    Vector* v = (Vector*) malloc(sizeof(Vector));
    v->vect = NULL;
    v->lmax = 0;
    v->nrel = 0;

    v_alloc(v, 5);

    v->nrel = 5;
    for(int i=0; i<v->lmax; i++)
        v->vect[i] = i+1;

    
    display(v);

    update(v, -2, 7);

    display(v);

    return 0;
}