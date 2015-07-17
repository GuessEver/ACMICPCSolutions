#include <cstdio>
#include <cmath>
#include <algorithm>

int sum, limit, maxk;
struct Node{
	int x, lowbit;
}a[100000+10];
int Cnt, ans[100000+10];

bool cmp(Node a, Node b) { return a.lowbit > b.lowbit; }

int main()
{
	scanf("%d%d", &sum, &limit);
	for(int i = 1; i <= limit; i++) a[i].x = i, a[i].lowbit = (i&-i);
	//for(int i = 1; i <= limit; i++) printf("%d %d\n", i, a[i]);
	std::sort(a+1, a+1+limit, cmp);
	int idx = 1;
	while(idx <= limit && sum)
	{
		while(a[idx].lowbit > sum) idx++;
		sum -= a[idx].lowbit;
		ans[Cnt++] = a[idx].x;
		idx++;
	}
	if(sum != 0) { puts("-1"); return 0; }
	printf("%d\n", Cnt);
	for(int i = 1; i < Cnt; i++) printf("%d ", ans[i]);
	printf("%d\n", ans[0]);
	return 0;
}
