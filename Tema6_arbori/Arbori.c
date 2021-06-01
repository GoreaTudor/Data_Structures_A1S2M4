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
void DeleteTree(Node root){
    if(root){
        DeleteTree(root->left);
        DeleteTree(root->right);
        free(root);
    }
}

//Destroy the tree
void abcDeleteTree(BinaryTree abc){
    DeleteTree(abc->root);
    abc->root = NULL;
    abc->nrOfElements = 0;
}


//Insert a note into the tree
int abcInsert(BinaryTree abc, int key, int value){
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
Node abcSearch(Node p, int key){
    if(p){
        if(key == p->key)
            return p; //the node is found

        if(key < p->key)
            return abcSearch(p->left, key); //the node is in left subtree

        if(key > p->key)
            return abcSearch(p->right, key); //the node is in the right subtree
    }

    return NULL; //the node was not found
}


//Deletes a node using  recursivity
Node DeleteNode(Node p, int key){
    if(p){
        if(key < p->key){
            p->left = DeleteNode(p->left, key);

        } else if(key > p->key){
            p->right = DeleteNode(p->right, key);

        } else { //key == p->key

            if(!p->left && !p->right){ //has no child
                free(p);
                return NULL;

            } else if(!p->left){ //has right child only
                Node temp = p->right;
                free(p);
                return temp;

            } else if(!p->right){ //has left child only
                Node temp = p->left;
                free(p);
                return temp;

            } else { //has two children
                Node temp = p->right;

                while(temp && temp->left) //minimum node in the right subtree of p
                    temp = temp->left;

                p->key = temp->key;
                p->value = temp->value;
            
                p->right = DeleteNode(p->right, temp->key);
            } 
        }

        return p;
    }

    return NULL;
}

//Deletes a node of the tree
int abcDeleteNode(BinaryTree abc, int key){
    if(abc){
        if(abc->root){
            if(abcSearch(abc->root, key)){
                abc->root = DeleteNode(abc->root, key);
                abc->nrOfElements --;

                return 1;
            }

            return 0; //node not found
        }

        return 0; //the tree is empty
    }

    return 0; //there is no tree
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


//returns the height of the tree
int abcHeight(Node p){
    if(p == NULL)
        return -1;

    int l = abcHeight(p->left);
    int r = abcHeight(p->right);

    if(l > r)
        return l + 1;
    else
        return r + 1;
}



////////////////////////////////////////////////////////



int main(){
    BinaryTree abc = newTree();
    int ok=1, opt, n, k, e;
    Node p;

    while(ok){
        printf("\n1 - Display");
        printf("\n2 - Insert");
        printf("\n3 - Delete node - NOT WORKING PROPERLY");
        printf("\n4 - Delete tree");
        printf("\n5 - Height");
        printf("\n6 - Search"); 
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

                e = abcInsert(abc, k, n);

                if(e)
                    printf("Inserted.");
                else
                    printf("Error: There is another element with the same key!");
            }break;


            case 3:{ //delete node
                printf("Key: ");
                scanf("%d", &k);

                e = abcDeleteNode(abc, k);
                
                if(e)
                    printf("Node Deleted.");
                else
                    printf("Error: node not found!");
            }break;


            case 4:{ //delete tree
                abcDeleteTree(abc);
                printf("Tree Deleted.");
            }break;


            case 5:{ //height
                n = abcHeight(abc->root);
                printf("The height of the tree is: %d", n);
            }break;


            case 6:{ //search
                printf("Key: ");
                scanf("%d", &k);

                p = abcSearch(abc->root, k);

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