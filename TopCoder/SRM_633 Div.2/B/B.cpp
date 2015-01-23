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

class Jumping {
public:
	string ableToGet(int, int, vector <int>);
};

string Jumping::ableToGet(int x, int y, vector <int> jumpLengths) {
	int n = jumpLengths.size();
	string yes = "Able", no = "Not able";
	double sum = 0, maxLen = 0;
	double dis = sqrt(x * x + y * y);
	for(int i = 0; i < n; i++)
	{
		sum += jumpLengths[i];
		if(jumpLengths[i] > maxLen) maxLen = jumpLengths[i];
	}
	sum += dis;
	if(dis > maxLen) maxLen = dis;
	if(maxLen * 2 <= sum) return yes;
	return no;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
