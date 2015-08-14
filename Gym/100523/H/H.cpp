#include <cstdio>
#include <vector>
using std::vector;

const int N = 100000 + 10;

int n;
char s[N];
int H, M;

int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	if(n == 1) puts("HM");
	else {
		for(int i = 0; i < n - 1; i++)
		{
			if(s[i] == 'H') H++;
			else M++;
		}
		if(H > M) puts("H");
		else if(H < M) puts("M");
		else {
			if(s[n - 2] == 'H') puts("M");
			else puts("H");
		}
	}
	return 0;
}
