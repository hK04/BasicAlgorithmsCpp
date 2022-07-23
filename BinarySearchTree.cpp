#include <stdio.h>

using namespace std;

//Fracture of Tree
typedef struct tree_element {
    int value;
    struct tree_element* right;
    struct tree_element* left;;
};

tree_element* create_tree_element(int val);

void insert_into_tree(tree_element* root, tree_element* elem);

void print_tree(tree_element* root); 

int main(){
    int a[7] = {8, 3, 1, 6, 10, 11, 4};
    tree_element* root = create_tree_element(a[0]);
    for (int i = 1; i<7; i++){
        tree_element* el = create_tree_element(a[i]);
        insert_into_tree(root, el);
    }
    print_tree(root);
    return 0;
}

tree_element* create_tree_element(int val){
    tree_element* elem = new tree_element;
    elem->value = val;
    elem->left = NULL;
    elem->right = NULL;
    return elem;
};

void insert_into_tree(tree_element* root, tree_element* elem){
    if (elem->value < root->value){
        if (root->left == NULL){
            root->left = elem;
        } else{
            insert_into_tree(root->left, elem);
        }
    } else {
        if (root->right == NULL){
            root->right = elem;
        } else{
            insert_into_tree(root->right, elem);
        }
    }
};
//this implementation of print provides ability to write tree in increasing way
void print_tree(tree_element* root){
    if (root->left != NULL){
        print_tree(root->left);
    }
    printf("%d \n", root->value);
    if (root->right != NULL){
        print_tree(root->right);
    }
}