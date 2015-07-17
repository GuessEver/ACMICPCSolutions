#include <cstdio>
#include <cstdlib>
#include <cstring>

int n, kmax, a[200], b[200];
struct Node{int i, j;}ans[2000];
int Cnt = 0;

int getmax(int *a)
{
	int k = -1;
	for(int i = 1; i <= n; i++)
		if(k == -1 || a[i] > a[k]) k = i;
	return k;
}
int getmin(int *a)
{
	int k = -1;
	for(int i = 1; i <= n; i++)
		if(k == -1 || a[i] < a[k]) k = i;
	return k;
}

int main()
{
	scanf("%d%d", &n, &kmax);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	for(int ti = 1; ti <= kmax; ti++)
	{
		int maxx = getmax(a);
		int minx = getmin(a);
		if(maxx == minx) break;
		a[maxx]--; a[minx]++;
		ans[Cnt].i = maxx;
		ans[Cnt++].j = minx;
	}
	int ANS = a[getmax(a)] - a[getmin(a)];
	printf("%d %d\n", ANS, Cnt);
	for(int i = 0; i < Cnt; i++)
	{
		printf("%d %d\n", ans[i].i, ans[i].j);
	}
	return 0;
}

