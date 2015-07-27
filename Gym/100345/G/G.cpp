#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using std::priority_queue;
using std::vector;
using std::greater;

const int N = 100000 + 10;

int n;
struct Node{
	int r, c;
	bool operator < (const Node &b) const
	{
		return r < b.r;
	}
}a[N];
priority_queue<long long, vector<long long>, greater<long long> > Q;

int main()
{
	freopen("pulp.in", "r", stdin);
	freopen("pulp.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[i].r, &a[i].c);
		a[i].r++;
	}
	std::sort(a+1, a+1+n);
	long long res = 0;
	for(int i = 1; i <= n; i++)
	{
		Q.push(a[i].c);
		if(i < n)
		{
			long long day = a[i].r;
			while(!Q.empty() && day < a[i+1].r)
			{
				long long now = Q.top(); Q.pop();
				if(day + now - 1 >= a[i+1].r) // a[i+1].r - day + 1 [ day, a[i+1].r ]
				{
					now -= a[i+1].r - day;
					day = a[i+1].r;
					Q.push(now);
				}
				else if(day + now - 1 < a[i+1].r)
				{
					day = day + now;
					now = 0; res += day - 1;
				}
			}
		}
		else {
			long long day = a[i].r;
			while(!Q.empty())
			{
				long long now = Q.top(); Q.pop();
				day += now;
				res += day - 1;
			}
		}
	}
	printf("%I64d\n", res);
	return 0;
}
