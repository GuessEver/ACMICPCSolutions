#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <stack>
using std::stack;

const int N = 80 * 80;
inline int Get(char a)
{
	if(isdigit(a)) return a - '0'; // 0 ~ 9
	if(islower(a)) return a - 'a' + 10; // 10 ~ 35
	return a - 'A' + 36; // 36 ~ 61
}
inline int getId(char a, char b) { return Get(a) * 70 + Get(b); }
inline char Back(int x)
{
	if(x >= 36) return x - 36 + 'A';
	if(x >= 10) return x - 10 + 'a';
	return x + '0';
}

int g[N][N];
int L = 0, in[N], ou[N], n, m;
bool vis[4 * 100000 + 10];
int cnt = 0;
stack<int> ans;
int circle[N];

inline void inLink(int x, int y)
{
	if(x == y) 
	{
		circle[x]++;
		return;
	}
	in[y]++; ou[x]++;
	g[x][y]++; L++;
}

void dfs(int x)
{
	for(int i = 0; i < n; i++) if(g[x][i])
	{
		cnt++; g[x][i]--;
		dfs(i);
	}
	ans.push(x);
}

char ans_string[4*100000+10];
int ans_len = 0;

bool printAns()
{
	if(cnt != L) return 0;
	bool flag = 1;
	while(!ans.empty())
	{
		int x = ans.top(); ans.pop();
		if(flag)
		{
			ans_string[ans_len++] = Back(x / 70);
			flag = 0;
		}
		ans_string[ans_len++] = Back(x % 70);
		for(int i = 1; i <= circle[x]; i++) ans_string[ans_len++] = Back(x % 70);
		circle[x] = 0;
	}
	for(int i = 0; i < n; i++) if(circle[i])
	{
		if(ans_len) return 0;
		for(int j = 1; j <= circle[i] + 2; j++) ans_string[ans_len++] = Back(i / 70);
	}
	puts("YES");
	ans_string[ans_len] = 0; puts(ans_string);
	return 1;
}

bool Solve()
{
	int first = 0, second = 0;
	for(int i = 0; i < n; i++)
	{
		if(in[i] == ou[i]) continue;
		else if(in[i] + 1 == ou[i]) first++;
		else if(in[i] == ou[i] + 1) second++;
		else return 0;
	}
	if(first == 0 && second == 0)
	{
		for(int i = 0; i < n; i++)
			if(in[i] && in[i] == ou[i]) { dfs(i); break; }
	}
	else if(first == 1 && second == 1)
	{
		for(int i = 0; i < n; i++)
			if(in[i] + 1 == ou[i]) dfs(i);
	}
	return printAns();
}

int main()
{
	scanf("%d", &m); n = 71 * 71;
	for(int i = 1; i <= m; i++)
	{
		char a, b, c; scanf(" %c %c %c", &a, &b, &c);
		inLink(getId(a, b), getId(b, c));
	}
	if(!Solve()) puts("NO");
	return 0;
}
