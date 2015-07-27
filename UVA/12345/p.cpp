#include <cstdio>

int n, q, a[50000 + 10];
bool hash[1000000 + 10];
char tmp[100];

int main()
{
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	while(q--)
	{
		scanf("%s", tmp);
		int l, r; scanf("%d%d", &l, &r);
		l++;
		if(tmp[0] == 'Q')
		{
			int cnt = 0;
			for(int i = l; i <= r; i++)
			{
				if(!hash[a[i]]) cnt++;
				hash[a[i]] = 1;
			}
			printf("%d\n", cnt);
			for(int i = l; i <= r; i++)
				hash[a[i]] = 0;
		}
		else a[l] = r;
	}
	return 0;
}
