#include <cstdio>
#include <algorithm>

const int N = 100100;

struct Node{
	long long x;
	int ord;
	bool is;
}a[N];
long long f[100];

bool cmp_x(Node a, Node b) { return a.x < b.x; }
bool cmp_ord(Node a, Node b) { return a.ord < b.ord; }

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		scanf("%lld", &a[cas].x);
		a[cas].ord = cas;
		a[cas].is = 0;
	}
	std::sort(a+1, a+1+T, cmp_x);
	f[0]=0;f[1]=1;
	int idx = 1;
	for(int i = 0; i <= 50; i++)
	{
		if(i > 1) f[i] = f[i-1] + f[i-2];
		while(a[idx].x < f[i] && idx <= T) idx++;
		while(a[idx].x == f[i])
		{
			a[idx].is = 1;
			idx++;
		}
	}
	std::sort(a+1, a+1+T, cmp_ord);
	for(int cas = 1; cas <= T; cas++)
		if(a[cas].is) puts("IsFibo");
		else puts("IsNotFibo");
	return 0;
}
