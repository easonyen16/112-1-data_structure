#include <stdio.h>
void dump(char msg[], int a[], int n){
    printf("%s[%d", msg, a[0]);
    int idx=1;
    while(idx<n){
        printf(",%d", a[idx]);
        idx++;
    }
    printf("]\n");
}
int load(int a[]){
    int x;
    int idx=0;
    while(scanf("%d", &x)==1){
        a[idx]=x;
        idx++;
    }
    return idx;
}
int main(){
    int a[100];
    int n,x,j,last,i;
    int cmps=0, movs=0;
    n =load(a);
    dump("The input a[]=", a, n);
    for(j=1;j<n;j++){
        x = a[j];
        printf("Pass %d:\n", j);
        printf("***(%d)***move a[%d] to x:%d\n", ++movs, j, x);
        printf("***insert x:%d", x);
        dump(" into the sorted a[]=", a, j);
        last = j-1;
        for(i=last; i>=0; i--){
            printf("---[%d]---compare x:%d with a[%d]:%d\n", ++cmps, x, i, a[i]);
            if (x<a[i]){
                a[i+1]=a[i];
                printf("***(%d)***move a[%d]:%d to a[%d]\n", ++movs, i, a[i], i+1);
            }else {
                break;
            }
        }
        a[i+1]=x;
        printf("***(%d)***move x:%d to a[%d]\n", ++movs, x, i+1);
        dump("***the sorted a[]=", a, j+1);
    }
    printf("The total number of comparisons is %d\n", cmps);
    printf("The total number of data movement is %d\n", movs);
}