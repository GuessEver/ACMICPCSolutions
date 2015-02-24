#include <cstdio>
#include <string>
using std::string;

int n;
string cap[20][2];
char tmp1[100], tmp2[100];
string S, T;
int best = 0;

bool change(string now, string &next, int k)
{
	bool flag = 0;
	next = "";
	while(1)
	{
		int pos = now.find(cap[k][0]);
		if(pos == -1) break;
		flag = 1;
		for(int i = 0; i < pos; i++)
		{
			next += now[0];
			now.erase(0, 1);
		}
		next += cap[k][1];
		now.erase(0, cap[k][0].length());
	}
	next += now;
	//puts(next.c_str());
	return flag;
}

void dfs(string now, int step)
{
	if(now.length() > T.length()) return;
	if(best != -1 && step >= best) return;
	if(now == T)
	{
		best = step;
		return;
	}
	string next;
	for(int i = 1; i <= n; i++)
	{
		if(!change(now, next, i)) continue;
		dfs(next, step+1);
	}
}

int main()
{
	while(scanf("%d", &n) == 1 && n)
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%s%s", tmp1, tmp2);
			cap[i][0] = string(tmp1);
			cap[i][1] = string(tmp2);
		}
		scanf("%s%s", tmp1, tmp2);
		S = tmp1; T = tmp2; best = -1;
		dfs(S, 0);
		printf("%d\n", best);
	}
	return 0;
}
