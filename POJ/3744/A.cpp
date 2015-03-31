#include <cstdio>
#include <cstring>
#include <algorithm>

int n;
double p;
int mine[20];
struct Matrix{
	double val[2][2];
	Matrix() {}
	Matrix(double a, double b, double c, double d)
	{
		val[0][0] = a; val[0][1] = b;
		val[1][0] = c; val[1][1] = d;
	}
	Matrix operator * (const Matrix &b) const
	{
		Matrix ans(0, 0, 0, 0);
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				for(int k = 0; k < 2; k++)
					ans.val[i][j] += val[i][k] * b.val[k][j];
		return ans;
	}
}base, pre;
int preidx;

/*
   [ f(i-1)  f(i-2) ]  *  [  p   1 ]  =  [ p*f(i-1)+(1-p)*f(i-2)=f(i)   f(i-1) ]
   [   0       0    ]     [ 1-p  0 ]     [               0                 0   ]
*/

Matrix mul(Matrix x, int y)
{
	if(y == 0) return Matrix(1, 0, 0, 1);
	if(y & 1) return mul(x * x, y / 2) * x;
	return mul(x * x, y / 2);
}

int main()
{
	while(scanf("%d%lf", &n, &p) == 2)
	{
		base = Matrix(p, 1, 1-p, 0);
		for(int i = 1; i <= n; i++) scanf("%d", &mine[i]);
		std::sort(mine+1, mine+1+n);
		if(mine[1] == 1) { puts("0.0000000"); continue; }
		pre = Matrix(1, 0, 0, 0); preidx = 1;
		for(int i = 1; i <= n; i++)
		{
			int alpha = (mine[i] - 1 - preidx);
			pre = pre * mul(base, alpha);
			pre.val[0][1] = pre.val[0][0]; pre.val[0][0] = 0;
			//pre = pre * base;
			preidx = mine[i];// + 1;
		}
		pre = pre * base;
		printf("%.7f\n", pre.val[0][0]);
	}
	return 0;
}
