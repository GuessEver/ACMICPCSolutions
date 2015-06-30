#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 100000 + 10;

int n;
struct LEG{
	int l, d;
	bool operator < (const LEG &b) const
	{
		return l < b.l;
	}
}a[N];
struct Node{
	int l, r;
}len[N];
int S[N];
int num[210];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i].l);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i].d);
	std::sort(a+1, a+1+n);
	for(int i = 1; i <= n; i++) S[i] = S[i-1] + a[i].d;
	//for(int i = 1; i <= n; i++) printf("%d: %d %d\n", i, a[i].l, a[i].d);
	memset(len, -1, sizeof(len));
	for(int i = 1; i <= n; i++)
	{
		if(len[a[i].l].l == -1) len[a[i].l].l = i;
		len[a[i].l].r = i;
	}
	int res = 0;
	for(int i = 1; i <= 100000; i++)
	{
		if(len[i].l == -1) continue;
		int st = len[i].l, ed = len[i].r, length = ed - st + 1;
		int tmp = S[ed] - S[st-1]; length--;
		for(int j = 200; j >= 1; j--)
		{
			if(length >= num[j])
			{
				tmp += j * num[j];
				length -= num[j];
			}
			else {
				tmp += j * length;
				length = 0;
			}
		}
		if(tmp > res) res = tmp;
		for(int j = st; j <= ed; j++) num[a[j].d]++;
	//	printf("%d %d %d\n", i, tmp, res);
	}
	printf("%d\n", S[n] - res);
	return 0;
}
