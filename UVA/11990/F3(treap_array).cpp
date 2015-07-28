// Solution: http://www.guessbug.com/problem/UVa/11990
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#define lowbit(x) ((x)&(-x))
const int N = 200000 + 10;

int n, m, a[N];
int pos[N];

int L[N*20], R[N*20], S[N*20], fix[N*20], key[N*20];
int total;
struct treap {
	int root;
	void rotate_left(int &p)
	{
		int tmp = R[p];
		R[p] = L[tmp];
		int zsize = S[L[tmp]];
		S[p] = S[p] - S[tmp] + zsize;
		L[tmp] = p;
		S[tmp] = S[tmp] - zsize + S[p];
		p = tmp;
	}
	void rotate_right(int &p)
	{
		int tmp = L[p];
		L[p] = R[tmp];
		int zsize = S[R[tmp]];
		S[p] = S[p] - S[tmp] + zsize;
		R[tmp] = p;
		S[tmp] = S[tmp] - zsize + S[p];
		p = tmp;
	}
	void Insert(int &p, int x)
	{
		if(!p)
		{
			p = ++total;
			L[p] = R[p] = 0;
			S[p] = 1;
			fix[p] = rand();
			key[p] = x;
			return;
		}
		S[p]++;
		if(x < key[p])
		{
			Insert(L[p], x);
			if(fix[L[p]] > fix[p]) rotate_right(p);
		}
		else {
			Insert(R[p], x);
			if(fix[R[p]] > fix[p]) rotate_left(p);
		}
	}
	int Delete_min(int &p)
	{
		S[p]--;
		if(!L[p])
		{
			int value = key[p];
			p = R[p];
			return value;
		}
		else return Delete_min(L[p]);
	}
	void Delete(int &p, int x)
	{
		if(!p) return;
		S[p]--;
		if(x < key[p]) Delete(L[p], x);
		else if(x > key[p]) Delete(R[p], x);
		else {
			if(!L[p] && !R[p]) p = 0;
			else if(!L[p] || !R[p])
			{
				if(!L[p]) p = R[p];
				else p = L[p];
			}
			else key[p] = Delete_min(R[p]);
		}
	}
	int Query_less(int &p, int x)
	{
		if(!p) return 0;
		if(key[p] <= x) return S[L[p]] + 1 + Query_less(R[p], x);
		else return Query_less(L[p], x);
	}
	int Query_greater(int &p, int x)
	{
		if(!p) return 0;
		if(key[p] >= x) return S[R[p]] + 1 + Query_greater(L[p], x);
		else return Query_greater(R[p], x);
	}
}tree[N], root;

void Insert(int a, int x)
{
	for(int p = a; p <= n; p += lowbit(p))
		tree[p].Insert(tree[p].root, x);
}
void Delete(int a, int x)
{
	for(int p = a; p <= n; p += lowbit(p))
		tree[p].Delete(tree[p].root, x);
}
int Query_greater(int a, int c, int &size)
{
	int res = 0; size = 0;
	for(int p = a; p > 0; p -= lowbit(p))
	{
		size += S[tree[p].root];
		res += tree[p].Query_greater(tree[p].root, c);
	}
	return res;
}
int Query_less(int a, int c)
{
	int res = 0;
	for(int p = a; p > 0; p -= lowbit(p))
		res += tree[p].Query_less(tree[p].root, c);
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
	while(scanf("%d%d", &n, &m) == 2)
	{
		total = root.root = 0;
		for(int i = 1; i <= n; i++) tree[i].root = 0;
		long long res = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			pos[a[i]] = i;
			Insert(i, a[i]); root.Insert(root.root, a[i]);
			res += root.Query_greater(root.root, a[i] + 1);
		}
		for(int i = 1; i <= m; i++)
		{
			int x; scanf("%d", &x);
			Delete(pos[x], x); root.Delete(root.root, x);
			printf("%lld\n", res);
			int left_greater, left_size = 0;
			left_greater = Query_greater(pos[x] - 1, x, left_size);
			int all_less = root.Query_less(root.root, x - 1);
			res -= left_greater + (all_less - (left_size - left_greater));
		}
	}
	return 0;
}
