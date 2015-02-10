#include <cstdio>
#include <cstdlib>
#include <ctime>

int m, Limit;
struct Treap{
	int fix, key, size;
	Treap *left, *right;
}*root;
int leave;

void rotate_left(Treap *&p)
{
	Treap *tmp = p -> right;
	p -> right = tmp -> left;
	int zsize = tmp -> left ? tmp -> left -> size : 0;
	p -> size = p -> size - tmp -> size + zsize;
	tmp -> left = p;
	tmp -> size = tmp -> size - zsize + p -> size;
	p = tmp;
}
void rotate_right(Treap *&p)
{
	Treap *tmp = p -> left;
	p -> left = tmp -> right;
	int zsize = tmp -> right ? tmp -> right -> size : 0;
	p -> size = p -> size - tmp -> size + zsize;
	tmp -> right = p;
	tmp -> size = tmp -> size - zsize + p -> size;
	p = tmp;
}

void insert(Treap *&p, int x)
{
	if(!p)
	{
		p = new Treap;
		p -> fix = rand();
		p -> key = x;
		p -> size = 1;
		p -> left = 0;
		p -> right = 0;
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
	if(!p) return;
	if(p -> key < L)
	{
		leave += (p -> left ? p -> left -> size : 0) + 1;
		p = p -> right;
		remove(p, L);
	}
	else {
		remove(p -> left, L);
		int lsize = p -> left ? p -> left -> size : 0;
		int rsize = p -> right ? p -> right -> size : 0;
		p -> size = lsize + rsize + 1;
	}
}

int kth(Treap *&p, int k)
{
	int Lsize = p -> left ? p -> left -> size : 0;
	if(k <= Lsize) return kth(p -> left, k);
	else if(k == Lsize + 1) return p -> key;
	else return kth(p -> right, k - Lsize - 1);
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
			int tot = root ? root -> size : 0;
			x = tot - x + 1;
			if(x <= 0) puts("-1");
			else printf("%d\n", kth(root, x) + delta);
		}
	}
	printf("%d\n", leave);
	return 0;
}
