// 包含標準輸入輸出函式庫
#include <stdio.h>
// 包含字符串處理函式庫
#include <string.h>

// 主函數，程式的入口點
int main(){
    // 宣告整數變量 n 用於存儲測試案例的數量，caseno 用於記錄當前案例的編號
    int n, caseno=0;
    // 宣告一個字符型陣列 buf 作為緩衝區，用於存儲每個測試案例的輸入
    char buf[1024];
    // 宣告指針變量 pleft 和 pright 用於指向找到的 '[' 和 ']' 字符
    char *pleft, *pright;

    // 從標準輸入讀取整數到 n，這是將要處理的測試案例的數量
    scanf("%d\n", &n);
    
    // 使用 while 迴圈來處理所有的測試案例
    while(n--){
        // 使用 fgets 從標準輸入讀取一行文字到 buf 中
        fgets(buf, sizeof(buf), stdin);
        
        // 使用 strchr 函數找到 buf 中第一次出現 '[' 的位置
        pleft=strchr(buf, '[');
        // 使用 strchr 函數找到 pleft 之後第一次出現 ']' 的位置
        pright=strchr(pleft+1, ']');
        
        // 將 pright 指向的 ']' 修改為字符串結束符 '\0'，從而終止字符串
        *pright='\0';
        
        // 如果不是第一個案例，則在輸出之前打印一個換行符
        if(caseno>0){
            printf("\n");
        }
        
        // 使用 printf 函數按照格式 "Case #%d: binary tree = <%s>\n" 打印案例編號和二叉樹字符串
        printf("Case #%d: binary tree = <%s>\n", ++caseno, pleft+1);
    }
    
    // 程式正常結束
    return 0;
}
