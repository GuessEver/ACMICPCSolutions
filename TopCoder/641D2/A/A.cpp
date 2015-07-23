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

class BuyingTshirts {
public:
	int meet(int, vector <int>, vector <int>);
};

int BuyingTshirts::meet(int T, vector <int> Q, vector <int> P) {
	int n = Q.size();
	int x = 0, y = 0, cnt = 0;
	for(int i = 0; i < n; i++)
	{
		x += Q[i];
		y += P[i];
		if(x >= T && y >= T) cnt++;
		if(x >= T) x -= T;
		if(y >= T) y -= T;
	}
	return cnt;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
