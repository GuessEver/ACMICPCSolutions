#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 3000 + 10;

int b, d;
double dp[N][N];
bool calced[N][N];
int mul[20];

double calc(int A, int B, int turns)
{
	if(turns > d + d) return dp[A][B] = A > B ? 1.0 : 0.0;
	if(calced[A][B]) return dp[A][B];
	calced[A][B] = 1; dp[A][B] = 0.0;
	if(turns & 1)
	{
		for(int j = 1; j <= b; j++)
		{
			double res = 0.0;
			for(int i = 0; i < d; i++)
				if(A / mul[i] % (b + 1) == 0)
					res = std::max(res, calc(A + mul[i] * j, B, turns + 1));
			dp[A][B] += res / b;
		}
	}
	else {
		for(int j = 1; j <= b; j++)
		{
			double res = 1.0;
			for(int i = 0; i < d; i++)
				if(B / mul[i] % (b + 1) == 0)
					res = std::min(res, calc(A, B + mul[i] * j, turns + 1));
			dp[A][B] += res / b;
		}
	}
	return dp[A][B];
}

bool fullFill(int A)
{
	for(int i = 0; i < d; i++)
		if(A / mul[i] % (b + 1) == 0)
			return 0;
	return 1;
}

double Awin[N], Bwin[N];

double dfs(int A, int B, int turns)
{
	if(turns > d) return Bwin[B] = B >= A ? 1.0 : 0.0;
	if(calced[A][B]) return Bwin[B];
	calced[A][B] = 1; Bwin[B] = 0.0;
	for(int j = 1; j <= b; j++)
	{
		double res = 0.0;
		for(int i = 0; i < d; i++)
			if(B / mul[i] % (b + 1) == 0)
				res = std::max(res, dfs(A, B + mul[i] * j, turns + 1));
		Bwin[B] += res / b;
	}
	return Bwin[B];
}

double dpA[N];

double getAns(int A, int turns)
{
	if(turns > d) return dpA[A] = Awin[A];
	if(calced[A][0]) return dpA[A];
	calced[A][0] = 1; dpA[A] = 0.0;
	for(int j = 1; j <= b; j++)
	{
		double res = 0.0;
		for(int i = 0; i < d; i++)
			if(A / mul[i] % (b + 1) == 0)
				res = std::max(res, getAns(A + mul[i] * j, turns + 1));
		dpA[A] += res / b;
	}
	return dpA[A];
}

int main()
{
	//freopen("greater.in", "r", stdin);
	//freopen("greater.out", "w", stdout);
	while(scanf("%d%d", &d, &b) == 2 && (d || b))
	{
		mul[0] = 1;
		for(int i = 1; i <= d; i++) mul[i] = mul[i-1] * (b + 1);
		int tot = mul[d];
		memset(calced, 0, sizeof(calced));
		printf("%.7f ", calc(0, 0, 1));
		memset(calced, 0, sizeof(calced));
		for(int A = 0; A < tot; A++)
			if(fullFill(A)) Awin[A] = 1.0 - dfs(A, 0, 1);
		//for(int A = 0; A < tot; A++) printf("Awin[%d] = %.5f\n", A, Awin[A]);
		memset(calced, 0, sizeof(calced));
		printf("%.7f\n", getAns(0, 1));
	}
	return 0;
}
