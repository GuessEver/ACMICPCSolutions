#include <cstdio>
#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;

long long gcd(long long a, long long b) 
{
	return b == 0 ? a : gcd(b, a % b); 
}

bool check(long long a, long long b)
{
	return gcd(a, b) == 1;
}

int main()
{
	long long l, r;
	cin >> l >> r;
	for(long long a = l; a <= r; a++)
		for(long long b = a+1; b <= r; b++)
			for(long long c = b+1; c <= r; c++)
				if(check(a, b) && check(b, c) && !check(a, c))
				{
					cout << a << ' ' << b << ' ' << c << endl;
					return 0;
				}
	puts("-1");
	return 0;
}
