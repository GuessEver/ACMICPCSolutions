#include <cstdio>
#include <cstring>

char s[100000+10];
long long cnt[2][2];

int main()
{
	s[0] = '$';
	scanf("%s", s+1);
	int n = strlen(s) - 1;
	for(int i = 1; i <= n; i++)
		cnt[s[i]-'a'][i & 1]++;
	long long odd = 0, even = 0;
	odd += cnt[0][1] + cnt[0][0] + cnt[1][0] + cnt[1][1];
	odd += cnt[0][1] * (cnt[0][1] - 1) / 2;
	odd += cnt[0][0] * (cnt[0][0] - 1) / 2;
	odd += cnt[1][1] * (cnt[1][1] - 1) / 2;
	odd += cnt[1][0] * (cnt[1][0] - 1) / 2;
	even += cnt[0][0] * cnt[0][1];
	even += cnt[1][0] * cnt[1][1];
	printf("%I64d %I64d\n", even, odd);
	return 0;
}
