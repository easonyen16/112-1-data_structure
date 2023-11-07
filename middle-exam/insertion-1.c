#include <stdio.h>

// 主函數，程式的入口點
int main(){
    // 宣告整數變量 n, caseno, population, 和 area
    int n, caseno=0, population, area;
    // 宣告字符陣列 by 和 order 來儲存排序依據和排序順序
    char by[12], order[12];
    // 宣告字符陣列 name 來儲存國家名稱
    char name[20];

    // 使用 while 迴圈讀取測試案例，當讀取到的變量數為 3 時繼續迴圈
    while(scanf("%d%s%s", &n, &by[0], order)==3){
        // 如果不是第一個案例，則在輸出之前打印一個換行符，以分隔不同的案例
        if(caseno>0){
            printf("\n");
        }
        // 打印案例標題，包括案例編號、排序依據和排序順序
        printf("Case #%d: sort Countries by \"%s\" in %s order\n", ++caseno, by, order);
        // 使用 while 迴圈讀取每個案例中的國家數據
        while(n--){
            // 讀取國家名稱、人口和面積數據
            scanf("%s%d%d", name, &population, &area);
            // 打印讀取的國家數據
            printf("input Country(name=%s, population=%d, area=%d)\n", name, population, area);
        }
    }
    // 程式結束
    return 0;
}
