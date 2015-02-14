#include <cstdio>
#include <cstring>
#include <queue>
using std::queue;

struct ACG{
	int count;
	ACG *fail, *next[26];
	ACG()
	{
		fail = 0;
		count = 0;
		for(int i = 0; i < 26; i++) next[i] = 0;
	}
}*root;
queue<ACG*> Q;

void insert(char *str, ACG *p)
{
	int len = strlen(str);
	for(int i = 0; i < len; i++)
	{
		int x = str[i] - 'a';
		if(!p -> next[x]) p -> next[x] = new ACG;
		p = p -> next[x];
	}
	p -> count ++;
}

void build_acg()
{
	while(!Q.empty()) Q.pop();
	Q.push(root);
	while(!Q.empty())
	{
		ACG *p = Q.front(); Q.pop();
		for(int i = 0; i < 26; i++)
		{
			if(p -> next[i])
			{
				if(p == root) p -> next[i] -> fail = root;
				else{
					ACG *temp = p -> fail;
					while(temp)
					{
						if(temp -> next[i])
						{
							p -> next[i] -> fail = temp -> next[i];
							break;
						}
						temp = temp -> fail;
					}
					if(!temp) p -> next[i] -> fail = root;
				}
				Q.push(p -> next[i]);
			}
		}
	}
}

int query(char *str, ACG *p)
{
	int len = strlen(str), res = 0;
	for(int i = 0; i < len; i++)
	{
		int x = str[i] - 'a';
		while(!p -> next[x] && p != root) p = p -> fail;
		p = p -> next[x];
		if(!p) p = root;
		ACG *temp = p;
		while(temp != root && temp -> count != -1)
		{
			res += temp -> count;
			temp -> count = -1;
			temp = temp -> fail;
		}
	}
	return res;
}

int n;
char tmp[1000000+10];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		root = new ACG;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%s", tmp);
			insert(tmp, root);
		}
		build_acg();
		scanf("%s", tmp);
		printf("%d\n", query(tmp, root));
	}
	return 0;
}
