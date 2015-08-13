#include <cstdio>
#include <cstring>
#include <stack>
using std::stack;
const int N = 100 + 10;
const int M = 500 + 10;

int n, m;
struct Matrix{
	int a[N][N];
	void Read()
	{
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				scanf("%d", &a[i][j]);
	}
}A, B;
int cnt[2][N][N];
struct OP{
	int op, x, y;
	OP() {}
	OP(int _op, int _x, int _y) { op = _op; x = _x; y = _y; }
	void Read()
	{
		char tmp; scanf(" %c", &tmp);
		if(tmp == 'L') op = 0; else op = 1;
		scanf("%d%d", &x, &y);
		cnt[op][x][y]++;
	}
	bool operator == (const OP &b) const
	{
		return op == b.op && x == b.x && y == b.y;
	}
}op[M];
stack<OP> st;

bool findL()
{
	int op = 0, x = 0, y = 0; bool flag = 1;
	for(int j = 1; j <= n; j++)
	{
		y = 0; flag = 1;
		for(int i = 1; i <= n; i++)
		{
			if(B.a[i][j] == 0) continue;
			if(y == 0) y = B.a[i][j];
			if(y != B.a[i][j]) { flag = 0; break; }
		}
		if(y == 0 || !flag) continue;
		else { x = j; break; }
	}
	if(!flag || x == 0) return 0;
	if(cnt[op][x][y])
	{
		//printf("###: L %d %d\n", x, y);
		st.push(OP(op, x, y));
		cnt[op][x][y]--;
		for(int i = 1; i <= n; i++) B.a[i][x] = 0;
		return 1;
	}
	return 0;
}
bool findH()
{
	int op = 1, x = 0, y = 0; bool flag = 1;
	for(int i = 1; i <= n; i++)
	{
		y = 0; flag = 1;
		for(int j = 1; j <= n; j++)
		{
			if(B.a[i][j] == 0) continue;
			if(y == 0) y = B.a[i][j];
			if(y != B.a[i][j]) { flag = 0; break; }
		}
		if(y == 0 || !flag) continue;
		else { x = i; break; }
	}
	if(!flag || x == 0) return 0;
	if(cnt[op][x][y])
	{
		//printf("###: H %d %d\n", x, y);
		st.push(OP(op, x, y));
		cnt[op][x][y]--;
		for(int j = 1; j <= n; j++) B.a[x][j] = 0;
		return 1;
	}
	return 0;
}

bool vis[M];
int rank[M];

void Solve()
{
	bool flag = 1;
	while(flag)
	{
		flag = 0;
		flag |= findL();
		flag |= findH();
	}
	for(int i = 1; i <= m; i++)
		if(cnt[op[i].op][op[i].x][op[i].y])
		{
			//printf("###: %s %d %d\n", op[i].op == 0 ? "L" : "H", op[i].x, op[i].y);
			st.push(op[i]);
			cnt[op[i].op][op[i].x][op[i].y]--;
		}
	memset(vis, 0, sizeof(vis));
	memset(rank, 0, sizeof(rank));
	int R = 0;
	while(!st.empty())
	{
		OP now = st.top(); st.pop();
		for(int i = 1; i <= m; i++) if(!vis[i])
			if(now == op[i])
			{
				vis[i] = 1;
				rank[++R] = i;
				break;
			}
	}
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		memset(cnt, 0, sizeof(cnt));
		scanf("%d%d", &n, &m);
		A.Read(); B.Read();
		for(int i = 1; i <= m; i++) op[i].Read();
		Solve();
		for(int i = 1; i <= m; i++) printf("%d%s", rank[i], i == m ? "\n" : " ");
	}
	return 0;
}
