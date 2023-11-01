#include <stdio.h>

int stack[100], sp;

void push(int x) {
    stack[sp++] = x;
}

int pop() {
    return stack[--sp];
}

void dumpstack() {
    int i;
    for (i = 0; i < sp; ++i)
        printf("[%d]", stack[i]);
}

int main() {
    char line[100];
    int idx, sum, a, b, cases = 0;

    while (fgets(line, sizeof(line), stdin) != NULL) {
        printf("Case %d: input line is %s", ++cases, line);
        sp = 0;
        for (idx = 0;;) {
            while (line[idx] == ' ')
                ++idx;
            if (line[idx] == '\0' || line[idx] == '\n')
                break;
            switch(line[idx])
			{
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					sum=0;
					while('0'<=line[idx]&&line[idx]<='9')
					{
						sum=sum*10+line[idx]-'0';
						++idx;
					}
					push(sum);
					break;
				case '+':
					printf("before %c stack contains:",line[idx]);
					dumpstack();
					printf("\n");
					b=pop();
					a=pop();
					push(a+b);
					printf("do %d %c %d = %d\n",a,line[idx],b,stack[sp-1]);
					printf("after %c stack contains:",line[idx]);
					dumpstack();
					printf("\n");
					++idx;
					break;
				case '-':
					printf("before %c stack contains:",line[idx]);
					dumpstack();
					printf("\n");
					b=pop();
					a=pop();
					push(a-b);
					printf("do %d %c %d = %d\n",a,line[idx],b,stack[sp-1]);
					printf("after %c stack contains:",line[idx]);
					dumpstack();
					printf("\n");
					++idx;
					break;
				case '*':
					printf("before %c stack contains:",line[idx]);
					dumpstack();
					printf("\n");
					b=pop();
					a=pop();
					push(a*b);
					printf("do %d %c %d = %d\n",a,line[idx],b,stack[sp-1]);
					printf("after %c stack contains:",line[idx]);
					dumpstack();
					printf("\n");
					++idx;
					break;
				case '/':
					printf("before %c stack contains:",line[idx]);
					dumpstack();
					printf("\n");
					b=pop();
					a=pop();
					push(a/b);
					printf("do %d %c %d = %d\n",a,line[idx],b,stack[sp-1]);
					printf("after %c stack contains:",line[idx]);
					dumpstack();
					printf("\n");
					++idx;
					break;
				case '%':
					printf("before %c stack contains:",line[idx]);
					dumpstack();
					printf("\n");
					b=pop();
					a=pop();
					push(a%b);
					printf("do %d %c %d = %d\n",a,line[idx],b,stack[sp-1]);
					printf("after %c stack contains:",line[idx]);
					dumpstack();
					printf("\n");
					++idx;
					break;
				case '=':
					printf("%d\n",pop());
					++idx;
					break;
			}
        }
    }
    return 0;
}
