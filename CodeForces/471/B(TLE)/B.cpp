#include <cstdio>
#include <algorithm>

const int N = 2000 + 10;

int n;
struct Node{int pos, dif;}a[N];
int b[N][N];
int ans[10][N], DIF = 0;
int Total = 0;

bool cmp(Node a, Node b) 
{
	if(a.dif == b.dif) return a.pos < b.pos;
	return a.dif < b.dif;
}

void solve(int x)
{
	if(Total >= 3) return;
	if(x > DIF)
	{
		Total++;
		int cc = 0;
		for(int i = 1; i <= DIF; i++)
			for(int j = 1; j <= b[i][0]; j++)
				ans[Total][++cc] = b[i][j];
		return;
	}
	do{
		solve(x+1);
	}while(std::next_permutation(b[x]+1, b[x]+b[x][0]+1));
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i].dif);
		a[i].pos = i;
	}
	std::sort(a+1, a+1+n, cmp);
	int tot = 0, cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i].dif != a[i-1].dif)
		{
			++DIF;
			int x = ++b[DIF][0];
			b[DIF][x] = a[i].pos;
		}
		else{
			int x = ++b[DIF][0];
			b[DIF][x] = a[i].pos;
		}
	}
	solve(1);
	if(Total < 3) puts("NO");
	else{
		puts("YES");
		for(int cc = 1; cc <= 3; cc++)
		{
			for(int i = 1; i < n; i++) printf("%d ", ans[cc][i]);
			printf("%d\n", ans[cc][n]);
		}
	}
	return 0;
}
