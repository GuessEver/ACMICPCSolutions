#include <cstdio>
#include <cstring>
char op[100], site[100];
char stack[1000][100];
int top, current;

int main()
{
	top = 0; current = 0;
	strcpy(stack[0], "http://www.acm.org/");
	while(scanf("%s", op) == 1 && strcmp(op, "QUIT"))
	{
		if(!strcmp(op, "VISIT"))
		{
			scanf("%s", site);
			strcpy(stack[++current], site);
			top = current;
			puts(site);
		}
		else if(!strcmp(op, "BACK"))
		{
			if(current > 0) puts(stack[--current]);
			else puts("Ignored");
		}
		else if(!strcmp(op, "FORWARD"))
		{
			if(current < top) puts(stack[++current]);
			else puts("Ignored");
		}
	}
	return 0;
}
