#include <cstdio>
#include <queue>
using std::priority_queue;

priority_queue<int> Q;
int tmp[10100];
char op[100];
int cnt, n;

void ask()
{
	if(!cnt) { printf("Empty!\n"); return; }
	int tt = cnt / 2;
	for(int j = 1; j <= tt; j++)
	{
		tmp[j] = Q.top();
		Q.pop();
	}
	if(cnt % 2 == 1) printf("%d\n", Q.top());
	else{
		int res = tmp[tt] + Q.top();
		printf("%d", res/2);
		if(res % 2 == 1) printf(".5");
		printf("\n");
	}
	for(int j = 1; j <= tt; j++) Q.push(tmp[j]);
}

void solve()
{
	scanf("%d", &n);
	cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		int x;
		scanf("%s%d", op, &x);
		if(op[0] == 'a')
		{
			Q.push(x);
			cnt++;
			ask();
		}
		else{
			bool flag = 0;
			int tt = 0;
			while(!Q.empty())
			{
				if(Q.top() == x){ Q.pop(); flag = 1; break; }
				else {tmp[++tt] = Q.top(); Q.pop();}
			}
			for(int j = 1; j <= tt; j++) Q.push(tmp[j]);
			if(flag){ cnt--; ask(); }
			else printf("Wrong!\n");
		}
	}
}

int main()
{
	freopen("B.in", "r", stdin);
	freopen("ppp.out", "w", stdout);
	int T; scanf("%d", &T);
	while(T--)
	{
		while(!Q.empty()) Q.pop();
		solve();
	}
	return 0;
}
