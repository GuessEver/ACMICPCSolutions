#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 1000 + 10;

int K, n;
char s[N];
struct Node{
	int cnt, hash['z'+10];
}a[N];
int f[N]['z'+10]; // f[i][j] : the value of ith block with ending `j`

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%s", &K, s);
		memset(a, 0, sizeof(a));
		for(int c = 0, i = 0; s[i]; i++, c++)
		{
			n = c / K + 1;
			if(a[n].hash[s[i]] == 0) a[n].cnt++;
			a[n].hash[s[i]]++;
		}
		memset(f, 0x3f, sizeof(f));
		for(char j = 'a'; j <= 'z'; j++) if(a[1].hash[j]) f[1][j] = a[1].cnt;
		for(int i = 2; i <= n; i++)
			for(char j = 'a'; j <= 'z'; j++) if(a[i].hash[j])
				for(char t = 'a'; t <= 'z'; t++) if(a[i-1].hash[t])
				{
					if(a[i].hash[t] && (j != t || (j == t && a[i].cnt == 1)))
						f[i][j] = std::min(f[i][j], f[i-1][t] + a[i].cnt - 1);
					f[i][j] = std::min(f[i][j], f[i-1][t] + a[i].cnt);
				}
		int res = 0x3f3f3f3f;
		for(char j = 'a'; j <= 'z'; j++) if(f[n][j] < res) res = f[n][j];
		printf("%d\n", res);
	}
	return 0;
}
