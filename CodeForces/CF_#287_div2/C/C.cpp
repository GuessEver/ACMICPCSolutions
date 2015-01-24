#include <cstdio>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

long long value(long long x)
{
	long long res = 1;
	for(long long i = 1; i < x; i++) res = res * 2 + 1;
	return res;
}

long long calc(long long tot, long long h, long long n, bool L)
{
	if(h == 1) return 0;
	bool left = (n * 2 <= tot);
	if(L && left) return calc(tot/2, h-1, n, !L) + 1;
	else if(L && !left) return calc(tot/2, h-1, n-tot/2, L) + value(h-1) + 1;
	else if(!L && left) return calc(tot/2, h-1, n, L) + value(h-1) + 1;
	else if(!L && !left) return calc(tot/2, h-1, n-tot/2, !L) + 1;
}

int main()
{
	long long h, n;
	cin >> h >> n;
	long long res = 0;
	long long tot = (1ll << h);
	cout << calc(tot, h+1, n, 1) << endl;
	return 0;
}
