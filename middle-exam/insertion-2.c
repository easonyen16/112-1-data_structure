#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 定義一個國家結構體，包含名稱、人口、面積和指向下一個國家的指針。
typedef struct _country {
    char *name;           // 國家名稱的指針
    int population;       // 人口數
    int area;             // 國家面積
    struct _country *next; // 指向下一個國家結構體的指針
} Country;

// 定義頭指針和尾指針，用於維護國家鏈結列表
Country *head, *tail;

// 函數用於打印單個國家的信息
void dumpCountry(char *msg, Country *p) {
    printf("%s Country(%s,%d,%d,next->%s)\n",
           msg, p->name, p->population, p->area,
           p->next == NULL ? "NULL" : p->next->name);
}

// 函數用於打印整個國家鏈結列表的信息
void dumpList(Country *p) {
    while (p != NULL) {
        dumpCountry("dump", p); // 使用 dumpCountry 函數打印每個國家的信息
        p = p->next;            // 移動到列表中的下一個元素
    }
}

// 函數用於釋放整個國家鏈結列表佔用的記憶體
void freeList(Country *p) {
    Country *temp;
    while (p != NULL) {
        temp = p->next;         // 記錄下一個要處理的元素
        dumpCountry("free", p); // 打印當前要釋放的元素信息
        free(p->name);          // 釋放國家名稱佔用的記憶體
        free(p);                // 釋放國家結構體佔用的記憶體
        p = temp;               // 移動到下一個元素
    }
}

// 函數用於將一個國家結構體添加到鏈結列表中
void addList(Country *p) {
    if (tail == NULL) { // 如果列表為空
        head = tail = p; // 新元素既是頭也是尾
    } else {            // 如果列表不為空
        tail->next = p;  // 將新元素添加到列表末尾
        tail = p;        // 更新尾指針
    }
}

// 函數用於創建一個新的國家結構體並返回指向它的指針
Country *newCountry(char *name, int population, int area) {
    int len = strlen(name) + 1;          // 計算名稱長度，加一是為了結束符 '\0'
    char *s = (char *)malloc(len);       // 為名稱分配記憶體
    strcpy(s, name);                     // 複製名稱到新分配的記憶體
    Country *p = (Country *)malloc(sizeof(Country)); // 為新國家結構體分配記憶體
    p->name = s;                         // 設置名稱指針
    p->population = population;          // 設置人口
    p->area = area;                      // 設置面積
    p->next = NULL;                      // 下一個國家指針設置為 NULL
    dumpCountry("new", p);               // 打印新建國家的信息
    return p;                            // 返回新建的國家結構體指針
}

// 主函數
int main() {
    int n, caseno = 0, population, area;
    char by[12], order[12];
    char name[20];

    // 讀取輸入數據直到文件結尾
    while (scanf("%d%s%s", &n, &by[0], order) == 3) {
        if (caseno > 0) {
            printf("\n"); // 在案例之間打印空行
        }
        printf("Case #%d: sorted in %s order by \"%s\".\n", ++caseno, order, by);
        head = tail = NULL; // 初始化鏈結列表
        while (n--) {
            scanf("%s%d%d", name, &population, &area); // 讀取國家信息
            Country *p = newCountry(name, population, area); // 創建新國家結構體
            addList(p); // 將新國家添加到列表中
        }
        dumpList(head); // 打印列表中的所有國家
        freeList(head); // 釋放列表記憶體
    }
    return 0;
}
