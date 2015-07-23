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

class SpecialStrings {
public:
	string findNext(string);
};

bool ok(long long x)
{
	string ans = "";
	for(int i = 0; i < n; i++)
	{
		char ch = (now & 1) + '0';
		ans = ch + ans;
		x >>= 1;
	}
	string a, b = ans;
	for(int i = 1; i < n; i++)
	{
		a += b[0];
		b.erase(0, 1);
		if(a >= b) return 0;
	}
	return 1;
}

string SpecialStrings::findNext(string current) {
	int n = current.length();
	long long now = 0;
	for(int i = 0; i < n; i++)
	{
		if(current[i] == '1') now |= (1 << i);
	}
	while(++now)
	{
		if(ok) break;
	}
	string ans = "";
	for(int i = 0; i < n; i++)
	{
		char ch = (now & 1) + '0';
		ans = ch + ans;
		x >>= 1;
	}
	return ans;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
