#include <cstdio>

int n, L;
int a[100000];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int x, y, c; char ch;
		scanf("%d%d %c", &x, &y, &ch);
		if(ch == 'w') c = 1; else c = 0;
		for(int j = x; j <= y; j++) a[j] = c;
		if(y > L) L = y;
	}
	int ansL = 0, ansR = 0;
	for(int i = 1; i <= L; i++) if(a[i] == 1)
	{
		int cnt = 0;
		for(int j = i; j <= L; j++)
		{
			if(a[j] != 1) break;
			cnt++;
		}
		if(ansL == 0 || cnt > ansR - ansL + 1)
		{
			ansL = i;
			ansR = i + cnt - 1;
		}
	}
	if(!ansL) puts("Oh, my god");
	else printf("%d %d\n", ansL, ansR);
	return 0;
}
