#include <stdio.h>
#include <algorithm>

using namespace std;
const int N= 100000+10;
int n;
struct node
{
		int e, l, r;
		void in()
		{
				scanf("%d%d%d", &e, &l, &r);
		}
}e[N];
bool operator < (node a, node b)
{
	return a.l < b.l;
}
int main()
{
		int T;
		scanf("%d", &T);
		for(int cas = 1; cas <= T; cas++)
		{
				scanf("%d", &n);
				for(int i = 0;  i < n; i++)
				{
						e[i].in();
				}
				sort(e, e + n);
				int time = 0, last = 0;
				bool flag = true;
				for(int i = 0; i < n; i++)
				{
						time += e[i].l - last;
						if(time >= e[i].e)
						{
								time -= e[i].e;
						}
						else
						{
								flag = false;
								break;
						}
						last = e[i].l + e[i].r;

				}
				printf("Case #%d: %s\n", cas, flag ? "YES" : "NO");
		}
		return 0;
}
