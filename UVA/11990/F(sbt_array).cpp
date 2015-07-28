// Solution: http://www.guessbug.com/problem/UVa/11990
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#define lowbit(x) ((x)&(-x))
const int N = 200000 + 10;

int n, m, a[N];
int pos[N];

int A[N*20], S[N*20], L[N*20], R[N*20], total;
struct SBT {
	int root;
	void rotate_left(int &x)
	{
		int y = R[x];
		R[x] = L[y];
		L[y] = x;
		S[y] = S[x];
		S[x] = S[L[x]] + S[R[x]] + 1;
		x = y;
	}
	void rotate_right(int &x)
	{
		int y = L[x];
		L[x] = R[y];
		R[y] = x;
		S[y] = S[x];
		S[x] = S[L[x]] + S[R[x]] + 1;
		x = y;
	}
	void maintain(int &p, bool flag)
	{
		if(flag)
		{
			if(S[R[R[p]]] > S[L[p]]) rotate_left(p);
			else if(S[R[L[p]]] > S[L[p]])
			{
				rotate_right(R[p]);
				rotate_left(p);
			}
			else return;
		}
		else
		{
			if(S[L[L[p]]] > S[R[p]]) rotate_right(p);
			else if(S[L[R[p]]] > S[R[p]])
			{
				rotate_left(L[p]);
				rotate_right(p);
			}
			else return;
		}
		maintain(L[p], 0);
		maintain(R[p], 1);
		maintain(p, 0);
		maintain(p, 1);
	}
	void Insert(int &p, int x)
	{
		if(!p)
		{
			p = ++total;
			L[p] = R[p] = 0;
			A[p] = x; S[p] = 1;
			return;
		}
		S[p]++;
		if(x < A[p]) Insert(L[p], x);
		else Insert(R[p], x);
		maintain(p, x >= A[p]);
	}
	int Delete_min(int &p)
	{
		S[p]--;
		if(!L[p])
		{
			int value = A[p];
			p = R[p];
			return value;
		}
		else return Delete_min(L[p]);
	}
	void Delete(int &p, int x)
	{
		if(!p) return;
		S[p]--;
		if(x < A[p]) Delete(L[p], x);
		else if(x > A[p]) Delete(R[p], x);
		else {
			if(!L[p] && !R[p]) p = 0;
			else if(!L[p] || !R[p])
			{
				if(!L[p]) p = R[p];
				else p = L[p];
			}
			else A[p] = Delete_min(R[p]);
		}
	}
	int Query_less(int &p, int x)
	{
		if(!p) return 0;
		if(A[p] <= x) return S[L[p]] + 1 + Query_less(R[p], x);
		else return Query_less(L[p], x);
	}
	int Query_greater(int &p, int x)
	{
		if(!p) return 0;
		if(A[p] >= x) return S[R[p]] + 1 + Query_greater(L[p], x);
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
