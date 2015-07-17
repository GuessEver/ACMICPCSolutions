#include <cstdio>
#include <cstring>

const int N = 100000 + 10;

struct Node{
	char s[N];
	int cnt[26], len;
}L[3];
int cc[26];

void Read(Node &a)
{
	scanf("%s", a.s);
	a.len = strlen(a.s);
	for(int i = 0; a.s[i]; i++) a.cnt[a.s[i]-'a']++;
}

int check(int res)
{
	for(int A = 0; A <= res; A++)
	{
		int B = res - A;
		bool flag = 1;
		for(int j = 0; j < 26; j++)
		{
			long long tmp = 1ll * L[1].cnt[j] * A + 1ll * L[2].cnt[j] * B;
			if(tmp > L[0].cnt[j]) { flag = 0; break; }
		}
		if(flag) return A;
	}
	return -1;
}

int main()
{
	for(int i = 0; i < 3; i++) Read(L[i]);
	int low = 0, high = L[0].len, ans = 0, A = 0;
	while(low <= high)
	{
		int mid = low + (high - low) / 2;
		int cc = check(mid);
		if(cc != -1) 
		{
			low = mid + 1;
			ans = mid;
			A = cc;
		}
		else high = mid - 1;
	}
	//printf("%d %d\n", A, ans-A);
	for(int i = 0; i < A; i++) printf("%s", L[1].s);
	for(int i = 0; i < ans-A; i++) printf("%s", L[2].s);
	for(int j = 0; j < 26; j++)
	{
		L[0].cnt[j] -= (L[1].cnt[j] * A + L[2].cnt[j] * (ans - A));
		for(int i = 0; i < L[0].cnt[j]; i++) printf("%c", j + 'a');
	}
	puts("");
	return 0;
}
