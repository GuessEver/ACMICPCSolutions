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
#include <queue>

using namespace std;

class TravellingSalesmanEasy {
public:
	int getMaxProfit(int, vector <int>, vector <int>, vector <int>);
};

priority_queue<int> Q[200];

int TravellingSalesmanEasy::getMaxProfit(int M, vector <int> profit, vector <int> city, vector <int> visit) {
	int n = city.size();
	for(int i = 0; i < n; i++)
		Q[city[i]].push(profit[i]);
	int q = visit.size();
	int res = 0;
	for(int i = 0; i < q; i++)
	{
		if(Q[visit[i]].empty()) continue;
		res += Q[visit[i]].top();
		Q[visit[i]].pop();
	}
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
