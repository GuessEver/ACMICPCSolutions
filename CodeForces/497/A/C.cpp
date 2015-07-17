#include <cstdio>
#include <string>
using std::string;

int n, m;
char s[200][200];
string a[200], b[200];

bool check()
{
	for(int i = 1; i < n; i++)
		if(b[i] < b[i-1]) return 0;
	return 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%s", s[i]);
	if(n == 1) { puts("0"); return 0; }
	int cnt = 0;
	for(int j = 0; j < m; j++)
	{
		for(int i = 0; i < n; i++) b[i] = a[i];
		for(int i = 0; i < n; i++) b[i] += s[i][j];
		if(check()) for(int i = 0; i < n; i++) a[i] = b[i];
		else cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
