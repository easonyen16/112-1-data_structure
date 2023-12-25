#include <stdio.h>
#include <stdlib.h>
#define MAXNODES 6
#define PREORDER -1
#define INORDER 0
#define POSTORDER 1
int hasHeap(){
    int n;
    scanf("%d", &n);
    return n;
}
int *loadHeap(int n){
    int size = sizeof(int) * (n+1);
    int* a = (int*) malloc(size);
    int i;
    for (i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
    }
    printf("allocate %d bytes of an integer array for a heap from a[1] to a[%d].\n", size, n);
    return a;
}
void freeHeap(int arr[]){
    free(arr);
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
void dumpSubTree(int type, int a[], int root, int n){
    int left = root+root;
    int right = left+1;
    if(type==PREORDER){
        printf("%d", a[root]);
    }
    if(left<=n){
        printf("(");
        dumpSubTree(type, a, left, n);
        printf(")");
    }
    if(type==INORDER){
        printf("%d", a[root]);
    }
    if(right<=n){
        printf("(");
        dumpSubTree(type, a, right, n);
        printf(")");
    }
    if(type==POSTORDER){
        printf("%d", a[root]);
    }
}
void dumpHeapTree(char msg[], int type, int a[], int root, int n){
    printf("%s", msg);
    dumpSubTree(type, a, root, n);
    printf("\n");
}
void heapify(int a[], int n, int root){
    int left = root+root;
    int right = left+1;
    int larger = left;
    if(right<=n && a[right]>a[left]){
        larger = right;
    }
    if(a[root]<a[larger]){
        printf("swap(%d,%d)", a[root], a[larger]);
        int tmp = a[root];
        a[root] = a[larger];
        a[larger] = tmp;
        if(larger+larger<=n){
            heapify(a, n, larger);
        }else{
            printf("end\n");
        }
    }else{
        printf("no more swap\n");
    }
}
void buildMaxHeap(int a[], int n){
    int parent;
    for(parent=n>>1; parent>=1; --parent){
        printf("heapify subtree root index is %d\n", parent);
        dumpHeapTree("before heapify: ", INORDER, a, parent, n);
        heapify(a, n, parent);
        dumpHeapTree("after heapify: ", INORDER, a, parent, n);
    }
}
void sortByMaxHeap(int a[], int n){
    int t, pass=0;
    while(n>1){
        printf("heap-pass #%d: rootswap(%d,%d)\n", ++pass, a[1], a[n]);
        t = a[1];
        a[1] = a[n];
        a[n] = t;
        --n;
        if(n>=2){
            dumpHeapTree("before heapify: ", INORDER, a, 1, n);
            heapify(a, n, 1);
            dumpHeapTree("after heapify: ", INORDER, a, 1, n);
        }
    }
}
int main(){
    int nodes, caseno=0;
    int* arr;
    while((nodes=hasHeap())){
        if(caseno>0){
            printf("\n");
        }
        printf("Case #%d: there are %d unsorted integers.\n", ++caseno, nodes);
        arr = loadHeap(nodes);
        dumpHeap("input array:", arr, nodes, MAXNODES);
        dumpHeapTree("inorder heaptree> ", INORDER, arr, 1, nodes);
        buildMaxHeap(arr, nodes);
        dumpHeap("max-heap array:", arr, nodes, MAXNODES);
        sortByMaxHeap(arr, nodes);
        dumpHeap("sorted array:", arr, nodes, MAXNODES);
        freeHeap(arr);
    }
}