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

class ShufflingCardsDiv2 {
public:
	string shuffle(vector <int>);
};

string ShufflingCardsDiv2::shuffle(vector <int> permutation) {
	int n = permutation.size() / 2;
	int smaller = 0, bigger = 0;
	for(int i = 0; i < 2 * n; i++) if(i % 2 == 0) // odd pos
	{
		if(permutation[i] <= n) smaller++;
		else bigger++;
	}
	printf("%d %d\n", smaller, bigger);
	if(2 * n % 4 == 0)
	{
		if(bigger == smaller) return "Possible";
		else return "Impossible";
	}
	else{
		if(bigger + 1 == smaller) return "Possible";
		else return "Impossible";
	}
}


//Powered by [KawigiEdit] 2.0!
