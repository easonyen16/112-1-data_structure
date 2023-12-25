#include <stdio.h>

int main(){
    int n, caseno=0, population, area;
    char by[12], order[12];
    char name[20];

    while(scanf("%d%s%s", &n, &by[0], order)==3){
        if(caseno>0){
            printf("\n");
        }
        printf("Case #%d: sort Countries by \"%s\" in %s order\n", ++caseno, by, order);
        while(n--){
            scanf("%s%d%d", name, &population, &area);
            printf("input Country(name=%s, population=%d, area=%d)\n", name, population, area);
        }
    }
    return 0;
}
