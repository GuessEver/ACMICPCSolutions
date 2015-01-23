#include <cstdio>
#include <algorithm>
using std::sort;

int a[10];

int solve()
{
	int x1, x2;
	if(a[1] == a[2] && a[2] == a[3] && a[3] == a[4])
	{
		x1 = a[5]; x2 = a[6];
	}
	else if(a[2] == a[3] && a[3] == a[4] && a[4] == a[5])
	{
		x1 = a[1]; x2 = a[6];
	}
	else if(a[3] == a[4] && a[4] == a[5] && a[5] == a[6])
	{
		x1 = a[1]; x2 = a[2];
	}
	else return 0;
	if(x1 == x2) return 2;
	else return 1;
}

int main()
{
	for(int i = 1; i <= 6; i++) scanf("%d", &a[i]);
	sort(a+1, a+7);
	int J = solve();
	if(J == 1) puts("Bear");
	else if(J == 2) puts("Elephant");
	else puts("Alien");
	return 0;
}
