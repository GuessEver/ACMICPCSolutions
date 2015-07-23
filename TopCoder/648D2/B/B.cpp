#include <vector>
#include <cstring>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Fragile2 {
public:
	int countPairs(vector <string>);
};

int n;
bool vis[100];
vector <string> G;

void dfs(int x)
{
	if(vis[x]) return;
	vis[x] = 1;
	for(int i = 0; i < n; i++)
		if(G[x][i] == 'Y') dfs(i);
}

int solve(int x, int y)
{
	memset(vis, 0, sizeof(vis));
	vis[x] = vis[y] = 1;
	int res = 0;
	for(int i = 0; i < n; i++)
		if(!vis[i])
		{
			dfs(i);
			res++;
		}
	return res;
}

int Fragile2::countPairs(vector <string> graph) {
	G = graph;
	n = graph.size();
	int pre = 0;
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < n; i++)
		if(!vis[i])
		{
			dfs(i);
			pre++;
		}
	int cnt = 0;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			if(solve(i, j) > pre) cnt++;
	return cnt;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
