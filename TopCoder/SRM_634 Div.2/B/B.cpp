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
#include <cstring>

using namespace std;

class ShoppingSurveyDiv2 {
public:
	int minValue(int, vector <int>);
};

int cnt[200];

int ShoppingSurveyDiv2::minValue(int N, vector <int> s) {
	memset(cnt, 0, sizeof(cnt));
	int n = N, m = s.size();
	int now = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < s[i]; j++)
		{
			cnt[now]++;
			now++;
			now %= n;
		}
		now %= n;
	}
	int res = 0;
	for(int i = 0; i < n; i++) if(cnt[i] == m) res++;
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
