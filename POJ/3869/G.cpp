#include <cstdio>
#include <cmath>
#include <cstring>

char s[110];
int n, a[110];

int main()
{
	scanf("%s", s);
	n = strlen(s);
	for(int i = 0; i < n; i++)
		a[i+1] = s[i] - '0';
	int two = 0, one = 0;
	a[0] = a[n];
	for(int i = 1; i <= n; i++)
		if(!a[i-1] && !a[i]) two++;
	for(int i = 1; i <= n; i++)
		if(!a[i]) one++;
	double R = 1.0 * one / n;
	double S = 1.0 * two / one;
	if(fabs(R - S) < 1e-7) puts("EQUAL");
	else if(R > S) puts("ROTATE");
	else puts("SHOOT");
	return 0;
}
