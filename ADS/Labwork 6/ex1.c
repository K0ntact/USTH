#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//doubly linked list data structure ???
typedef struct TreeNode{
    int val;
    struct TreeNode* parent;
    struct TreeNode* tLeft;
    struct TreeNode* tRight;
}Node;

Node* init(int val){
    Node* a = (Node*)malloc(sizeof(Node));
    a->val = val;
    a->parent = NULL;
    a->tLeft = NULL;
    a->tRight = NULL;
    return a;
}

//insert Child node to the 1 side of Parent node (tP)
void insertLeft(Node* tP, Node* tC){
    tP->tLeft = tC;
    tC->parent = tP;
}

void insertRight(Node* tP, Node* tC){
    tP->tRight = tC;
    tC->parent = tP;
}

int isRoot(Node* t){
    return t->parent == NULL;
}

int isLeaf(Node* t){
    return (t->tLeft == NULL && t->tRight == NULL);
}

int* rand_int(int n)    //array of size n with random numbers from 0-99
{
    int* rand_arr = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i<n; i++){
        rand_arr[i] = rand()%101;
    }
    return rand_arr;
}

int INT_SIZE;   //size of int array
int* lvs_arr(int* int_arr){   //create leaves array from int array
    int depth = ceil(log2(INT_SIZE) + 1);  //length of leaves array
    int lvs_num = pow(2,depth - 1);

    int* temp = (int*)malloc(sizeof(int) * lvs_num);

    for(int i = 0; i<INT_SIZE; i++){    //copy int from array to leaves array
        temp[i] = int_arr[i];
    }

    for(int j = INT_SIZE; j<lvs_num; j++){  //fill the rest of leaves array with 100
        temp[j] = 100;
    }

    return temp;
}

int smaller(int a, int b){
    if(a < b){
        return a;
    }
    return b;
}

Node* build_Tree(int h){    //create a perfect 0 Tree with depth = h
    Node* root = init(0);
    if (h==1){
        return root;
    }
    
    Node* left = build_Tree(h-1);
    insertLeft(root, left);
    Node* right = build_Tree(h-1);
    insertRight(root, right);
    return root;    
}

int INDEX = 0;
void lvs_insert(Node* root, int* lvs_arr){  //insert leaves value
    if(root == NULL){
        return;
    }
    if(isLeaf(root)){
        root->val = lvs_arr[INDEX];
        INDEX++;
        return;
    }
    lvs_insert(root->tLeft, lvs_arr);
    lvs_insert(root->tRight, lvs_arr);
}

int fill_tree(Node* root){   //fill the remaining value of tree
    if(isLeaf(root)){
        return root->val;
    }
    root->val = smaller(fill_tree(root->tLeft), fill_tree(root->tRight));
}

//In-order vs Pre-order vs Post-order traversal:
//https://media.geeksforgeeks.org/wp-content/cdn-uploads/Preorder-from-Inorder-and-Postorder-traversals.jpg

//Pre-order NLR
void display_NLR(Node* t, int level){
    if(t == NULL){
        return;
    }
    display_NLR(t->tLeft, level+1);
    for(int i = 1; i <= 5*level; i++){
        printf(" ");
    }
    printf("-> %d\n", t->val);
    display_NLR(t->tRight, level+1);
}

int checkLastParent(Node* root, Node* temp){
    if(root->tRight == NULL){
        return (temp == root->parent);
    }
    checkLastParent(root->tRight, temp);
}

Node* GLOBAL_ROOT;
int search_node(Node* root, int val){
    if(checkLastParent(GLOBAL_ROOT,root)){
        if(root->val == val){
            display_NLR(root,0);
            return 1;
        }
        else
            printf("Value not found!\n");
            return -1;
    }

    if(root == NULL){
        return 0;
    }
    if(root->val == val){
        display_NLR(root,0);
        return 1;
    }
    search_node(root->tLeft, val);
    search_node(root->tRight, val);
}

int N_INDEX = -1;
void add_leaf(Node* root, int val){
    if(root == NULL){
        return;
    }
    if(isLeaf(root)){
        N_INDEX++;
        if(root->val == 100 && N_INDEX == INT_SIZE){
            root->val = val;
            return;
        }
    }
    add_leaf(root->tLeft, val);
    add_leaf(root->tRight, val);
    fill_tree(GLOBAL_ROOT);
}

void rem_leaf(Node* root, int val){ //
    if(root == NULL){
        return;
    }
    if(isLeaf(root)){
        if(root->val == val){
            root->val = root->parent->val;
        }
        return;
    }
    rem_leaf(root->tLeft, val);
    rem_leaf(root->tRight, val);
}

int main(){
    int n;
    printf("Give array length: ");
    scanf("%d", &n);
    INT_SIZE = n;
    int height = ceil(log2(n) + 1);
    
    // Intializes random number generator
    time_t tm;
    srand((unsigned) time(&tm));
    int* arr = rand_int(n);
    printf("\nInitial random array:\n");
    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }

    //create tree from random array
    int* leaves = lvs_arr(arr);
    Node* root = build_Tree(height);
    lvs_insert(root, leaves);
    fill_tree(root);
    GLOBAL_ROOT = root;

    printf("\n\nCreated tree: \n"); 
    display_NLR(root, 0);
    
    // //find a value and display its subtree if found

    // int find_val;
    // printf("\nWhat value do you want to find: ");
    // scanf("%d", &find_val);
    // printf("\nSubtree of node with value %d: \n", find_val);
    // search_node(root, find_val);

    // //add a leaf to the tree
    // int add_val;
    // printf("\nWhat value do you want to add: ");
    // scanf("%d", &add_val);
    // add_leaf(root, add_val);
    // printf("\nTree after adding %d: \n", add_val);
    // display_NLR(root, 0);

    // //remove a leaf node
    // int rem_val;
    // printf("\nWhat value do you want to remove: ");
    // scanf("%d", &rem_val);
    // rem_leaf(root, rem_val);
    // printf("\nTree after removing leaf node with value %d: \n", rem_val);
    // display_NLR(root, 0);

    return 0;
}