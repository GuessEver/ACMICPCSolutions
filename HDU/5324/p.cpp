#include <cstdio>
#include <vector>
using std::vector;

const int N = 50000 + 10;
struct Node{
	int x, y;
}a[N];
int n;
vector<int> v1, v2;
int pre[N];
int f[N];

void getMin(int p)
{
	if((int)v1.size() == 0) v1 = v2;
	else{
		for(int i = p - 1; i >= 0; i--) if(v2[i] < v1[i])
		{
			v1 = v2;
			return;
		}
	}
}
int main()
{
	//freopen("I.in", "r", stdin);
	while(scanf("%d", &n) == 1)
	{
		for(int i = 1; i <= n; i++) scanf("%d", &a[i].x);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i].y);
		for(int i = 1; i <= n; i++) f[i] = 1, pre[i] = -1;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j < i; j++)
				if(a[i].x <= a[j].x && a[i].y >= a[j].y && f[j] + 1 > f[i])
				{
					f[i] = f[j] + 1;
					pre[i] = j;
				}
		int res = 0;
		for(int i = 1; i <= n; i++) res = std::max(res, f[i]);
		printf("%d\n", res);
		v1.clear();
		for(int i = 1; i <= n; i++) if(f[i] == res)
		{
			v2.clear();
			for(int S = i; S != -1; S = pre[S]) v2.push_back(S);
			getMin(res);
		}
		for(int i = res - 1; i >= 0; i--) printf("%d%s", v1[i], i == 0 ? "\n" : " ");
	}
	return 0;
}
