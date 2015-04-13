#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <map>
using std::map;

const int N = 1000000 + 10;

int n, m;
map<int, int> cap;

inline int nextInt()
{
	char ch; int res = 0;
	while(!isdigit(ch = getchar()));
	do res = ((res << 1) + (res << 3)) + (ch - '0');
	while(isdigit(ch = getchar()));
	return res;
}

int main()
{
	while(scanf("%d%d", &n, &m) == 2)
	{
		cap.clear();
		for(int i = 1; i <= n; i++) cap[nextInt()]++;
		for(int i = 1; i <= m; i++)
		{
			int x = nextInt();
			printf("%d\n", cap[x]);
			cap.erase(x);
		}
	}
	return 0;
}
