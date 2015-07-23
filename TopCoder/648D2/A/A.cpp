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

class KitayutaMart2 {
public:
	int numBought(int, int);
};

int KitayutaMart2::numBought(int K, int T) {
	int t = 1, i = 0;
	while(1)
	{
		if(T - t * K < 0) return i;
		T -= t * K;
		t *= 2;
		i++;
	}
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
