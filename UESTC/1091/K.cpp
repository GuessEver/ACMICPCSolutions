#include <cstdio>
#include <cstring>
#include <cctype>

const int N = 2 * 1000000 + 10;

int s[N], t[N];
int fail[N], n, m;

void getFail()
{
	memset(fail, 0, sizeof(fail)); fail[0] = -1;
	for(int j = 0, k = -1; j < m; )
	{
		if(k == -1 || t[j] == t[k]) fail[++j] = ++k;
		else k = fail[k];
	}
}

int kmp()
{
	int res = 0;
	for(int i = 0, j = 0; i < n; )
	{
		if(j == -1 || s[i] == t[j]) { i++; j++; }
		else j = fail[j];
		if(j == m) 
		{
			//printf("pos = %d\n", i - m);
			res++;
		}
	}
	return res;
}

inline int nextInt()
{
	char ch = getchar(); int res = 0; bool sign = 0;
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') { sign = 1; ch = getchar(); }
	do res = (res << 1) + (res << 3) + ch - '0';
	while(isdigit(ch = getchar()));
	return sign ? -res : res;
}

int main()
{
	//scanf("%d", &n); for(int i = 0; i < n; i++) scanf("%d", &s[i]);
	//scanf("%d", &m); for(int i = 0; i < m; i++) scanf("%d", &t[i]);
	n = nextInt(); for(int i = 0; i < n; i++) s[i] = nextInt();
	for(int i = 0; i < n - 1; i++) s[i] = s[i + 1] - s[i]; n--;
	m = nextInt(); for(int i = 0; i < m; i++) t[i] = nextInt();
	for(int i = 0; i < m - 1; i++) t[i] = t[i + 1] - t[i]; m--;
	getFail();
	//for(int i = 1; i <= m; i++) printf("%d ", fail[i]); puts("");
	int res = kmp();
	if(res) printf("Wow! Life Winner!\n%d\n", res);
	else puts("Oh. That's impossible. I must have had a dream.");
	return 0;
}
