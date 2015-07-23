#include <cstdio>

int N, d[1010];

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", &d[i]);
	
	int cnt = 0;
	for(int i = 0; i < N; i++)
		for(int j = i; j < N; j++)
		{
			bool flag = 1;
			int l = i, r = j;
			
			if(r - l + 1 <= 2) flag = 1;
			else{
				int qd = d[l+1] - d[l];
				for(int k = l + 1; k <= r; k++)
				{
					int tmp = d[k] - d[k-1];
					if(qd != tmp)
					{
						flag = 0;
						break;
					}
				}
			}
			
			if(flag) cnt++;
		}
	printf("%d\n", cnt);
	return 0;
}
