#include <cstdio>

int n, m;
int a[30000+10];

int main()
{
	scanf("%d%d", &n, &m);
	int cur = 1;
	for(int i = 1; i < n; i++) scanf("%d", &a[i]);
	while(cur < m)
		cur += a[cur];
	if(cur == m) puts("YES");
	else puts("NO");
	return 0;
}
