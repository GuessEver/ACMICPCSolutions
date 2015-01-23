#include <cstdio>

int n, m, a[N];

int main()
{
	char ch;
	while(scanf("%d%c", &a[++n], &ch) == 2)
		if(ch != ',') break;
