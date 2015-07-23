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

class MountainRanges {
public:
	int countPeaks(vector <int>);
};

int MountainRanges::countPeaks(vector <int> heights) {
	int n = heights.size();
	int res = heights[0] > heights[1];
	for(int i = 1; i < n-1; i++)
		if(heights[i] > heights[i-1] && heights[i] > heights[i+1])
			res++;
	if(n > 1) res += heights[n-1] > heights[n-2];
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
