#include <cstdio>
#include <cstring>
#include <algorithm>

int n;
struct Trie{
	int bit, id;
	Trie *next[2];
	Trie()
	{
		bit = id = 0;
		next[0] = next[1] = 0;
	}
}*root;
int tmp[100], len = 0;

void insert(Trie *p, int id)
{
	for(int i = 1; i <= 20; i++)
	{
		if(!p -> next[tmp[i]]) p -> next[tmp[i]] = new Trie;
		p = p -> next[tmp[i]];
	}
	p -> id = id;
}

int init()
{
	int x; scanf("%d", &x);
	int tmpx = x;
	memset(tmp, 0, sizeof(tmp));
	for(int i = 1; i <= 20; i++)
	{
		tmp[i] = x & 1;
		x >>= 1;
	}
	for(int i = 1, j = 20; i < j; i++, j--)
		std::swap(tmp[i], tmp[j]);
	//for(int i = 1; i <= 20; i++) printf("%d", tmp[i]); puts("");
	return tmpx;
}

int find(Trie *p)
{
	for(int i = 1; i <= 20; i++)
	{
		if(p -> next[1-tmp[i]]) p = p -> next[1-tmp[i]];
		else p = p -> next[tmp[i]];
	}
	return p -> id;
}

int main()
{
	root = new Trie;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int x = init();
		insert(root, x);
	}
	int q; scanf("%d", &q);
	while(q--)
	{
		int op; scanf("%d", &op);
		int x = init();
		if(op == 0) insert(root, x);
		else printf("%d\n", find(root));
	}
	return 0;
}
