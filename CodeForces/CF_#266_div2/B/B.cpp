#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;

long long n;
int a, b;

int main()
{
	cin >> n >> a >> b;
	long long s = std::max(n * 6, 1ll * a * b);
	int m = (int)sqrt(s);
	int sign = 0;
	if(a > b) { std::swap(a, b); sign = 1; }

	long long mins = -1;
	long long ansa = -1, ansb = -1;
	for(int i = a; i <= m; i++)
	{
		long long a1 = i;
		long long b1 = s / a1;
		if(a1 * b1 < s) b1++;
		if(a1 < a) a1 = a;
		if(b1 < b) b1 = b;
		long long tmps = a1 * b1;
		if(mins == -1 || tmps < mins)
		{
			mins = tmps;
			ansa = a1; ansb = b1;
		}
	}
	if(sign) std::swap(ansa, ansb);
	cout << mins << endl;
	cout << ansa << ' ' << ansb << endl;
	return 0;
}
