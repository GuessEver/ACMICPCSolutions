#include <cstdio>

const int N = 500 + 100 + 10;

int n, k1, k2, k3, a, b, c;
double A[N], C[N];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d%d%d%d%d", &n, &k1, &k2, &k3, &a, &b, &c);
		for(int i = 0; i <= 600; i++) A[i] = C[i] = 0.0;
		A[n] = 1.0 / (1.0 * k1 * k2 * k3);
		C[n] = 1.0;
		for(int i = n - 1; i >= 0; i--)
		{
			double sigmaAi = 0.0, sigmaCi = 0.0;
			for(int j = 1; j <= k1; j++)
				for(int k = 1; k <= k2; k++)
					for(int t = 1; t <= k3; t++)
					{
						if(j == a && k == b && t == c) continue;
						sigmaAi += A[i+j+k+t];
						sigmaCi += C[i+j+k+t];
					}
			A[i] = A[n] * (1.0 + sigmaAi);
			C[i] = A[n] * sigmaCi + 1.0;
		}
		printf("%.10f\n", C[0] / (1 - A[0]));
	}
	return 0;
}
