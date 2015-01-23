#include <cstdio>
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;

const int N = 2 * 100000 + 10;

int n, m;
struct Node{int d, t;}a[N*3];

bool cmp(Node a, Node b)
{
	return a.d < b.d;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i].d);
		a[i].t = 1;
	}
	scanf("%d", &m);
	for(int i = n+1; i <= n+m; i++)
	{
		scanf("%d", &a[i].d);
		a[i].t = 2;
	}
	std::sort(a+1, a+1+n+m, cmp);
	long long A = 3ll * n, B = 3ll * m;
	long long ansA = -1, ansB = -1, AB = -0x3f3f3f3f3f3f3f3fll;
	for(int i = 1; i <= n + m + 1;)
	{
		long long sub = A - B;
		if(sub > AB || (sub == AB && A > ansA))
		{
			ansA = A; ansB = B;
			AB = sub;
		}
		if(a[i].t == 1) A--; else B--;
		while(i <= n + m + 1 && a[i+1].d == a[i].d)
		{
			i++;
			if(a[i].t == 1) A--; else B--;
		}
		i++;
	}
	cout << ansA << ':' << ansB << endl;
	return 0;
}
