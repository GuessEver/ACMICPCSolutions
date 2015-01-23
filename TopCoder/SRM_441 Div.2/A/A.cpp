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
#include <string>
using namespace std;

class DifferentStrings {
public:
	int minimize(string, string);
};

int DifferentStrings::minimize(string A, string B) {
	int lena = A.length();
	int lenb = B.length();
	int res = 0x3f3f3f3f;
	for(int i = 0; i <= lenb-lena; i++)
	{
		int tmp = 0;
		for(int j = 0; j < lena; j++)
		{
			if(A[j] != B[i+j]) tmp++;
			printf("%c %c %d\n", A[j], B[i+j], tmp);
		}puts("");
		res = min(res, tmp);
	}
	return res;
}


//Powered by [KawigiEdit] 2.0!
