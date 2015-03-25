#include <cstdio>
#include <algorithm>


int n, a[100010], b[100010];

int main()
{
	while(scanf("%d", &n) == 1 && n)
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			b[i] = a[i];
		}
		for(int i = 1; i <= n; i++)
			for(int j = 1; j + 2 <= n; j++)
				if(a[j] > a[j+2]) std::swap(a[j], a[j+2]);
		std::sort(b+1, b+1+n);
		//for(int i = 1; i <= n; i++) printf("%d ", a[i]); puts("");
		bool flag = 1;
		for(int i = 1; i <= n; i++)
			if(a[i] != b[i])
			{
				flag = 0;
				break;
			}
		if(flag) puts("Yes"); else puts("No");
	}
	return 0;
}
