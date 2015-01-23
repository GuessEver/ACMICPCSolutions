#include <cstdio>
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

const int N = 1000 + 10;

int n, m, w[N], b[N];
int res[N];
bool done[N];
int st[N*N], len;

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
	for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
	int cc = 0;
	for(int i = 1; i <= m; i++)
	{
		if(done[b[i]]) continue;
		done[b[i]] = 1;
		res[++cc] = b[i];
		if(cc == n) break;
	}
	for(int i = cc; i > 0; i--)
		st[++len] = res[i];
	long long ans = 0;
	for(int i = 1; i <= m; i++)
	{
		memset(done, 0, sizeof(done));
		for(int j = len; j > 0; j--)
		{
			if(st[j] == b[i]) break;
			if(done[st[j]]) continue;
			ans += w[st[j]];
			done[st[j]] = 1;
		}
		st[++len] = b[i];
	}
	cout << ans << endl;
	return 0;
}
