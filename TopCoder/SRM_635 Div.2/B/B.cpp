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

class QuadraticLaw {
public:
	long long getTime(long long);
};

long long QuadraticLaw::getTime(long long d) {
	double t = (-1.0 + sqrt(1.0 + 4.0 * d)) / 2.0;
	t += 1e-7;
	return (long long)t;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
