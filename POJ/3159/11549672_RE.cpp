#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <queue>
#include <limits.h>
#define MAX 30010
using namespace std;
typedef struct CANDY{
	int to,len;
	int num; 
	CANDY *next;
}CANDDY;
CANDY *kid[MAX],node[MAX*10];
typedef struct DIS{
	int len,num;
}DIS;
int cou,n;
void init()
{
	memset(kid,'/0',sizeof(kid));
	memset(node,'/0',sizeof(node));
	cou = 0;
}
bool operator<(DIS a,DIS b)
{
	return a.len > b.len;
}
priority_queue <DIS> Q;
int Dijkstra()
{
	while( !Q.empty() )
		Q.pop(); 
	int i,k,used[MAX],now,len,to;
	DIS dis[MAX],tmp;
	CANDY *head;
	memset(used,0,sizeof(used));
	for(i=1; i<=n; i++)
	{
		dis[i].num = i;
		dis[i].len = INT_MAX;
	}
	dis[1].len = 0;
	dis[1].num = 1;
	Q.push(dis[1]);
	while( !Q.empty() )
	{
		tmp = Q.top();
		Q.pop();
		now = tmp.num;
		if( used[now] == 1 )
			continue;
		used[now] = 1;
		head = kid[now];
		while( head != NULL )
		{
			len = head->len;
			to = head->to;
			if( dis[to].len > dis[now].len + len )
			{
				dis[to].len = dis[now].len + len;
				Q.push(dis[to]);
			}
			head = head->next;
		}
	}
	return dis[n].len;
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
		ans = Dijkstra();
		printf("%d/n",ans);
	}
return 0;
}
