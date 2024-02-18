#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int hasNextCase(){
    int n;
    if(scanf("%d", &n)==EOF){
        return 0;
    }
    return n;
}
void showCaseNo(int n){
    if(n>0){
        printf("\n");
    }
    printf("Case %d:\n", n);
}
char *queue[MAX];
int head, tail;
int isQueue;
int isStack;
void enqueue(char f[]){
    queue[tail++]=f;
}
char *dequeue(){
    int i;
    printf("do dequeue and return %s\n", queue[head]);
    return queue[head++];
}
char *stack[MAX];
int sp;
void push(char f[]){
    stack[sp++]=f;
}
char*pop(){
    printf("do pop and return %s\n", stack[sp-1]);
    return stack[--sp];
}
void dumpStack(){
    int i;
    printf("stack point=%d\n", sp);
    for(i=0;i<sp;++i){
        printf("stack[%d]=%s\n", i, stack[i]);
    }
}
void dumpQueue(){
    int i;
    for(i=head;i<=tail;++i){
        printf("queue head=%d, tail=%d\n", head, tail);
        for(i=head;i<tail;++i){
            printf("queue [%d]=%s\n", i, queue[i]);
        }
    }
}
void doThrow(char f[]){
    char*p = (char*)malloc(strlen(f)+1);
    strcpy(p, f);
    if(isQueue==1){
        enqueue(p);
        dumpQueue();
    }
    if(isStack==1){
        push(p);
        dumpStack();
    }
}
void doTake(char f[]){
    if(isQueue==1){
        char*p = dequeue();
        if(strcmp(p, f)!=0){
            isQueue=0;
        };
        dumpQueue();
    }
    if(isStack==1){
        char*p = pop();
        if(strcmp(p, f)!=0){
            isStack=0;
        };
        dumpStack();
    }
}
void loadOperations(int n){
    int i, ret;
    char cmd[8], fruit[32];
    head=tail=0;
    isQueue=1;
    for(i=0;i<n;++i){
        scanf("%s%s",&cmd[0], &fruit[0]);
        printf("cmd=%s, fruit=%s\n", &cmd[0], &fruit[0]);
        if(strcmp("throw", cmd)==0){
            doThrow(fruit);   
        }else{
            doTake(fruit);
        }
    }
}
void showAnswer(){
    if(isQueue){
        printf("The answer is a queue.\n");
    }else{
        printf("The answer is NOT a queue.\n");
    }
    if(isStack){
        printf("The answer is a stack.\n");
    }else{
        printf("The answer is NOT a stack.\n");
    }
}
int main(){
    int n, caseno=0;
    while((n=hasNextCase()!=0)){
        showCaseNo(++caseno);
        loadOperations(n);
    }
}