/*
ID: MasterRay
LANG: C++
TASK: nocows
*/
 
#include <stdio.h>
 
int s[100][200];
 
int main()
{
	int k, n;
	freopen("nocows.in", "r", stdin);
	freopen("std.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int j = 1; j <= k; ++j)
		s[j][1] = 1;
	for (int j = 1; j <= k; ++j)
		for (int i = 3; i <= n; i += 2)
			for (int k = 1; k <= i-2; k += 2)
				s[j][i] = (s[j][i]+s[j-1][k]*s[j-1][i-k-1])%9901;
	printf("%d\n", (s[k][n]-s[k-1][n]+9901)%9901);
}
