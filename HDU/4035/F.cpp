#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using std::vector;

const int N = 10000 + 10;
const double eps = 1e-10;
/*
   eps = 1e-7  ->  WA
   eps = 1e-8  ->  TLE
   eps = 1e-9  ->  AC
   eps = 1e-10 ->  AC
   .....hehe
*/

int n;
double k[N], e[N];
vector<int> path[N];
double A[N], B[N], C[N];
bool vis[N];

void dfs(int x)
{
	vis[x] = 1;
	bool isleaf = 1;
	double sigmaAj = 0.0, sigmaBj = 0.0, sigmaCj = 0.0;
	for(vector<int>::iterator it = path[x].begin(); it < path[x].end(); it++)
		if(!vis[*it])
		{
			dfs(*it);
			isleaf = 0;
			sigmaAj += A[*it];
			sigmaBj += B[*it];
			sigmaCj += C[*it];
		}
	//printf("%d : %d\n", x, isleaf);
	double base = (1.0 - k[x] - e[x]) / path[x].size();
	if(isleaf)
	{
		A[x] = k[x];
		B[x] = 1.0 - k[x] - e[x];
		C[x] = 1.0 - k[x] - e[x];
	}
	else{
		A[x] = (k[x] + base * sigmaAj) / (1.0 - base * sigmaBj);
		B[x] = base / (1.0 - base * sigmaBj);
		C[x] = (base * sigmaCj + (1.0 - k[x] - e[x])) / (1.0 - base * sigmaBj);
	}
}

int main()
{
	int T, cas = 0; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) path[i].clear();
		for(int i = 1; i < n; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			path[x].push_back(y);
			path[y].push_back(x);
		}
		for(int i = 1; i <= n; i++)
		{
			scanf("%lf%lf", &k[i], &e[i]);
			k[i] /= 100.0;
			e[i] /= 100.0;
		}
		memset(vis, 0, sizeof(vis));
		dfs(1);
		if(fabs(A[1] - 1.0) < eps) printf("Case %d: impossible\n", ++cas);
		else printf("Case %d: %.6f\n", ++cas, C[1] / (1.0 - A[1]));
	}
	return 0;
}
