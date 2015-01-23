#include <cstdio>
#include <queue>
#include <vector>
using std::priority_queue;
using std::vector;
using std::greater;

int n;
priority_queue<int, vector<int>, greater<int> > Q;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int a; scanf("%d", &a);
		Q.push(a);
	}
	int sub = 0;
	while(!Q.empty())
	{
		while(!Q.empty() && Q.top() == sub) Q.pop();
		sub = Q.top();
		if(Q.empty()) break;
		printf("%d\n", (int)Q.size());
	}
	return 0;
}
