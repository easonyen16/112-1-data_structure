#include <stdio.h>
#include <string.h>
#define MAX 1000
char stack[MAX];
int sp; //stack pointer 0: empty stack
void push(char c){
	if(sp>=MAX){
		printf("Stack Overflow!\n");
		return;
	}
	stack[sp++] = c;
}
char pop(void){
	if(sp<=0){
		// stack 為空，返回一個特殊字符表示錯誤
		return '\0';
	}
	return stack[--sp];
}
int match(char s[]){ // 0: No, 1: Yes
	int i;
	char popped;
	for(i=0;s[i]!='\0';++i){
		switch(s[i]){
			case '(': // fall through
			case '[':
			case '{':
			case '<':
				push(s[i]);
				break;
			case '>':
				popped = pop();
				if(popped == '\0' || popped != '<') return 0;
				break;
			case '}':
				popped = pop();
				if(popped == '\0' || popped != '{') return 0;
				break;
			case ']':
				popped = pop();
				if(popped == '\0' || popped != '[') return 0;
				break;
			case ')':
				popped = pop();
				if(popped == '\0' || popped != '(') return 0;
				break;
			default:
				// 忽略非括號字符
				break;
		}		
	}
	if(sp!=0){ 
        return 0; //only left
    }
	sp = 0;
	return 1;
}
int main(){
    char buf[MAX];
    while(fgets(buf, sizeof(buf), stdin) != NULL) {
        sp = 0;  // 重置 stack pointer
        // Remove newline character at the end of the line
        size_t len = strlen(buf);
        if (len > 0 && buf[len - 1] == '\n') {
            buf[len - 1] = '\0';
        }
        
        if(match(buf)) 
            printf("Yes\n");
        else
            printf("No\n");
    }
}
