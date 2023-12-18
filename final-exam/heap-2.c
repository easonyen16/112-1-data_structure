#include <stdio.h>
#include <stdlib.h>
#define MAXNODES 6
#define PREORDER -1
#define INORDER 0
#define POSTORDER 1
int hasHeap() {
    int n;
    scanf("%d", &n);
    return n;
}

int* loadHeap(int n) {
    int size = sizeof(int) * (n+1);
    int* a = (int*) malloc(size);
    int i;
    for (i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        printf("allocatc %d bytes of an integer array for a heap from a[1] to a[%d].\n", size, n);
    }
    return a;
}
void dumpHeap(char msg[], int a[] , int n, int width){
    int i;
    printf("%s\n", msg);
    for (i=1; i<=n; ++i) {
        if(i>1 && i%width==1){
            printf("\n");
        }
        if(i%width==1){
            printf("a[%02d]~a[%02d]:", i, (i+width-1>n?n:i+width-1));
        }
        printf("%6d", a[i]);
    }
    printf("\n");
}
void freeHeap(int a[]){
    free(a);
}
void dumpHeapSubtTree(int type, int a[], int root, int n){
    int left = root+root;
    int right = left+1;
    if(type==PREORDER){
        printf("%d ", a[root]);
    }
    if(left<=n){
        printf("(");
        dumpHeapSubtTree(type, a, left, n);
        printf(")");
    }
    if(type==INORDER){
        printf("%d ", a[root]);
    }
    if(right<=n){
        printf("(");
        dumpHeapSubtTree(type, a, right, n);
        printf(")");
    }
    if(type==POSTORDER){
        printf("%d ", a[root]);
    }
}
void dumpHeapTree(char msg[], int type, int a[], int root, int n){
    printf("%s", msg);
    dumpHeapSubtTree(type, a, root, n);
    printf("\n");
}
int main() {
    int nodes, caseno=0;
    int* arr;
    while ((nodes=hasHeap())) {
        if(caseno>0){
            printf("\n");
        }
        printf("Case #%d: there are %d unsorted integers.\n", ++caseno, nodes);
        arr = loadHeap(nodes);
        dumpHeap("input array:", arr, nodes, MAXNODES);
        dumpHeapTree(" preorder heaptree> ", PREORDER, arr, 1, nodes);
        dumpHeapTree("  inorder heaptree> ", INORDER, arr, 1, nodes);
        dumpHeapTree("postorder heaptree> ", POSTORDER, arr, 1, nodes);
        freeHeap(arr);
    }
}
