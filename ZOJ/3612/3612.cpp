#include <cstdio> // By GuessEver
#include <cstdlib>
#include <cstring>
#include <algorithm>

const int N = 100000 + 10;

int n;
char ord[100];
struct OP{int p, ord;long long num;}op[N];
int sum[N*4];
long long hash[N];

bool cmp_num(OP a, OP b) { return a.num < b.num; }
bool cmp_ord(OP a, OP b) { return a.ord < b.ord; }

void dosth()
{
	for(int i = 1; i <= n; i++)
	{
		scanf("%s%lld", ord, &op[i].num);
		if(ord[0] == 'r') op[i].p = 0;
		else op[i].p = 1;
		op[i].ord = i;
	}
	std::sort(op+1, op+1+n, cmp_num);
	long long now = op[1].num + 1;
	for(int i = 1; i <= n; i++)
	{
		if(op[i].num != now)
		{
			now = op[i].num;
			op[i].num = i;
			hash[i] = now;
		}
		else op[i].num = op[i-1].num;
	}
	std::sort(op+1, op+1+n, cmp_ord);
	//for(int i = 1; i <= n; i++) printf("===%d %d  %d===\n", op[i].p, op[i].num, hash[op[i].num]);
}

void add(int p, int l, int r, int x)
{
	if(l == r && l == x)
	{
		sum[p]++;
		return;
	}
	int mid = l + (r - l) / 2;
	if(x <= mid) add(p*2, l, mid, x);
	else add(p*2+1, mid+1, r, x);
	sum[p] = sum[p*2] + sum[p*2+1];
}

bool remove(int p, int l, int r, int x)
{
	if(l == r && l == x)
	{
		if(!sum[p]) return 0;
		sum[p]--;
		return 1;
	}
	int mid = l + (r - l) / 2;
	bool flag;
	if(x <= mid) flag = remove(p*2, l, mid, x);
	else flag = remove(p*2+1, mid+1, r, x);
	sum[p] = sum[p*2] + sum[p*2+1];
	return flag;
}

int query(int p, int l, int r, int k)
{
	if(l == r) return l;
	int mid = l + (r - l) / 2;
	if(k <= sum[p*2]) return query(p*2, l, mid, k);
	else return query(p*2+1, mid+1, r, k-sum[p*2]);
}

void ask()
{
	long long res = hash[query(1, 1, n, sum[1]/2+1)];
	if(sum[1] % 2 == 0)
	{
		res = res + hash[query(1, 1, n, sum[1]/2)];
		if(res == -1)
		{
			printf("-0.5\n");
			return;
		}
		printf("%lld", res/2);
		if(abs(res) % 2 == 1) printf(".5");
		printf("\n");
	}
	else printf("%lld\n", res);
}

void solve()
{
	scanf("%d", &n);
	dosth();
	for(int i = 1; i <= n; i++)
	{
		if(op[i].p == 0) //remove
		{
			if(!remove(1, 1, n, op[i].num)) printf("Wrong!\n");
			else{
				if(sum[1] == 0) printf("Empty!\n");
				else ask();
			}
		}
		else{ //add
			add(1, 1, n, op[i].num);
			ask();
		}
	}
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		memset(sum, 0, sizeof(sum));
		memset(hash, 0, sizeof(hash));
		solve();
	}
	return 0;
}
