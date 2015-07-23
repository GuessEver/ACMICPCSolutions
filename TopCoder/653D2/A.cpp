#include<bits/stdc++.h>
using namespace std;

class CountryGroup {
public:
	int solve(vector <int>);
};

int CountryGroup::solve(vector <int> a) {
	int res = 0, n = a.size();
	for(int i = 0; i < n; )
	{
		res++;
		for(int j = i; j < i + a[i]; j++) if(a[i] != a[j]) return -1;
		i += a[i];
		if(i > n) return -1;
	}
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!

