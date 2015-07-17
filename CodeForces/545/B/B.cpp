#include <cstdio>

const int N = 100000 + 10;
int a[N], b[N], c[N];
char s[N];
int n, cnt;

int main()
{
	scanf("%s", s);
	for(n = 0; s[n]; n++) a[n] = s[n] - '0';
	scanf("%s", s);
	for(int i = 0; i < n; i++) b[i] = s[i] - '0';
	for(int i = 0; i < n; i++)
		if(a[i] != b[i])
		{
			c[i] = 1;
			cnt++;
		}
	if(cnt & 1) puts("impossible");
	else for(int i = 0, j = 0; i < n; i++)
	{
		if(c[i] && j < cnt / 2)
		{
			printf("%d", 1-a[i]);
			j++;
		}
		else printf("%d", a[i]);
	}
	return 0;
}
