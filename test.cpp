#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using std::string;
int n;
char s[1000];
bool a[1000];
string all[10000];
int L = 0;

void solve()
{
	string tmp = "";
	for(int i = 0; i < n; i++)
		if(a[i]) tmp += s[i];
	all[L++] = tmp;
}

void dfs(int x)
{
	if(x == n)
	{
		solve();
		return;
	}
	dfs(x+1);
	a[x] = 1;
	dfs(x+1);
	a[x] = 0;
}

int main()
{
	while(scanf("%s", s) == 1)
	{
		L = 0;
		n = strlen(s);
		dfs(0);
		std::sort(all, all+L);
		int cnt = 0;
		for(int i = 0; i < L; i++)
			if(i == 0 || all[i] != all[i-1])
			{
				printf("%s\n", all[i].c_str());
				cnt++;
			}
		printf("Total = %d\n\n\n", cnt);
	}
	return 0;
}
