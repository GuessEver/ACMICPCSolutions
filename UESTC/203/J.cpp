#include <cstdio>
#include <algorithm>

const int N = 1000 + 10;
const int Q = 100000 + 10;

int n, m, cap[N][N];
struct Node{
	int id, day;
	bool operator < (const Node &b) const
	{
		if(day == b.day) return id < b.id;
		return day > b.day;
	}
}a[N*N], b[N*N];
int d[Q], ans[Q], f[N*N];
int answer;

int getroot(int x) { return f[x] == x ? x : f[x] = getroot(f[x]); }

void solve(int idx)
{
	int neigh[4], len = 0;
	int root[4];
	if(idx % m != 0 && a[idx-1].day >= a[idx].day) neigh[len++] = idx - 1; // left
	if(idx % m != m - 1 && a[idx+1].day > a[idx].day) neigh[len++] = idx + 1; // right
	if(idx / m != 0 && a[idx-m].day >= a[idx].day) neigh[len++] = idx - m; // up
	if(idx / m != n - 1 && a[idx+m].day > a[idx].day) neigh[len++] = idx + m; // down
	for(int i = 0; i < len; i++) root[i] = getroot(neigh[i]);
	std::sort(root, root + len);
	int st = std::unique(root, root + len) - root;
	//printf("len = %d, st = %d\n", len, st);
	for(int i = 0; i < len; i++) f[getroot(idx)] = getroot(neigh[i]);
	for(int i = 0; i < len; i++) root[i] = getroot(neigh[i]);
	root[len++] = getroot(idx);
	std::sort(root, root + len);
	int ed = std::unique(root, root + len) - root;
	//printf("len = %d, ed = %d\n", len, ed);
	answer += (ed - st);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
			{
				scanf("%d", &cap[i][j]);
				a[i * m + j] = (Node){i * m + j, cap[i][j]};
				b[i * m + j] = a[i * m + j];
			}
		for(int i = 0; i < n * m; i++) f[i] = i;
		std::sort(b, b+n*m);
		//for(int i = 0; i < n * m; i++) printf("%3d ", a[i].id);puts("");
		//for(int i = 0; i < n * m; i++) printf("%3d ", a[i].day);puts("");
		int q; scanf("%d", &q);
		for(int i = 1; i <= q; i++) scanf("%d", &d[i]);
		int head = 0;
		answer = 0;
		for(int t = q; t >= 1; t--)
		{
			int day = d[t];
			while(head < n * m && b[head].day > day)
			{
				solve(b[head].id);
				head++;
	//			printf("answer = %d\n", answer);
			}
			ans[t] = answer;
			//for(int i = 0; i < n * m; i++) printf("%d ", f[i]); puts("");
		}
		for(int t = 1; t <= q; t++) printf("%d ", ans[t]);
		puts("");
	}
	return 0;
}
