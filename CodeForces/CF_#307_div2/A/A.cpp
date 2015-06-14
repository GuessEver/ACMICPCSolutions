#include <cstdio>
#include <algorithm>

const int N = 2000 + 10;

struct Node{
	int score, idx, ord;
}a[N];
int n;

bool cmp_i(Node a, Node b) { return a.idx < b.idx; }
bool cmp_s(Node a, Node b) { return a.score > b.score; }

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i].score);
		a[i].idx = i;
	}
	std::sort(a+1, a+1+n, cmp_s);
	a[1].ord = 1;
	for(int i = 2; i <= n; i++)
	{
		if(a[i].score == a[i-1].score) a[i].ord = a[i-1].ord;
		else a[i].ord = i;
	}
	std::sort(a+1, a+1+n, cmp_i);
	for(int i = 1; i < n; i++) printf("%d ", a[i].ord);
	printf("%d\n", a[n].ord);
	return 0;
}
