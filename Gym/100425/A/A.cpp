#include <cstdio>
#include <iostream>

long long L, R;

long long calc(long long n)
{
	//long long k = (n - 3) / 3;
	//long long tmp = ((1 + k) * n - (2 + 3 * k) * (k + 1) / 2) / 2;
	//return tmp;
	long long tmp = n * n / 12;
	if(n * n % 12 >= 6) tmp++;
	return tmp;
}

long long find(long long x) // first position calc(low) >= x
{
	long long low = 3, high = 2 * 1e9;
	while(low < high)
	{
		long long mid = low + (high - low) / 2;
		long long tmp = calc(mid);
		if(tmp < x) low = mid + 1;
		else high = mid;
	}
	return low;
}

int main()
{
	//for(int i = 3; i <= 20; i++)
	//	std::cout << i << ": " << calc(i) << std::endl;
	std::cin >> L >> R;
	long long pos1 = find(L);
	long long pos2 = find(R + 1);
	std::cout << pos2 - pos1 << std::endl;
	return 0;
}
