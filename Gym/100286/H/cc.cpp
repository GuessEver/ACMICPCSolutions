#include <cstdio>
#include <cstring>

FILE *in = fopen("hell.in", "r");
FILE *ou = fopen("hell.out", "r");
FILE *st = fopen("p.out", "r");
const int N = 100000 + 10;
int n, a[N];
char ans1[100], ans2[100];

int main()
{
	fscanf(in, "%d", &n);
	for(int i = 1; i <= n; i++) fscanf(in, "%d", &a[i]);
	fscanf(ou, "%s", ans1);
	fscanf(st, "%s", ans2);
	if(strcmp(ans1, ans2)) return 1;
	long long sum = 0;
	for(int i = 1; i <= n; i++)
	{
		int x; fscanf(ou, "%d", &x);
		sum += a[i] * x;
	}
	if(sum) return 1;
	return 0;
}
