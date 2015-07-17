#include <cstdio>
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;

const int N = 100000 + 10;

int n, r, avg;
long long need = 0, now = 0;
struct Node{
	int a, b;
}a[N];

bool cmp(Node a, Node b)
{
	return a.b < b.b;
}

int main()
{
	scanf("%d%d%d", &n, &r, &avg);
	long long need = 1ll * avg * n;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[i].a, &a[i].b);
		now += a[i].a;
	}
	std::sort(a+1, a+1+n, cmp);
	long long res = 0;
	if(now >= need) { puts("0"); return 0; }
	for(int i = 1; i <= n; i++)
	{
		long long tmp = r - a[i].a;
		if(now + tmp >= need)
		{
			tmp = need - now;
			res += tmp * a[i].b;
			cout << res << endl;
			break;
		}
		else{
			now += tmp;
			res += tmp * a[i].b;
		}
	}
	return 0;
}
