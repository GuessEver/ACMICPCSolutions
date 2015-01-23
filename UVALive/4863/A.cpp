#include <cstdio>
#include <algorithm>
using std::max;
using std::min;

const int N = 1000 + 10;

struct Node{ 
	int k, dA, dB;
	bool operator < (const Node &b) const
	{
		return max(dA, dB) - min(dA, dB) > 
			max(b.dA, b.dB) - min(b.dA, b.dB);
	}
}a[100010];
int n, A, B, m;

int main()
{
	while(scanf("%d%d%d", &n, &A, &B) == 3 && n)
	{
		m = 0;
		for(int i = 1; i <= n;i++)
		{
			int K, dA, dB;
			scanf("%d%d%d", &K, &dA, &dB);
			for(int j = 1; j <= K; j++)
			{
				m++;
				a[m].dA = dA;
				a[m].dB = dB;
			}
		}
		std::sort(a+1, a+1+m);
		int res = 0;
		for(int i = 1; i <= m; i++)
		{
			if(a[i].dA < a[i].dB)
			{
				if(A > 0)
				{
					res += a[i].dA;
					A--;
				}
				else{
					res += a[i].dB;
					B--;
				}
			}
			else{
				if(B > 0)
				{
					res += a[i].dB;
					B--;
				}
				else{
					res += a[i].dA;
					A--;
				}
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
