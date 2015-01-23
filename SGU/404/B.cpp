#include <cstdio>

int n, m;
char s[1000][1000];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) scanf("%s", s[i]); 
	n = n % m;
	if(n == 0) n = m;
	puts(s[n]);
	return 0;
}
