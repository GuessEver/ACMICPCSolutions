#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
using std::set;

const int N = 50000 + 10;
const int A = 1000000 + 10;

int n, m, a[N];
int pre[N], P[A];
set<int> pos[A];

struct treap {
	struct Treap{
		int fix, key, size;
		Treap *left, *right;
	}*root, *null;

	void init()
	{
		null = new Treap;
		root = null;
	}
	void rotate_left(Treap *&p)
	{
		Treap *tmp = p -> right;
		p -> right = tmp -> left;
		int zsize = tmp -> left -> size;
		p -> size = p -> size - tmp -> size + zsize;
		tmp -> left = p;
		tmp -> size = tmp -> size - zsize + p -> size;
		p = tmp;
	}
	void rotate_right(Treap *&p)
	{
		Treap *tmp = p -> left;
		p -> left = tmp -> right;
		int zsize = tmp -> right -> size;
		p -> size = p -> size - tmp -> size + zsize;
		tmp -> right = p;
		tmp -> size = tmp -> size - zsize + p -> size;
		p = tmp;
	}

	void Insert(Treap *&p, int x)
	{
		if(p == null)
		{
			p = new Treap;
			p -> fix = rand();
			p -> key = x;
			p -> size = 1;
			p -> left = null;
			p -> right = null;
			return;
		}
		if(x < p -> key)
		{
			Insert(p -> left, x);
			p -> size++;
			if(p -> left -> fix > p -> fix) rotate_right(p);
		}
		else {
			Insert(p -> right, x);
			p -> size++;
			if(p -> right -> fix > p -> fix) rotate_left(p);
		}
	}
	int Delete_min(Treap *&p)
	{
		p -> size--;
		if(p -> left == null)
		{
			int value = p -> key;
			p = p -> right;
			return value;
		}
		else return Delete_min(p -> left);
	}
	void Delete(Treap *&p, int x)
	{
		if(p == null) return;
		p -> size--;
		if(x < p -> key) Delete(p -> left, x);
		else if(x > p -> key) Delete(p -> right, x);
		else { // delete *p
			if(p -> left == null && p -> right == null)
			{
				p = null;
			}
			else if(p -> left == null || p -> right == null)
			{
				if(p -> left == null)
				{
					p = p -> right;
				}
				else { // p -> right == null
					p = p -> left;
				}
			}
			else { // p -> left != null && p -> right != null
				p -> key = Delete_min(p -> right);
			}
		}
	}
	int Query(Treap *p, int x) // count number in [0, x]
	{
		if(p == null) return 0;
		if(p -> key <= x)
			return p -> left -> size + 1 + Query(p -> right, x);
		else return Query(p -> left, x);
	}
}tree[N*4];

void Insert(int p, int l, int r, int a, int c)
{
	tree[p].Insert(tree[p].root, c);
	if(l == r) return;
	int mid = (l + r) / 2;
	if(a <= mid) Insert(p*2, l, mid, a, c);
	else Insert(p*2+1, mid+1, r, a, c);
}
void Delete(int p, int l, int r, int a, int c)
{
	tree[p].Delete(tree[p].root, c);
	if(l == r) return;
	int mid = (l + r) / 2;
	if(a <= mid) Delete(p*2, l, mid, a, c);
	else Delete(p*2+1, mid+1, r, a, c);
}
int Query(int p, int l, int r, int a, int b) // < c
{
	if(a <= l && b >= r) return tree[p].Query(tree[p].root, a - 1);
	int mid = (l + r) / 2, res = 0;
	if(a <= mid) res += Query(p*2, l, mid, a, b);
	if(b > mid) res += Query(p*2+1, mid+1, r, a, b);
	return res;
}
void build_map(int p, int l, int r)
{
	tree[p].init();
	if(l == r) return;
	int mid = (l + r) / 2;
	build_map(p*2, l, mid);
	build_map(p*2+1, mid+1, r);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) pos[a[i]].insert(i);
	for(int i = 1; i <= n; i++)
	{
		pre[i] = P[a[i]];
		P[a[i]] = i;
	}
	build_map(1, 1, n);
	for(int i = 1; i <= n; i++) Insert(1, 1, n, i, pre[i]);
	while(m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", Query(1, 1, n, x, y)); // pre[x..y] < x
	}
	return 0;
}
