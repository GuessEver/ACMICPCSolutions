#include <cstdio>
#include <algorithm>

int a[4], b[4];

bool check(int L, int R)
{
	if(a[1] >= L && b[1] >= R) return 1;
	if(a[1] >= R && b[1] >= L) return 1;
	return 0;
}

int main()
{
	for(int i = 1; i <= 3; i++) scanf("%d%d", &a[i], &b[i]);
	if(check(a[2] + a[3], std::max(b[2], b[3])) 
			|| check(std::max(a[2], a[3]), b[2] + b[3])
			|| check(a[2] + b[3], std::max(b[2], a[3]))
			|| check(std::max(a[2], b[3]), b[2] + a[3]))
		puts("YES");
	else puts("NO");
	return 0;
}
