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

class TheConsecutiveIntegersDivTwo {
public:
	int find(vector <int>, int);
};

map<int, bool> hash;

int TheConsecutiveIntegersDivTwo::find(vector <int> numbers, int k) {
	if(k == 1) return 0;
	sort(numbers.begin(), numbers.end());
	int res = 30000000;
	int n = numbers.size();
	for(int i = 1; i < n; i++)
		if(res > abs(numbers[i] - numbers[i-1]))
			res = abs(numbers[i] - numbers[i-1]);
	return res - 1;
}


//Powered by [KawigiEdit] 2.0!
