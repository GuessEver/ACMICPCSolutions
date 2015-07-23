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

class PeacefulLine {
public:
	string makeLine(vector <int>);
};

int cnt[100];

string PeacefulLine::makeLine(vector <int> x) {
	int n = x.size();
	for(int i = 0; i < n; i++) cnt[x[i]]++;
	int sum = 0, max = 0;
	for(int i = 1; i <= 25; i++)
	{
		sum += cnt[i];
		if(cnt[i] > max) max = cnt[i];
	}
	for(int i = 1; i <= 25; i++)
		if(sum-cnt[i] < cnt[i]-1) return "impossible";
	return "possible";
}

<%:testing-code%>

//Powered by [KawigiEdit] 2.0!
