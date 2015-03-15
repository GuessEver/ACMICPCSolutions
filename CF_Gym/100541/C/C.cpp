#include <cstdio>
#include <cstring>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const int mon[] = {1000, 2000, 3000, 5000};

long long w;
int n, c;
long long a[30][10];
long long num[30][10];

long long calc()
{
	long long one = num[c][0];
	long long two = num[c][1];
	long long three = num[c][2];
	long long five = num[c][3];
	long long sum = one * 1 + two * 2 + three * 3 + five * 5;
	if(sum >= 10) sum = sum - (sum - 9) / 5 * 5;
	long long tmp = 0;
	for(int i = 14; i >= 1; i--)
	{
		int flag = 1;
		if(i == 14) flag = 3;
		else if(i == 11) flag = 2;
		else if(i == 9) flag = 3;
		else if(i == 6 || i == 4) flag = 2;
		tmp += sum / i * flag; sum %= i;
	}
	return tmp == 0 ? 1 : tmp;
}

long long solve()
{
	long long res = 1;
	for(int ic = c - 1; ic >= 0; ic--)
	{
	/*
	   4 = 1 + 3 <-> 2 + 2
	   6 = 1 + 5 <-> 3 + 3
	   9 = 2 + 2 + 5 <-> 3 + 3 + 3 <-> 1 + 3 + 5
	*/
		long long one = num[ic][0];
		long long two = num[ic][1];
		long long three = num[ic][2];
		long long five = num[ic][3];
		long long sum = one * 1 + two * 2 + three * 3 + five * 5;
		//cout << "sum = " << sum << endl;
		long long tmp = 0;
		for(int i = 9; i >= 1; i--)
		{
			int flag = 1;
			if(i == 9) flag = 3;
			else if(i == 6 || i == 4) flag = 2;
			tmp += sum / i * flag; sum %= i;
		}
		if(!tmp) tmp = 1;
		res *= tmp;
	}
	res *= calc();
	return res;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		memset(num, 0, sizeof(num));
		memset(a, 0, sizeof(a));
		cin >> w >> c;
		n = 0;
		long long k = 1;
		for(int ic = c - 1; ic >= 0; ic--) k *= 10;
		for(int ic = c; ic >= 0; ic--)
		{
			for(int i = 3; i >= 0; i--) a[ic][i] = mon[i] * k;
			k /= 10;
		}
	//	for(int ic = c; ic >= 0; ic--)
	//		for(int i = 3; i >= 0; i--) cout << a[ic][i] << endl;
		long long res = 0;
		for(int ic = c; ic >= 0; ic--)
			for(int i = 3; i >= 0; i--)
			{
				num[ic][i] = w / a[ic][i];
				w -= num[ic][i] * a[ic][i];
				res += num[ic][i];
			}
		if(w != 0) puts("0");
		else cout << res << ' ' << solve() << endl;
	}
	return 0;
}
