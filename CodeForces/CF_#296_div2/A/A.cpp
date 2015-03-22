#include <cstdio>
#include <algorithm>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

long long solve(long long a, long long b)
{
	long long res = 0;
	while(a)
	{
		long long tmp = b / a;
		b %= a;
		if(a > b) std::swap(a, b);
		res += tmp;
	}
	return res;
}

int main()
{
	long long a, b;
	cin >> a >> b;
	if(a > b) std::swap(a, b);
	cout << solve(a, b) << endl;
	return 0;
}
