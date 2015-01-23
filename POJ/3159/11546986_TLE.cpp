#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
const int N=30000+10;

int n,m;
struct link{int y,z;link *next;}*head[N];
int dist[N],inQ[N];
int relax[N];
stack<int> st;

void inlink(int x,int y,int z)
{
	link *tmp=new link;
	tmp->y=y;tmp->z=z;
	tmp->next=head[x];
	head[x]=tmp;
}

bool spfa()
{
	memset(dist,0x3f,sizeof(dist));
	dist[1]=0;st.push(1);
	while(!st.empty())
	{
		int x=st.top();st.pop();
		for(link *node=head[x];node;node=node->next)
			if(dist[node->y]>dist[x]+node->z)
			{
				dist[node->y]=dist[x]+node->z;
					if(++relax[node->y]>=n) return 0;
				if(!inQ[node->y])
				{
					inQ[node->y]=1;
					st.push(node->y);
				}
			}
		inQ[x]=0;
	}
	return 1;
}

int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int a,b,c;// b<=a+c    ->    a-b>=-c
		scanf("%d%d%d",&a,&b,&c);
		inlink(a,b,c);
	}
	spfa();
	//for(int i=1;i<=n;i++) printf("%d ",dist[i]);
	printf("%d\n",dist[n]);
	return 0;
}