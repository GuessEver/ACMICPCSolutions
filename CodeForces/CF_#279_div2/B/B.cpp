#include <cstdio>
#include <algorithm>
using std::max;
const int N = 2 * 1000000 + 10;

int n;
int pre[N], next[N];
int maxp;

int main()
{
	scanf("%d", &n);
	int root1 = 0, root2 = 0, tail1 = 0, tail2 = 0, second = 0;
	for(int i = 1; i <= n; i++)
	{
		int a, b; scanf("%d%d", &a, &b);
		next[a] = b; pre[b] = a;
		if(a == 0) root2 = b;
		if(b == 0) tail1 = a;
		maxp = max(maxp, max(a, b));
	}
	for(int i = 1; i <= maxp; i++)
	{
		if(!next[i] && pre[i] && i != tail1) tail2 = i;
		if(next[i] && !pre[i] && i != root2) root1 = i;
	}
	//printf("%d %d\n", tail1, root2);
	int now = 0;
	if(n == 2) printf("%d %d\n", tail1, root2);
	else while(root1 || root2)
	{
		if(root1)
		{
			now = root1;
			printf("%d ", root1);
			root1 = next[root1];
		}
		if(root2)
		{
			now = root2;
			printf("%d ", root2);
			root2 = next[root2];
		}
	}
	puts("");
	return 0;
}
