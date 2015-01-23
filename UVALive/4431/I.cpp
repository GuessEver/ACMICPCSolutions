#include <cstdio>
#include <cmath>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>
using std::map;
using std::string;
using std::min;
const double eps = 1e-7;

map<string, int> P;
int m, n;
char X[60], Y[60];
string Xs, Ys;
double cap[210][210];

int dcmp(double x)
{
	if(fabs(x) < eps) return 0;
	return x > 0 ? 1 : -1;
}

int solve()
{
	int ta, tb; // ta * X (?) tb * Y  --->   X (?) tb/ta * Y
	scanf("%d%s", &ta, X); Xs = string(X);
	scanf("%d%s", &tb, Y); Ys = string(Y);

	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				cap[i][j] = min(cap[i][j], cap[i][k] + cap[k][j]);

	for(int i = 1; i <= n; i++) if(dcmp(cap[i][i]) < 0) return 3;
	int a = P[Xs], b = P[Ys];
	double std = log(1.0 * tb / ta);
	// ~ (1/cap[b][a])Y ~ X ~ (cap[a][b]) Y    
	//!!!!!!!!!!!   1/cap[b][a] --->get Log---> -cap[b][a]
	if(dcmp(cap[a][b] - (-cap[b][a])) == 0 && dcmp(cap[a][b] - std) == 0) return 0;
	if(dcmp(cap[a][b] - std) <= 0) return -1;
	if(dcmp((-cap[b][a]) - std) >= 0) return 1;
	return 2;
}

int main()
{
	while(scanf("%d", &m) == 1 && m)
	{
		P.clear(); n = 0;
		for(int i = 0; i <= 205; i++)
		{
			for(int j = 0; j <= 205; j++)
				cap[i][j] = 1e20;
			cap[i][i] = 0;
		}
		for(int i = 1; i <= m; i++)
		{
			int a, b;
			scanf("%d%s", &a, X); Xs = string(X);
			scanf("%d%s", &b, Y); Ys = string(Y);
			if(!P[Xs]) P[Xs] = ++n;
			if(!P[Ys]) P[Ys] = ++n;
			cap[P[Xs]][P[Ys]] = min(cap[P[Xs]][P[Ys]], log(1.0 * b / a));
		}
		int cc = solve();
		if(cc == -1) puts("<=");
		else if(cc == 0) puts("==");
		else if(cc == 1) puts(">=");
		else if(cc == 2) puts("UNAVAILABLE");
		else puts("INCONSISTENT");
	}
	return 0;
}
