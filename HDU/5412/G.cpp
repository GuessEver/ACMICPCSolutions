#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#define lowbit(x) ((x)&(-x))
const int N = 100000 + 10;

int A[N*30], S[N*30], L[N*30], R[N*30];
int total;
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
	int Query_leq(int &p, int x)
	{
		if(!p) return 0;
		if(A[p] <= x) return S[L[p]] + 1 + Query_leq(R[p], x);
		else return Query_leq(L[p], x);
	}
}tree[N];

int n, m, a[N];

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
int Query_leq(int a, int x)
{
	int res = 0;
	for(int p = a; p > 0; p -= lowbit(p))
		res += tree[p].Query_leq(tree[p].root, x);
	return res;
}
int query(int l, int r, int k)
{
	int low = 0, high = 1000000000, ans = low;
	while(low <= high)
	{
		int mid = low + (high - low) / 2;
		int tmp = Query_leq(r, mid - 1) - Query_leq(l - 1, mid - 1);
		if(tmp >= k) high = mid - 1;
		else { low = mid + 1; ans = mid; }
	}
	return ans;
}

int main()
{
	while(scanf("%d", &n) == 1)
	{
		memset(tree, 0, sizeof(tree)); total = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			Insert(i, a[i]);
		}
		scanf("%d", &m);
		while(m--)
		{
			int op, x, y;
			scanf("%d%d%d", &op, &x, &y);
			if(op == 1)
			{
				Delete(x, a[x]);
				Insert(x, a[x] = y);
			}
			else {
				int k; scanf("%d", &k);
				printf("%d\n", query(x, y, k));
			}
		}
	}
	return 0;
}
