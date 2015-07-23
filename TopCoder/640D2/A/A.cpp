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

class ChristmasTreeDecorationDiv2 {
public:
	int solve(vector <int>, vector <int>, vector <int>);
};

int ChristmasTreeDecorationDiv2::solve(vector <int> col, vector <int> x, vector <int> y) {
	int n = col.size();
	int res = 0;
	for(int i = 0; i < n - 1; i++)
	{
		int a = x[i] - 1;
		int b = y[i] - 1;
		res += (col[a] != col[b]);
	}
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
