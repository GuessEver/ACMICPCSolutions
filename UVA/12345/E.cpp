// Solution: http://www.guessbug.tk/problem/UVa/12345
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

void debug_pre_a()
{
	for(int i = 1; i <= n; i++) printf("%d ", a[i]); puts("");
	for(int i = 1; i <= n; i++) printf("%d ", pre[i]); puts("");
	puts("======");
}

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
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) pos[a[i]].insert(i);
	for(int i = 1; i <= n; i++)
	{
		pre[i] = P[a[i]];
		P[a[i]] = i;
	}
	//debug_pre_a();
	build_map(1, 1, n);
	for(int i = 1; i <= n; i++) Insert(1, 1, n, i, pre[i]);
	while(m--)
	{
		char op; int x, y;
		scanf(" %c%d%d", &op, &x, &y); x++;
		if(op == 'Q') // [x, y]
		{
			printf("%d\n", Query(1, 1, n, x, y)); // pre[x..y] < x
		}
		else {
			set<int>::iterator it = pos[a[x]].upper_bound(x);
			if(it != pos[a[x]].end())
			{
				Delete(1, 1, n, *it, pre[*it]);
				pre[*it] = pre[x];
				Insert(1, 1, n, *it, pre[*it]);
			}
			pos[a[x]].erase(x); //delete the previous position x
			// deal with a[x] = y
			if(pos[y].size() == 0)
			{
				Delete(1, 1, n, x, pre[x]);
				pre[x] = 0;
				Insert(1, 1, n, x, pre[x]);
			}
			else {
				set<int>::iterator jt = pos[y].lower_bound(x);
				if(jt == pos[y].end())
				{
					Delete(1, 1, n, x, pre[x]);
					jt--; pre[x] = *jt;
					Insert(1, 1, n, x, pre[x]);
				}
				else {
					Delete(1, 1, n, *jt, pre[*jt]);
					pre[*jt] = x;
					Insert(1, 1, n, *jt, pre[*jt]);
					Delete(1, 1, n, x, pre[x]);
					if(jt == pos[y].begin()) pre[x] = 0;
					else { jt--; pre[x] = *jt; }
					Insert(1, 1, n, x, pre[x]);
				}
			}
			a[x] = y; pos[y].insert(x);
		}
		//debug_pre_a();
	}
	return 0;
}
