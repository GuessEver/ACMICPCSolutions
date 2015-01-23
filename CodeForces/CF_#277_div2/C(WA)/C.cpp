#include <cstdio>
#include <cstdlib>
#include <algorithm>
using std::lower_bound;

int n, p;
char s[100100];
struct Node{
	int pos, w;
	bool operator < (const Node &b) const
	{
		return pos < b.pos;
	}
}a[100100];
int Cnt = 0;
int done = 0;
int next[100100], pre[100100], ok[100100];

int get(int a)
{
	int b = 26 - a;
	return std::min(a, b);
}

int compare(int p, int k1, int k2)
{
	if(abs(a[k1].pos - p) < abs(a[k2].pos - p)) return k1;
	return k2;
}

int find(int pos)
{
	int low = 0, high = Cnt;
	while(low < high)
	{
		int mid = (low + high) / 2;
		if(a[mid].pos < pos) low = mid + 1;
		else high = mid;
	}
	return std::min(high, Cnt-1);
}

int solve()
{
	int k = find(p);
	if(ok[k]) k = next[k];
	if(!ok[pre[k]]) k = compare(p, pre[k], k);
	ok[k] = 1; pre[next[k]] = pre[k]; next[pre[k]] = next[k];
	int dis = abs(a[k].pos - p); 
	//printf("p = %d, pos = %d, dis = %d, w = %d, done = %d\n", p, a[k].pos, dis, a[k].w, done+1);
	p = a[k].pos; done++;
	return dis + a[k].w;
}

int main()
{
	scanf("%d%d", &n, &p);
	scanf("%s", s+1);
	if(p > n/2) p = n - p + 1;
	for(int i = 1, j = n; i < j; i++, j--)
		if(s[i] - s[j])
		{
			a[Cnt].pos = i;
			a[Cnt++].w = get(abs(s[i] - s[j]));
		}
	std::sort(a, a+Cnt);
	for(int i = 0; i < Cnt-1; i++) next[i] = i + 1;
	for(int i = 1; i < Cnt; i++) pre[i] = i - 1;
	long long ans = 0;
	while(done < Cnt)
	{
		int tmp = solve();
		ans += tmp;
		//printf("solve() = %d\n", tmp);
	}
	printf("%I64d\n", ans);
	return 0;
}
