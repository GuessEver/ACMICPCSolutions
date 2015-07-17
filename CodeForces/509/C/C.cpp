#include <cstdio>
#include <cstring>
#include <algorithm>

int n;
int pre[500000], now[500000];
int len1 = 0, len2 = 0;
int b[500000];

void P(int *p, int len)
{
	//printf("len = %d\n", len);
	for(int i = len; i >= 1; i--) printf("%d", p[i]);
	puts("");
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
	int x = b[1];
	while(x > 9)
	{
		pre[++len1] = 9;
		x -= 9;
	}
	if(x) pre[++len1] = x;
	P(pre, len1);
	for(int p = 2; p <= n; p++)
	{
		if(b[p] > b[p-1])
		{
			int add = b[p] - b[p-1];
			for(int i = 1; i <= len1; i++)
				now[++len2] = pre[i];
			for(int i = 1; add > 0; i++)
			{
				int tmp = 9 - pre[i];
				if(tmp > add) tmp = add;
				now[i] = pre[i] + tmp;
				add -= tmp;
				if(i > len2) len2 = i;
			}
		}
		else if(b[p] == b[p-1])
		{
			for(int i = 1; i <= len1; i++)
				now[++len2] = pre[i];
			int j = 1;
			while(j < len1 && !now[j]) j++;
			now[j]--; j++;
			while(now[j] >= 9) j++;
			now[j]++;
			if(j > len2) len2 = j;
		}
		else{ // b[p] < b[p-1]
			int sub = b[p-1] - b[p] + 1;
			bool flag = 1;
			for(int i = 1; i <= len1; i++)
			{
				int tmp = pre[i];
				if(tmp > sub) tmp = sub;
				while(now[len2+1] + pre[i] - tmp > 9) 
					tmp++;
				now[++len2] += pre[i] - tmp;
				sub -= tmp;
				if(!sub && flag)
				{
					now[len2+1]++;
					flag = 0;
				}
			}
			if(now[len2+1]) len2++;
			if(sub)
			{
				x = b[p] - 1;
				for(int i = 1; i <= len1; i++)
				{
					int tmp = 9;
					if(tmp > x) tmp = x;
					now[i] = tmp;
					x -= tmp;
				}
				len2 = len1;
				while(x > 9) now[++len2] = 9;
				if(x) now[++len2] = x + 1;
				else now[++len2] = 1;
			}
		}
		//puts("------"); P(now, len2);
		int ed = len2;
		if(len2 == len1)
			while(now[ed] == pre[ed]) ed--;
		int i = ed - 1, j = 1;
		while(i >= 1 && j < i)
		{
			int tmp = 9 - now[j];
			if(tmp > now[i]) tmp = now[i];
			now[i] -= tmp; now[j] += tmp;
			if(now[j] == 9) j++;
			i--;
		}
		P(now, len2);
		memset(pre, 0, sizeof(pre));
		for(int i = 1; i <= len2; i++) pre[i] = now[i];
		len1 = len2;
		memset(now, 0, sizeof(now)); len2 = 0;
	}
	return 0;
}
