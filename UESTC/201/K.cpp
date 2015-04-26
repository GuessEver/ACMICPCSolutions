#include <cstdio>
#include <algorithm>
#include <vector>
using std::vector;

const int N = 1000000 + 10;

int n, m, a[N];
int idx[N], L, R;
vector<int> res;

void solve_min()
{
	res.clear(); L = R = 0;
	for(int i = 1; i <= std::min(n, m) - 1; i++)
	{
		while(L < R && a[i] <= a[idx[R-1]]) R--;
		idx[R++] = i;
	}
	for(int i = m; i <= n; i++)
	{
		while(L < R && a[i] <= a[idx[R-1]]) R--;
		while(L < R && idx[L] <= i - m) L++;
		idx[R++] = i;
		res.push_back(a[idx[L]]);
	}
	for(vector<int>::iterator it = res.begin(); it < res.end(); it++)
		printf("%d%s", *it, it == res.end() - 1 ? "\n" : " ");
}

void solve_max()
{
	res.clear(); L = R = 0;
	for(int i = 1; i <= std::min(n, m) - 1; i++)
	{
		while(L < R && a[i] >= a[idx[R-1]]) R--;
		idx[R++] = i;
	}
	for(int i = m; i <= n; i++)
	{
		while(L < R && a[i] >= a[idx[R-1]]) R--;
		while(L < R && idx[L] <= i - m) L++;
		idx[R++] = i;
		res.push_back(a[idx[L]]);
	}
	for(vector<int>::iterator it = res.begin(); it < res.end(); it++)
		printf("%d%s", *it, it == res.end() - 1 ? "\n" : " ");
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	solve_min();
	solve_max();
	return 0;
}
