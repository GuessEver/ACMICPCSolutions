#include <cstdio>

int R, S, P;
double f[110][110][110];

int main()
{
	scanf("%d%d%d", &R, &S, &P);
	f[R][S][P] = 1;
	for(int r = R; r >= 0; r--)
		for(int s = S; s >= 0; s--)
			for(int p = P; p >= 0; p--)
			{
				int cnt = (r == 0) + (s == 0) + (p == 0);
				if(cnt >= 2) continue;
				double tot = 1.0 * r * s + 1.0 * r * p + 1.0 * s * p;
				if(r) f[r-1][s][p] += f[r][s][p] * (1.0 * r * p / tot);
				if(s) f[r][s-1][p] += f[r][s][p] * (1.0 * r * s / tot);
				if(p) f[r][s][p-1] += f[r][s][p] * (1.0 * s * p / tot);
			}
	double ansR = 0.0, ansS = 0.0, ansP = 0.0;
	for(int r = R; r > 0; r--) ansR += f[r][0][0];
	for(int s = S; s > 0; s--) ansS += f[0][s][0];
	for(int p = P; p > 0; p--) ansP += f[0][0][p];
	printf("%.10f %.10f %.10f\n", ansR, ansS, ansP);
	return 0;
}
