#include <cstdio>
#include <vector>
#include <algorithm>
using std::vector;

const int N = 100000 + 10;

int n, a[N], maxp;
vector<int> v[N];
int cnt[N];

int solve(int tar)
{
	int res = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < v[i].size(); j++)
			if(v[i][j] == tar)
			{
				res += j;
				break;
			}
	int tmp = res;
	for(tar *= 2; tar <= maxp; tar *= 2)
	{
		tmp = tmp - cnt[tar] + (n - cnt[tar]);
		if(tmp < res) res = tmp;
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] > maxp) maxp = a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		for(int x = a[i]; x != 1; x /= 2)
		{
			v[i].push_back(x);
			cnt[x]++;
		}
		v[i].push_back(1); cnt[1]++;
	}
	/*for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < v[i].size(); j++) printf("%d ", v[i][j]);
		puts("");
	}*/
	int res = -1;
	for(int i = 1; i <= 100000; i++) if(cnt[i] == n)
	{
		int tmp = solve(i);
		if(res == -1 || tmp < res) res = tmp;
	}
	printf("%d\n", res);
	return 0;
}
