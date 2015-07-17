#include <cstdio>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

long long cnt1, cnt2, x, y;

bool check(long long v)
{
	long long divx = v / x;
	long long divy = v / y;
	long long both = v / (x * y);
	long long neither = v - (divx + divy - both);
	if(divx - both + neither < cnt2) return 0;
	if(divy - both + neither < cnt1) return 0;
	return (divx - both) + (divy - both) + neither >= cnt1 + cnt2;
}

int main()
{
	cin >> cnt1 >> cnt2 >> x >> y;
	long long low = 1, high = 1e15;
	while(low < high)
	{
		long long v = low + (high - low) / 2;
		if(check(v)) high = v;
		else low = v + 1;
	}
	cout << high << endl;
	return 0;
}
