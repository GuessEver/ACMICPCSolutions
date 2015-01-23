#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define see(x) cerr<<#x<<" "<<x<<endl
#define se(x) cerr<<" "<<x 
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (long long i=l;i<=r;i++)
#define repdown(i,l,r) for (long long i=l;i<=r;i--)
using namespace std;
ll T,n,m,que,x,y,num,cnt,tail,q[10010],dfn[10010],low[10010],vis[10010],fa[10010],color[10010],top[10010],next[200200];
struct edge{
	int u,v;
}e[200200];
void add(){
	ll x,y;
	
	scanf("%lld%lld",&x,&y);//cout<<"!"<<endl;
	e[++num].u=x;e[num].v=y;next[num]=top[x];top[x]=num;
	e[++num].u=y;e[num].v=x;next[num]=top[y];top[y]=num;
}
void dfs(ll x,ll ax){
	ll y;
	++T;dfn[x]=T;low[x]=T;
	q[++tail]=x;
	y=top[x]; while (y) {
		if (e[y].v!=ax){
		if (!vis[e[y].v]) {
			vis[e[y].v]=1;
			dfs(e[y].v,x);
			low[x]=min(low[x],low[e[y].v]);
		}
		else low[x]=min(low[x],low[e[y].v]);
		}
		y=next[y];
	}
	if (low[x]==dfn[x]){
		cnt++;
		while (q[tail+1]!=x) color[q[tail--]]=cnt;
	}
}
ll getfather(ll x){
	return fa[x]==x?x:fa[x]=getfather(fa[x]);
}
int main(){
	freopen("H.in", "r", stdin);
	freopen("H.out", "w", stdout);
	ll x,y;
	while (cin>>n>>m>>que && n!=0 && m!=0){
		num=0;clr(top,0);
		rep(i,1,m) add();
		clr(vis,0);cnt=0;tail=0;
		rep(i,1,n) 
			if (!vis[i]) {
				vis[i]=1;T=0;dfs(i,0);
			}
		//rep(i,1,n) cout<<i<<" "<<dfn[i]<<" "<<low[i]<<" "<<color[i]<<endl;
		//sort(e+1,e+1+m,cmp);
		rep(i,1,n) fa[i]=i;
		for(ll i=1;i<=m*2;i+=2)
		if (color[e[i].u]!=color[e[i].v])
		{
			x=getfather(e[i].u);
			//cout<<"x is ready"<<endl;
			y=getfather(e[i].v);
			//cout<<"y is ready"<<endl;
			if (x!=y){
				fa[x]=y;
			}
		}
		//rep(i,1,n) cout<<i<<" "<<fa[i]<<endl;
		rep(i,1,que){
			scanf("%lld%lld",&x,&y);
			x=getfather(x);
			y=getfather(y);
			if (x==y) printf("%c\n",'Y');else printf("%c\n",'N');
		}
		printf("%c\n",'-');
	}
	return 0;
}

