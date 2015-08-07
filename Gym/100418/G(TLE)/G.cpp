#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
const int N = 1000000 + 10;
int n, cnt[N], pre, tmp, ans[N];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &tmp);
		cnt[tmp]++;
	}
	//for(int i = 2; i <= 1000000; i++) cnt[i] += cnt[i-1];
	pre = tmp = 0;
	for(int i = 1; i <= 1000000; i++) if(cnt[i])
	{
		ans[++tmp] = i; cnt[i]--;
		if(i != pre && cnt[pre]) i = pre-1;
		else pre = i;
	}
	//for(int i = 1; i <= tmp; i++) printf("%d ", ans[i]); puts("");
	for(int i = 1; i <= 1000000; i++) if(cnt[i]) pre = i;
	for(int i = 1, j = 1; i <= tmp; i++)
		if(ans[i] == pre) { ans[i] = 0; cnt[pre]++; }
	for(int i = 1, j = 1; i <= tmp; i++) if(ans[i] == 0)
	{
		if(j <= i) j = i + 1; 
		for(; j <= tmp; j++) if(ans[j])
		{
			ans[i] = ans[j];
			ans[j] = 0; j++;
			break;
		}
	}
	for(int i = 1; i <= tmp; i++)
		if(ans[i] == 0) { tmp = i - 1; break; }
	//for(int i = 1; i <= tmp; i++) printf("%d ", ans[i]); puts("");
	//printf("%d %d\n", pre, cnt[pre]);
	if(cnt[pre] > tmp + 1)
	{
		puts("-1");
		return 0;
	}
	std::sort(ans + tmp + 1 - cnt[pre] + 1, ans + tmp + 1);
	//for(int i = 1; i <= tmp; i++) printf("%d ", ans[i]); puts("");
	for(int i = 0; i <= tmp; i++)
	{
		if(i) printf("%d ", ans[i]);
		if(i > tmp - cnt[pre]) printf("%d ", pre);
	} puts("");
	return 0;
}
