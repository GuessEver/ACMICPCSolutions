#include <cstdio>
#include <cstring>

const int N = 1000 + 10;

char s[N];
int n, val['z'+10], vmax;

int main() 
{
	freopen("B.in", "r", stdin);
	scanf("%s", s);
	scanf("%d", &n);
	for(int i = 'a'; i <= 'z'; i++)
	{
		int a; scanf("%d", &a);
		val[i] = a;
		if(a > vmax) vmax = a;
	}
	int len = strlen(s);
	int res = 0;
	for(int i = 0; i < len; i++)
		res += (i+1) * val[s[i]];
	for(int i = 1; i <= n; i++)
		res += (i+len) * vmax;
	//res += (len+n) * val[s[len-1]];
	printf("%d\n", res);
	return 0;
}
