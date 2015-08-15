#include <cstdio>
const int N = 5000 + 10;

int n, a[N];
bool sum[100000*4+10];

int main()
{
	scanf("%d", &n);
	int res = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		for(int j = 1; j < i; j++)
		{
			int tmp = a[i] - a[j];
			if(sum[tmp+200000])
			{
				//printf("##%d ", a[i]);
				res++;
				break;
			}
		}
		for(int j = 1; j <= i; j++)
			sum[a[j] + a[i] + 200000] = 1;
	}
	printf("%d\n", res);
	return 0;
}
