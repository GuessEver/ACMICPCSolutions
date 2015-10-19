#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
long long n;
long long res = 1;

int main()
{
	std::cin >> n;
	for(long long i = 2; i * i <= n; i++) if(n % i == 0)
	{
		while(n % i == 0) n /= i;
		res *= i;
	}
	res *= n;
	std::cout << res << std::endl;
	return 0;
}
