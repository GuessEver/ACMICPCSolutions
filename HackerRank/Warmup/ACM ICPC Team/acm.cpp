#include <cstdio>
#include <queue>
using std::priority_queue;

int n, m;
char s[600][600];
priority_queue<int> Q;

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%s", s[i]);
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
		{
			int tmp = 0;
			for(int k = 0; k < m; k++)
				if(s[i][k] == '1' || s[j][k] == '1') tmp++;
			Q.push(tmp);
		}
	int max_t = Q.top(), cnt = 0;
	while(!Q.empty() && Q.top() == max_t)
	{
		cnt++;
		Q.pop();
	}
	printf("%d\n%d\n", max_t, cnt);
}
