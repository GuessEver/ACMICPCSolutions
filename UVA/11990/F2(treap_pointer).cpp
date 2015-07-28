// Solution: http://www.guessbug.com/problem/UVa/11990
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
using std::set;

const int N = 2000000 + 10;

int n, m, a[N];
int pos[N];

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
	int Query_less(Treap *p, int x) // count number in [0, x]
	{
		if(p == null) return 0;
		if(p -> key <= x)
			return p -> left -> size + 1 + Query_less(p -> right, x);
		else return Query_less(p -> left, x);
	}
	int Query_greater(Treap *p, int x) // count number in [x, +oo)
	{
		if(p == null) return 0;
		if(p -> key >= x)
			return p -> right -> size + 1 + Query_greater(p -> left, x);
		else return Query_greater(p -> right, x);
	}
}tree[N], root;

inline int lowbit(int x) { return x & -x; }

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
		size += tree[p].root -> size;
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
		root.init();
		for(int i = 1; i <= n; i++) tree[i].init();
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
