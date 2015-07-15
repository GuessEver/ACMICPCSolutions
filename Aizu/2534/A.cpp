#include <cstdio>
#include <cstring>
#include <queue>
using std::queue;

const int N = 500 + 10;

int n;
char s[N][20];
int g[255][255];
int deg[255];
queue<int> Q;

bool topsort()
{
	while(!Q.empty()) Q.pop();
	for(int i = 0; i < 255; i++) if(deg[i] == 0) Q.push(i);
	int cnt = 0;
	while(!Q.empty())
	{
		int x = Q.front(); Q.pop(); cnt++;
		for(int i = 0; i < 255; i++)
			if(g[x][i] == 1)
			{
				deg[i]--;
				if(deg[i] == 0) Q.push(i);
			}
	}
	//printf("cnt = %d\n", cnt);
	return cnt == 255;
}

bool solve()
{
	memset(g, 0, sizeof(g));
	memset(deg, 0, sizeof(deg));
	for(int i = 2; i <= n; i++)
	{
		for(int j = 0; s[i][j] || s[i-1][j]; j++)
		{
			if(s[i][j] == s[i-1][j]) continue;
			if(!s[i][j]) return 0;
			char lesser = s[i-1][j], larger = s[i][j];
			if(g[larger][lesser] == 1) return 0;
			if(g[lesser][larger] == 0)
			{
				g[lesser][larger] = 1;
				deg[larger]++;
			}
			break;
		}
	}
	return topsort();
}

int main()
{
	while(scanf("%d", &n) == 1 && n)
	{
		memset(s, 0, sizeof(s));
		for(int i = 1; i <= n; i++) scanf("%s", s[i]);
		if(solve()) puts("yes"); else puts("no");
	}
	return 0;
}
