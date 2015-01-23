#include<cstdio>
#include<map>
using std::map;
int n;
map<int,int> d;
map<int,bool> vis;

int f(int x)
{
	if(x>=0) return 5;
	if(vis[x]) return d[x];
	vis[x]=1;
	return d[x]=f(x+1)+f(x+2)+1;
}

int main()
{
	scanf("%d",&n);
	printf("%d\n",f(n));
	//while(1);
	return 0;
}
