#include <cstdio>
#include <cstdlib>
#include <ctime>

const int N = 100000 + 10;

int m, Limit;
int L[N], R[N], S[N], fix[N], key[N];
int root, total, leave;

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

void insert(int &p, int x)
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
		insert(L[p], x);
		if(fix[L[p]] > fix[p]) rotate_right(p);
	}
	else {
		insert(R[p], x);
		if(fix[R[p]] > fix[p]) rotate_left(p);
	}
}

void remove(int &p, int limit)
{
	if(!p) return;
	if(key[p] < limit)
	{
		leave += S[L[p]] + 1;
		p = R[p];
		remove(p, limit);
	}
	else{
		remove(L[p], limit);
		S[p] = S[L[p]] + S[R[p]] + 1;
	}
}

int kth(int &p, int k)
{
	if(k <= S[L[p]]) return kth(L[p], k);
	else if(k == S[L[p]] + 1) return key[p];
	else return kth(R[p], k - S[L[p]] - 1);
}

int main()
{
	srand(time(0));
	scanf("%d%d", &m, &Limit);
	int delta = 0;
	while(m--)
	{
		char op; int x;
		scanf(" %c%d", &op, &x);
		if(op == 'I')
		{
			if(x < Limit) continue;
			insert(root, x - delta);
		}
		else if(op == 'A') delta += x;
		else if(op == 'S')
		{
			delta -= x;
			remove(root, Limit - delta);
		}
		else {
			x = S[root] - x + 1;
			if(x <= 0) puts("-1");
			else printf("%d\n", kth(root, x) + delta);
		}
	}
	printf("%d\n", leave);
	return 0;
}
