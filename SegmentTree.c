#include <stdio.h>

#define LENGTH 5

void build_tree(int tree[], int a[], int v, int l, int r);
int get_sum(int tree[], int v, int tl, int tr, int l, int r );
void update_tree(int tree[], int a[], int id_of_change, int change_, int v, int l, int r);

int main(){  
    int a[LENGTH];     
    int tree[4 * LENGTH + 4];  
    int v, l, r, tl, tr;

    printf("Setup values of tree: ");

    for (int i = 0; i<LENGTH; i++){
        scanf("%d", &a[i]);
    }

    printf("Initialize snippet, l and r: ");
    scanf("%d", &l);
    scanf("%d", &r);

    printf("Setup first vertex of tree, v: ");
    scanf("%d", &v);

    build_tree(&tree, &a, v, l, r);

    printf("Tree is built\n");
    printf("Now you will initiate fringes of sum snippet, tl and tr: ");

    scanf("%d", &tl);
    scanf("%d", &tr);   
    printf("Sum is equal: %d", get_sum(&tree, v, tl, tr, l, r));
}

void build_tree(int tree[], int a[], int v, int l, int r) {
    if (l == r) {
        *(tree + v) = *(a + l);
    } else {
        //snippets separets into [tl; tm], [tm + 1; tr]
        int mid = (l + r) / 2;
        build_tree(tree, a, v * 2 + 1, l, mid);
        build_tree(tree, a, v * 2 + 2, mid + 1, r);
        *(tree + v) = *(tree + (v * 2 + 1)) + *(tree + (v * 2 + 2));
    }
}

void update_tree(int tree[], int a[], int id_of_change, int change_, int v, int l, int r){
    if (v == id_of_change){
        *(a + v) = change_;
        *(tree + v) = change_;
        return;
    }
    if (id_of_change > r || id_of_change < l){
        return;
    }
    int mid = (l + r) / 2;
    update_tree(tree, a, id_of_change, change_, 2 * v + 1, l, mid);
    update_tree(tree, a, id_of_change, change_, 2 * v + 2, mid + 1, r);
    *(tree + v) = *(tree + (2 * v +1)) + *(tree + (2 * v + 2));
}


//[tl, tr] - snippet of asking sum
//[l, r] - all definition of tree 
int get_sum(int tree[], int v, int tl, int tr, int l, int r ) {
    if (tl <= l && r <= tr) {
        return tree[v];
    }
    if (r < tl || tr < l) {
        return 0;
    }
    int mid = (l + r) / 2;
    return get_sum(tree, v * 2 + 1, tl, tr, l, mid)
         + get_sum(tree, v * 2 + 2, tl, tr, mid + 1, r);
}