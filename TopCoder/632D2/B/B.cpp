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

class PotentialGeometricSequence {
public:
	int numberOfSubsequences(vector <int>);
};

int PotentialGeometricSequence::numberOfSubsequences(vector <int> d) {
	int cnt = 0;
	int N = d.size();
	for(int i = 0; i < N; i++)
		for(int j = i; j < N; j++)
		{
			bool flag = 1;
			int l = i, r = j;
			
			if(r - l + 1 <= 2) flag = 1;
			else{
				int qd = d[l+1] - d[l];
				for(int k = l + 1; k <= r; k++)
				{
					int tmp = d[k] - d[k-1];
					if(qd != tmp)
					{
						flag = 0;
						break;
					}
				}
			}
			
			if(flag) cnt++;
		}
	return cnt;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
