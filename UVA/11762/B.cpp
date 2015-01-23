#include <cstdio>
#include <cstring>

const int N = 1000000 + 10;

int n;
int pri[N], Cnt = 0;
bool flag[N];
double f[N];
bool vis[N];

void make_prime_list()
{
	for(int i = 2; i <= N; i++)
	{
		if(!flag[i]) pri[Cnt++] = i;
		for(int j = 0; j < Cnt && i * pri[j] <= N; j++)
		{
			flag[i*pri[j]] = 1;
			if(i % pri[j] == 0) break;
		}
	}
	//for(int i = 0; i < 100; i++) printf("%d ", pri[i]);
}

double dfs(int x)
{
	if(x == 1) return 0;
	if(vis[x]) return f[x];
	vis[x] = 1; f[x] = 1;
	double sum = 0;
	int tot = 0, cnt = 0;
	for(int i = 0; i < Cnt && pri[i] <= x; i++)
	{
		if(x % pri[i] == 0)
		{
			sum += dfs(x / pri[i]);
			cnt++;
		}
		tot++;
	} // If you cannot understand the following formula,
		//look at the picture in the same package
	return f[x] = (sum + tot) / cnt;
}

int main()
{
	make_prime_list();
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		memset(vis, 0, sizeof(vis));
		printf("Case %d: ", cas);
		scanf("%d", &n);
		printf("%.8lf\n", dfs(n));
	}
	return 0;
}
