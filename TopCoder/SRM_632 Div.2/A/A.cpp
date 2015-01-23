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

class RunningAroundPark {
public:
	int numberOfLap(int, vector <int>);
};

int f[1010];

int RunningAroundPark::numberOfLap(int N, vector <int> d) {
	int ans = 0;
	int n = d.size();
	for(int i = 0; i < n; i++)
	{
		f[i] = 1;
		for(int j = 0; j < i; j++)
			if(d[i] <= d[j] && f[i] < f[j] + 1)
				f[i] = f[j] + 1;
		if(ans < f[i]) ans = f[i];
	}
	return ans;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
