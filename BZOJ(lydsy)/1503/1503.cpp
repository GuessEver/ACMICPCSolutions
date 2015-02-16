#include <cstdio>
#include <cstdlib>
#include <ctime>

int m, Limit;
struct Treap{
	int fix, key, size;
	Treap *left, *right;
}*root, *null;
int leave;

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

void insert(Treap *&p, int x)
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
		insert(p -> left, x);
		p -> size++;
		if(p -> left -> fix > p -> fix) rotate_right(p);
	}
	else {
		insert(p -> right, x);
		p -> size++;
		if(p -> right -> fix > p -> fix) rotate_left(p);
	}
}

void remove(Treap *&p, int L)
{
	if(p == null) return;
	if(p -> key < L)
	{
		leave += p -> left -> size + 1;
		p = p -> right;
		remove(p, L);
	}
	else {
		remove(p -> left, L);
		p -> size = p -> left -> size + p -> right -> size + 1;
	}
}

int kth(Treap *&p, int k)
{
	int Lsize = p -> left -> size;
	if(k <= Lsize) return kth(p -> left, k);
	else if(k == Lsize + 1) return p -> key;
	else return kth(p -> right, k - Lsize - 1);
}

int main()
{
	srand(time(0));
	null = new Treap; root = null;
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
			x = root -> size - x + 1;
			if(x <= 0) puts("-1");
			else printf("%d\n", kth(root, x) + delta);
		}
	}
	printf("%d\n", leave);
	return 0;
}
