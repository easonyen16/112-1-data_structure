#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct _TreeNode {
  int val;                       // 節點儲存的值
  struct _TreeNode *left;        // 指向左子節點的指針
  struct _TreeNode *right;       // 指向右子節點的指針
} TreeNode;
TreeNode* newTreeNode(char*s){
  if(s[0]=='n') return NULL;     // 如果字符串以 'n' 開頭，則返回 NULL，代表這是一個空節點
  TreeNode*t=(TreeNode*)malloc(sizeof(TreeNode)); // 為新節點分配內存
  t->val = atoi(s);              // 將字符串轉換為整數並賦值給節點
  t->left = t->right = NULL;     // 初始化左右子節點為 NULL
  return t;                      // 返回新創建的節點
}
#define MAXQSIZE 128
#define QMASK 127
TreeNode*root;
TreeNode*queue[MAXQSIZE]; // 0~127 0...
int head, tail, qsize;
void enqueue(TreeNode*t){
  if(qsize==MAXQSIZE) {
    printf("queue full\n");
    return;
  }
  queue[tail++] = t;
  tail &= QMASK;
  printf("enqueue(%d)\n", t->val);
  ++qsize;
}
TreeNode*dequeue(){
  if(qsize==0) {
    printf("queue empty\n");
    return NULL;
  }
  TreeNode*t = queue[head++];
  head &= QMASK;
  --qsize;
  printf("dequeue(%d)\n", t->val);
  return t;
}
void addRoot(char*p){
  root = newTreeNode(p);
  printf("add %d as the root\n", root->val);
  enqueue(root);
}
void addChildren(char*pleft, char*pright){
  TreeNode* t = dequeue();
  t->left = newTreeNode(pleft);
  t->right = newTreeNode(pright);
  if(t->left!=NULL) {
    printf("add %d as a left child of %d\n", t->left->val, t->val);
    enqueue(t->left);
  }
  if(t->right!=NULL) {
    printf("add %d as a right child of %d\n", t->right->val, t->val);
    enqueue(t->right);
  }
}
int main(){
  int n, caseno=0, tokno;
  char buf[1024];
  char *pleft, *pright, *p;
  TreeNode*t, *left, *right;
  scanf("%d\n",&n);
  while(n--){
    fgets(buf, sizeof(buf), stdin);
    pleft=strchr(buf,'[');
    pright=strchr(pleft+1,']');
    *pright = '\0';
    if(caseno>0) printf("\n");
    printf("Case #%d: binary tree = <%s>\n", ++caseno,pleft+1);
    head = tail = qsize = 0;
    for(tokno=0,p=strtok(pleft+1,",");;++tokno){
      if(tokno==0) addRoot(p);
      else{
        pleft=strtok(NULL,",");
        if(pleft==NULL) break;
        pright=strtok(NULL,",");
        addChildren(pleft,pright);
      }
    }
  }
}