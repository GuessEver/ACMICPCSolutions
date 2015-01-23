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

class GoodSubset {
public:
	int numberOfSubsets(int, vector <int>);
};

const int mod = 1000000007;
int ans = 0;

void dfs(int x, vector<int> &d, int &goodValue, int &n, long long now)
{
	if(x != 1 && now == goodValue) ans++;
	if(x != 1 && now >= goodValue) return;
	if(x >= n) return;
	dfs(x+1, d, goodValue, n, now);
	dfs(x+1, d, goodValue, n, now * d[x] % mod);
}

int GoodSubset::numberOfSubsets(int goodValue, vector <int> d) {
	int n = d.size();
	sort(d.begin(), d.end());
	dfs(0, d, goodValue, n, 1LL);
	return ans;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
