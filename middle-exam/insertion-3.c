#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct _country {
  char *name;
  int population;
  int area;
  struct _country *next;
} Country;
Country*head,*tail; // input singly linked List
Country*sorted; // sorted singly linked List
void dumpCountry(char*msg, Country*p){
  printf("%s Country(%s,%d,%d,next->%s)\n",
    msg, p->name, p->population, p->area,
    p->next==NULL?"NULL":p->next->name);
}
void dumpCountry(char*msg, Country*p){
    printf("%s Country(%s,%d,%d,next->%s)\n",
    msg, p->name, p->population, p->area,
    p->next==NULL?"NULL":p->next->name);
}
void dumpList(Country*p){
    while(p!=NULL){
        dumpCountry("dump",p);
        p=p->next;
    }
}
void freeList(Country*p){
    Country*temp;
    while(p!=NULL){
        temp=p->next;
        dumpCountry("free",p);
        free(p);
        p=temp;
    }
}
void addList(Country*p){
    if(tail==NULL){
        head=tail=p;
    }else{
        tail->next=p;
        tail=p;
    }
}
Country*newCountry(char*name, int population, int area){
    int len=strlen(name)+1;
    char*s=(char*)malloc(len);
    strcpy(s,name);
    Country*p=(Country*)malloc(sizeof(Country));
    p->name=s;
    p->population=population;
    p->area=area;
    p->next=NULL;
    dumpCountry("new",p);
    return p;
}
void insertNode(Country*p){
    if(strcmp(p->name,sorted->name)<0){
        p->next=sorted;
        sorted=p;
        printf("insert %s at head\n", p->name);
    }else{
        Country*prev=sorted;
        while(prev->next!=NULL){
            if(strcmp(p->name,prev->next->name)<0){
                break;
            }
            prev=prev->next;
        }
    }
}
void insertionSort(){

}
int main(){
    int n, caseno=0, population, area;
    char by[12], order[12];
    char name[20];

    while(scanf("%d%s%s", &n, &by[0], order)==3){
        if(caseno>0){
            printf("\n");
        }
        printf("Case #%d: sort Countries by \"%s\" in %s order\n", ++caseno, by, order);
        head=tail=NULL;
        while(n--){
            scanf("%s%d%d", name, &population, &area);
            Country*p=newCountry(name, population, area);
            addList(p);
        }
        
    }
}