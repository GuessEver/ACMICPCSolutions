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

class ElectronicPetEasy {
public:
	string isDifficult(int, int, int, int, int, int);
};

int a[10000], b[10000];

string ElectronicPetEasy::isDifficult(int st1, int p1, int t1, int st2, int p2, int t2) {
	a[1] = st1; b[1] = st2;
	for(int i = 2; i <= t1; i++) a[i] = a[i-1] + p1;
	for(int i = 2; i <= t2; i++) b[i] = b[i-1] + p2;
	for(int i = 1; i <= t1; i++) printf("%d ", a[i]); puts("");
	for(int i = 1; i <= t2; i++) printf("%d ", b[i]); puts("");
	for(int i = 1; i <= t1; i++)
		for(int j = 1; j <= t2; j++)
			if(a[i] == b[j]) return "Difficult";
	return "Easy";
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
