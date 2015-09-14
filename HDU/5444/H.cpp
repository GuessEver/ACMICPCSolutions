#include <cstdio>
#include <cstring>
const int N = 1000 + 10;
char ans[N][N]; int len[N];
int A[N], L[N], R[N], total, root;
int n, q;

void insert(int &p, int x)
{
	if(!p)
	{
		p = ++total;
		A[p] = x;
		L[p] = R[p] = 0;
		return;
	}
	if(x < A[p]) 
	{
		ans[x][len[x]++]='E';
		insert(L[p], x);
	}
	else {
		ans[x][len[x]++]='W';
		insert(R[p], x);
	}
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n); total = root = 0;
		memset(ans, 0, sizeof(ans));
		memset(len, 0, sizeof(len));
		for(int i = 1; i <= n; i++)
		{
			int x; scanf("%d", &x);
			insert(root, x);
		}
		scanf("%d", &q);
		for(int i = 1; i <= q; i++)
		{
			int x; scanf("%d", &x);
			puts(ans[x]);
		}
	}
	return 0;
}
