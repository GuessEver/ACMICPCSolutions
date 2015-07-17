#include <cstdio>
#include <algorithm>
using std::sort;

struct Node { int a, b;} a[100010];

bool cmp(Node a, Node b)
{
	return a.a < b.a;
}

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d%d", &a[i].a, &a[i].b);
	sort(a+1, a+1+n, cmp);
	bool flag = 0;
	for(int i = 2; i <= n; i++)
		if(a[i].a > a[i-1].a && a[i].b < a[i-1].b)
		{
			flag = 1;
			break;
		}
	if(flag) printf("Happy Alex\n");
	else printf("Poor Alex\n");
	return 0;
}
