#include <stdio.h>
#include <stdlib.h>
#define MAXNODES 6
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
        freeHeap(arr);
    }
}