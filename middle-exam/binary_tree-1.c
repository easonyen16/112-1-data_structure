#include <stdio.h>
#include <string.h>

int main(){
    int n, caseno=0;
    char buf[1024];
    char *pleft, *pright;
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
    }
    return 0;
}
