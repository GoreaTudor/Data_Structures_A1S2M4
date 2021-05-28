#include <stdlib.h>
#include <stdio.h>

struct IntegerBinaryTreeNode{
    int key;
    int value;
    struct IntegerBinaryTreeNode* left;
    struct IntegerBinaryTreeNode* right;
};
typedef struct IntegerBinaryTreeNode* Node;

struct IntegerBinaryTree{
    int nrOfElements;
    Node root;
};
typedef struct IntegerBinaryTree* BinaryTree;


//Create a new Binary Tree
BinaryTree newTree(){
    BinaryTree abc = (BinaryTree) malloc(sizeof(struct IntegerBinaryTree));
    abc->nrOfElements = 0;
    abc->root = NULL;

    return abc;
}

//Create a new node of the tree
Node newNode(int key, int value){
    Node p = (Node) malloc(sizeof(struct IntegerBinaryTreeNode));
    p->key = key;
    p->value = value;
    p->left = NULL;
    p->right = NULL;

    return p;
}


//Destroy function using recursivity
void abcDelete(Node root){
    if(root){
        abcDelete(root->left);
        abcDelete(root->right);
        free(root);
    }
}

//Destroy the tree
void destroyTree(BinaryTree abc){
    abcDelete(abc->root);
    abc->root = NULL;
    abc->nrOfElements = 0;
}


//Insert a note into the tree
int insert(BinaryTree abc, int key, int value){
    if(abc){
        if(abc->root == NULL){ //the tree is empty
            abc->root = newNode(key, value);
            abc->nrOfElements = 1;

            return 1;
        }

        //There are elements in the tree
        Node p = abc->root;

        while(p){
            if(key == p->key)
                return 0; //duplicate key

            if(key < p->key){ //key is LOWER
                if(p->left){
                    p = p->left;
                } else {
                    Node q = newNode(key, value);
                    p->left = q;
                    abc->nrOfElements ++;

                    return 1;
                }
            }

            if(key > p->key){ //key is HIGHER
                if(p->right){
                    p = p->right;
                } else {
                    Node q = newNode(key, value);
                    p->right = q;
                    abc->nrOfElements ++;

                    return 1;
                }
            }
        } // while(p)
    } // if(abc)

    return 0; //there is no binary tree
}


//Searches a node inside a tree
Node search(Node p, int key){
    if(p){
        if(key == p->key)
            return p; //the node is found

        if(key < p->key)
            return search(p->left, key); //the node is in left subtree

        if(key > p->key)
            return search(p->right, key); //the node is in the right subtree
    }

    return NULL; //the node was not found
}


//display the tree: p - Left - Right
void abcPreorder(Node p){
    if(p){
        printf("(k:%d, v:%d), ", p->key, p->value);
        abcPreorder(p->left);
        abcPreorder(p->right);
    }
}

//display the tree: Left - p - Right
void abcInorder(Node p){
    if(p){
        abcInorder(p->left);
        printf("(k:%d, v:%d), ", p->key, p->value);
        abcInorder(p->right);
    }
}

//display the tree: Left - Right - p
void abcPostorder(Node p){
    if(p){
        abcPostorder(p->left);
        abcPostorder(p->right);
        printf("(k:%d, v:%d), ", p->key, p->value);
    }
}



////////////////////////////////////////////////////////



int main(){
    BinaryTree abc = newTree();
    int ok=1, opt, n, k, e;
    Node p;

    while(ok){
        printf("\n1 - Display");
        printf("\n2 - Insert");
        printf("\n3 - Delete");
        printf("\n4 - Destroy tree");
        printf("\n5 - Search");
        printf("\n0 - Exit");

        printf("\n\nOption: ");
        scanf("%d", &opt);

        printf("\n");
        switch(opt){
            case 1:{ //display
                if(abc->root){
                    printf("Format: (key, value)\n");

                    printf("\nPreorder:\n");
                    abcPreorder(abc->root);

                    printf("\nInorder:\n");
                    abcInorder(abc->root);

                    printf("\nPostorder:\n");
                    abcPostorder(abc->root);
                } else {
                    printf("The tree is empty.");
                }
            }break;


            case 2:{ //insert
                printf("Key: ");
                scanf("%d", &k);

                printf("Value: ");
                scanf("%d", &n);

                e = insert(abc, k, n);

                if(e)
                    printf("Inserted.");
                else
                    printf("Error: There is another element with the same key!");
            }break;


            case 3:{ //delete - NYI
                printf("Not yet implemented");
            }break;


            case 4:{ //destroy tree
                destroyTree(abc);
                printf("Destroyed.");
            }break;


            case 5:{ //search
                printf("Key: ");
                scanf("%d", &k);

                p = search(abc->root, k);

                if(p)
                    printf("Key found: (%d, %d).", p->key, p->value);
                else
                    printf("Error: Key not found!");
            }break;


            case 0:{ //EXIT
                printf("Bye.");
                ok = 0;
            }break;


            default: printf("Invalid option!");
        }

        printf("\n\n");
    }

    return 0;
}