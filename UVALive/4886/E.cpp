#include <cstdio>
#include <cstring>

int n, x, y;
char ch;
int a[2000];

int main()
{
	while(scanf("%d", &n) == 1 && n)
	{
		memset(a, 0, sizeof(a));
		do{
			scanf("%d%c", &x, &ch);
			if(ch == '-') scanf("%d%c", &y, &ch);
			else y = x;
			if(x > y) continue;
			//printf("%d %d\n", x, y);
			for(int i = x; i <= y; i++) a[i] = 1;
		}while(ch == ',');
		int cnt = 0;
		for(int i = 1;i <= n; i++) cnt += a[i];
		printf("%d\n", cnt);
	}
	return 0;
}
