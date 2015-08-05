#include <cstdio>

const int N = 1000000 + 10;

struct SBT {
	int A[N], S[N], L[N], R[N];
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
	int query_min(int &p)
	{
		if(!L[p]) return A[p];
		return query_min(L[p]);
	}
	int query_max(int &p)
	{
		if(!R[p]) return A[p];
		return query_max(R[p]);
	}
}tr;

int main()
{
	int q; scanf("%d", &q);
	while(q--)
	{
		int op; scanf("%d", &op);
		if(op == 1)
		{
			int x; scanf("%d", &x);
			tr.Insert(tr.root, x);
		}
		else if(op == 2)
		{
			if(tr.S[tr.root] == 0) continue;
			int min = tr.query_min(tr.root);
			tr.Delete(tr.root, min);
		}
		else if(op == 3)
		{
			if(tr.S[tr.root] == 0) puts("0");
			else printf("%d\n", tr.query_max(tr.root));
		}
	}
	return 0;
}
