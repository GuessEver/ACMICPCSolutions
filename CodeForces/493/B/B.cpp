#include <cstdio>
#include <algorithm>
using std::max;
using std::min;

const int N = 2 * 100000 + 10;

int n, A[N], B[N];
int cntA = 0, cntB = 0;
long long sumA = 0, sumB = 0;
int last;

bool check()
{
	if(sumA > sumB) return 1;
	if(sumA < sumB) return 0;
	int maxp = max(cntA, cntB);
	int minp = min(cntA, cntB);
	for(int i = 1; i <= minp; i++)
	{
		if(A[i] > B[i]) return 1;
		if(A[i] < B[i]) return 0;
	}
	if(cntA > cntB) return 1;
	if(cntA < cntB) return 0;
	if(last > 0) return 1; else return 0;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		last = x;
		if(x > 0)
		{
			A[++cntA] = x;
			sumA += x;
		}
		else{
			x = -x;
			B[++cntB] = x;
			sumB += x;
		}
	}
	if(check()) puts("first");
	else puts("second");
	return 0;
}
