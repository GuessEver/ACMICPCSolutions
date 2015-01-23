#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <queue>
#include <limits.h>
#include <stack>
#define MAX 30010
using namespace std;
typedef struct CANDY{
	int to,len;
	CANDY *next;
}CANDDY;
CANDY *kid[MAX],node[MAX*10];
int cou,n;
void init()
{
	memset(kid,'/0',sizeof(kid));
	memset(node,'/0',sizeof(node));
	cou = 0;
}
int SPFA()
{
	stack<int> Q;
	int i,len,to,x,inq[MAX],dis[MAX];
	CANDY *head;
	memset(inq,0,sizeof(inq));
	for(i=0; i<=n; i++)
		dis[i] = INT_MAX;
	dis[1] = 0;
	inq[1] = 1;
	Q.push(1);
	while( !Q.empty() )
	{
		x = Q.top();
		Q.pop();
		inq[x] = 0;
		head = kid[x];
		while( head != NULL )
		{
			to = head->to;
			len = head->len;
			if( dis[to] > dis[x] + len )
			{
				dis[to] = dis[x] + len;
				if( !inq[to] )
				{
					inq[to] = 1;
					Q.push(to);
				}
			}
			head = head->next;
		}
	}
	return dis[n];
}
void Add(int u,int v,int len)
{
	node[cou].to = v;
	node[cou].len = len;
	node[cou].next = kid[u];
	kid[u] = &node[cou++];
}
int main()
{
	int from,to,len,m,ans,i;
	while( scanf("%d%d",&n,&m) != EOF )
	{
		init();
		while( m-- )
		{
			scanf("%d%d%d",&from,&to,&len);
			Add(from,to,len);
		}
		ans = SPFA();
		printf("%d/n",ans);
	}
return 0;
}
