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

class TrianglesContainOriginEasy {
public:
	int count(vector <int>, vector <int>);
};

double Dis(int x1, int y1, int x2, int y2)
{
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

bool check(int x1, int y1, int x2, int y2, int x3, int y3)
{
	double d1 = Dis(x1, y1, x2, y2);
	double d2 = Dis(x1, y1, x3, y3);
	double d3 = Dis(x2, y2, x3, y3);
	return (d1 + d2 > d3) && (d1 + d3 > d2) && (d2 + d3 > d1)
		&& (fabs(d1 - d2) < d3) && (fabs(d1 - d3) < d2) && (fabs(d2 - d3) < d1);
}

bool check2(int x1, int y1, int x2, int y2, int x3, int y3)
{
	long long S2 = abs((x3-x1)*(y2-y1) - (x2-x1)*(y3-y1));
	long long SS = abs(x1*y2 - x2*y1) + abs(x1*y3 - x3*y1) + abs(x2*y3 - x3*y2);
	return S2 == SS;
}

int TrianglesContainOriginEasy::count(vector <int> x, vector <int> y) {
	int n = x.size();
	int cnt = 0;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			for(int k = j + 1; k < n; k++)
				if(check(x[i], y[i], x[j], y[j], x[k], y[k])
					&& check2(x[i], y[i], x[j], y[j], x[k], y[k]))
				{
					//printf("(%d,%d) (%d,%d) (%d,%d)\n", x[i], y[i], x[j], y[j], x[k], y[k]);
					cnt++;
				}
	return cnt;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
