#include <cstdio>
#include <stack>
#include <vector>
using std::vector;
using std::stack;

const int N = 2 * 100000 + 10;

stack<int> st[N];
int n;
vector<int> ans;

bool solve()
{
	int now = 0;
	for(int i = 1; i <= n; i++)
	{
		while(now >= 3 && st[now].empty()) now -= 3;
		if(st[now].empty()) return 0;
		//printf("%d ", st[now].top());
		ans.push_back(st[now].top());
		st[now].pop();
		now++;
	}
	return 1;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		st[x].push(i);
	}
	if(!solve()) puts("Impossible");
	else{
		puts("Possible");
		for(vector<int>::iterator it = ans.begin(); it < ans.end(); it++)
			printf("%d ", *it);
		puts("");
	}
	return 0;
}
