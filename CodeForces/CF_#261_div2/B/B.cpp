#include <cstdio>

int n, a[300100];

int main()
{
	scanf("%d", &n);
	int maxi = 0, mini = 0x3f3f3f3f;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] > maxi) maxi = a[i];
		if(a[i] < mini) mini = a[i];
	}
	printf("%d ", maxi - mini);
	int nummax = 0, nummin = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == maxi) nummax++;
		if(a[i] == mini) nummin++;
	}
	long long ans = (long long)nummax*nummin;
	if(maxi == mini) ans = (long long)nummax*(nummin-1) / 2;;
	printf("%I64d\n", ans);
	return 0;
}
