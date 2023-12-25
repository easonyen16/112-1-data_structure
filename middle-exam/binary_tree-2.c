#include <stdio.h>
#include <string.h>

int main(){
    int n, caseno=0, tokno;
    char buf[1024];
    char *pleft, *pright, *p;

    scanf("%d\n", &n);
    
    while(n--){
        fgets(buf, sizeof(buf), stdin);

        pleft=strchr(buf, '[');
        pright=strchr(pleft+1, ']');
        
        *pright='\0';
        
        if(caseno>0){
            printf("\n");
        }
        
        printf("Case #%d: binary tree = <%s>\n", ++caseno, pleft+1);
        
        p=strtok(pleft+1, ",");
        tokno=0;
        
        while(p!=NULL){
            printf("token[%d]=[%s]\n", ++tokno, p);
            p=strtok(NULL, ",");
        }
    }
    
    return 0;
}