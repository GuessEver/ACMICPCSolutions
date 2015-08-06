#include <cstdio>
#include <iostream>

const int N = 2 * 100000 + 10;
struct SBT {
	int S[N], L[N], R[N];
	long long A[N];
	int root, total;
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
	void Insert(int &p, long long x)
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
	void Delete(int &p, long long x)
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
	int Query_leq(int &p, long long x)
	{
		if(!p) return 0;
		if(A[p] <= x) return S[L[p]] + 1 + Query_leq(R[p], x);
		else return Query_leq(L[p], x);
	}
	int Query_geq(int &p, long long x)
	{
		if(!p) return 0;
		if(A[p] >= x) return S[R[p]] + 1 + Query_geq(L[p], x);
		else return Query_geq(R[p], x);
	}
}head, tail;
int n, k, a[N];
int L[N], R[N];
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
	{
		if(a[i] % k == 0)
		{
			long long x = 1ll * a[i] / k;
			L[i] = head.Query_leq(head.root, x) - head.Query_leq(head.root, x - 1);
		}
		head.Insert(head.root, a[i]);
	}
	for(int i = n; i >= 1; i--)
	{
		if(a[i] % k == 0)
		{
			long long x = 1ll * a[i] * k;
			R[i] = tail.Query_geq(tail.root, x) - tail.Query_geq(tail.root, x + 1);
		}
		tail.Insert(tail.root, a[i]);
	}
	long long res = 0;
	for(int i = 1; i <= n; i++) res += 1ll * L[i] * R[i];
	std::cout << res << std::endl;
	return 0;
}
