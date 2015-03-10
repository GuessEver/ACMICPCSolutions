#include<bits/stdc++.h>
using namespace std;

class ThePermutationGameDiv2 {
public:
	long long findMin(int);
};

long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
	return a / gcd(a, b) * b;
}

long long ThePermutationGameDiv2::findMin(int N) {
	long long res = 1;
	for(long long i = 2; i <= N; i++)
		res = lcm(res, i);
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
