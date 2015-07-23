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

class IdentifyingWood {
public:
	string check(string, string);
};

string IdentifyingWood::check(string s, string t) {
	int n = s.length();
	int m = t.length();
	int i = 0;
	int res = 0;
	for(int j = 0; j < m; j++)
	{
		while(i < n)
		{
			if(s[i] == t[j])
			{
				res++;
				break;
			}
			i++;
		}
		i++;
	}
	string YES = "Yep, it's wood.";
	string NO = "Nope.";
	if(res == m) return YES; else return NO;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
