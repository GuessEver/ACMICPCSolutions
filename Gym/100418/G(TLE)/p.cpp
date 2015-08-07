#include <cstdio>
#include <algorithm>
const int N = 1000000 + 10;
int n, a[N];

bool check()
{
	for(int i = 1; i < n; i++) if(a[i] == a[i+1]) return 0;
	return 1;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	std::sort(a+1, a+1+n);
	do{
		if(!check()) continue;
		for(int i = 1; i <= n; i++) printf("%d ", a[i]);
		puts("");
		return 0;
	}while(std::next_permutation(a+1, a+1+n));
	puts("-1");
	return 0;
}
