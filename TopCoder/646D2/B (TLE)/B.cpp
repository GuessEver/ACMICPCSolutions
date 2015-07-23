#include <vector>
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

class TheGridDivTwo {
public:
	int find(vector <int>, vector <int>, int);
};

int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
int cap[3000][3000];
int answer = 0;
int maxtime;

void dfs(int x, int y, int steps)
{
	if(steps > maxtime) return;
	if(x > answer) answer = x;
	if(x + (maxtime - steps) <= answer) return;
	for(int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(cap[nx+1000][ny+1000]) continue;
		dfs(nx, ny, steps+1);
	}
}

int TheGridDivTwo::find(vector <int> x, vector <int> y, int k) {
	int m = x.size();
	maxtime = k;
	for(int i = 0; i < m; i++) cap[x[i]+1000][y[i]+1000] = 1;
	dfs(0, 0, 0);
	return answer;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
