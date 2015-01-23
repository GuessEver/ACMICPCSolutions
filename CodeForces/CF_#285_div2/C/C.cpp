#include <cstdio>
#include <queue>
#include <algorithm>
using std::queue;

const int N = (1<<16) + 10;

int n, deg[N], Sxor[N];
queue<int> Q;
struct EG{
	int from, to;
}edge[N];
int L;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d", &deg[i], &Sxor[i]);
		if(deg[i] == 1) Q.push(i);
	}
	while(!Q.empty())
	{
		int k = Q.front(); Q.pop();
		if(!deg[k]) continue;
		int y = Sxor[k];
		Sxor[y] ^= k; deg[y]--; deg[k]--;
		if(deg[y] == 1) Q.push(y);
		//printf("! %d %d\n", k, y);
		edge[L].from = k; edge[L].to = y; L++;
		//printf("%d : deg = %d , Sxor = %d\n", k, deg[k], Sxor[k]);
		//printf("%d : deg = %d , Sxor = %d\n", y, deg[y], Sxor[y]);
	}
	printf("%d\n", L);
	for(int i = 0; i < L; i++) printf("%d %d\n", edge[i].from, edge[i].to);
	return 0;
}
