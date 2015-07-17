#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;

int n, m, cnt['Z'+10];
struct Node{
	char ch; int cnt;
}a[30];

bool cmp(Node a, Node b)
{
	return a.cnt > b.cnt;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		char ch; scanf(" %c", &ch);
		cnt[ch]++;
	}
	for(char i = 'A'; i <= 'Z'; i++)
		a[i-'A'] = (Node){i, cnt[i]};
	std::sort(a, a+26, cmp);
	long long res = 0;
	for(int i = 0; i < 26; i++)
	{
		if(a[i].cnt <= m)
		{
			m -= a[i].cnt;
			res += 1ll * a[i].cnt * a[i].cnt;
		}
		else{
			res += 1ll * m * m;
			m = 0;
		}
		if(m == 0) break;
	}
	cout << res << endl;
	return 0;
}
