#include <cstdio>
#include <algorithm>
using std::sort;

const int N = 5000 + 10;

int n;
struct Node{int a, b;}a[N];

bool cmp(Node a, Node b)
{
	if(a.a == b.a) return a.b < b.b;
	return a.a < b.a;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d%d", &a[i].a, &a[i].b);
	sort(a+1, a+1+n, cmp);
	int day = 0;
	for(int i = 1; i <= n; i++)
	{
		if(day <= a[i].b) day = a[i].b;
		else if(day <= a[i].a) day = a[i].a;
	}
	printf("%d\n", day);
	return 0;
}
