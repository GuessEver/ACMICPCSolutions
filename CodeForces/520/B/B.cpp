#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using std::queue;

int vis[100010], n, m;
struct Node{int x, steps;};
queue<Node> Q;

bool expand(Node x, Node &y, int k)
{
	y = x; y.steps++;
	if(k == 0) y.x -= 1;
	else y.x *= 2;
	if(y.x < 0 || y.x > std::max(n, m) * 2) return 0;
	return 1;
}

int BFS()
{
	Node S; S.x = n; S.steps = 0;
	Q.push(S);
	while(!Q.empty())
	{
		Node y, x = Q.front(); Q.pop();
		for(int k = 0; k < 2; k++)
			if(expand(x, y, k))
			{
				if(y.x == m) return y.steps;
				if(!vis[y.x])
				{
					vis[y.x] = 1;
					Q.push(y);
				}
			}
	}
	return -1;
}

int main()
{
	scanf("%d%d", &n, &m);
	printf("%d\n", BFS());
	return 0;
}
