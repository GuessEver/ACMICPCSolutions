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

class Target {
public:
	vector <string> draw(int);
};

vector <string> s;
string tmp;

void dfs(int x1, int y1, int x2, int y2)
{
	for(int i = y1; i <= y2; i++) s[x1][i] = s[x2][i] = '#';
	for(int i = x1; i <= x2; i++) s[i][y1] = s[i][y2] = '#';
	if(x1 == x2 && y1 == y2) return;
	dfs(x1+2, y1+2, x2-2, y2-2);
}


vector <string> Target::draw(int n) {
	for(int j = 0; j < n; j++) tmp += ' ';
	for(int i = 0; i < n; i++) s.push_back(tmp);
	dfs(0, 0, n-1, n-1);
	return s;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
