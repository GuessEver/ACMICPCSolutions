#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef struct{
	int ed,st,d;
}node;
node g[1010];
int tot,n,flag,num,maxid;
char s[10],s1[10],s2[10];
int len[1010];
bool cmp(node p1,node p2){
	return(p1.st<p2.st||(p1.st==p2.st&&p1.d<p2.d));
}
bool cmp1(node p1,node p2){
	return(p1.ed<p2.ed||(p1.ed==p2.ed&&p1.d>p2.d));
}
void Solve(){
	int day,ti; 
	day=(s[0]-'0')*10+s[1]-'0';
	day=day*32+(s[3]-'0')*10+s[4]-'0';
	ti=(s1[0]-'0')*10+s1[1]-'0';
	ti=ti*60+(s1[3]-'0')*10+s1[4]-'0';
	ti=ti+day*24*60;
	//printf("%d %d %d\n",day,ti,num);
	if(s2[0]=='I') g[++tot].d=num,g[tot].st=ti;
		else for(int i=tot;i>=1;i--)
				if(g[i].d==num){g[i].ed=ti;break;}
}
int Get(int k,int i){
	return(min(g[i].ed,g[k].ed)-g[i].st);
}
int Get2(int k,int i){
	if(g[k].st<=g[i].st) return(0);
	return(g[i].ed-max(g[k].st,g[i].st));
}
int Get3(int k,int i){
	if(g[i].d==0) return(0);
	if(g[k].ed<=g[i].st||g[i].ed<=g[k].st) return(0);
	//printf("%d %d\n",g[k].d,g[i].d);
	if(g[i].st<=g[k].st) return(min(g[k].ed,g[i].ed)-g[k].st);
	if(g[i].ed>=g[k].ed) return(g[k].ed-max(g[k].st,g[i].st));
	if(g[i].ed<=g[k].ed&&g[i].st>=g[k].st) return(g[i].ed-g[i].st);

	return(0);
}
int main(){
	//freopen("test.in","r",stdin);
	while(cin>>n&&n){
		tot=maxid=0;
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;i++){
			scanf("%s",&s[0]);
			scanf("%s",&s1[0]);
			scanf("%s",&s2[0]);
			scanf("%d",&num);
			Solve();
		//	printf("aa %d\n",num);
			maxid=max(maxid,num);
		}
	flag=0;
	memset(len,0,sizeof(len));
	//for(int i=1;i<=tot;i++) printf("%d %d %d\n",g[i].st,g[i].ed,g[i].d);
	for(int i=1;i<=tot;i++){
		if(g[i].d==0) flag=i;
			else if(flag){
				if(g[i].st>g[flag].ed){flag=0;continue;}
					else len[g[i].d]+=Get(flag,i);
				}
	}
	flag=0;
	for(int i=tot;i>=1;i--){
		if(g[i].d==0) flag=i;
			else if(flag){
				if(g[i].ed<g[flag].st){flag=0;continue;}
					else len[g[i].d]+=Get2(flag,i);
		}
	}
	int maxd=0;
	memset(len,0,sizeof(len));
	for(int i=1;i<=tot;i++)
		if(g[i].d==0)
			for(int j=1;j<=tot;j++) len[g[j].d]+=Get3(i,j);
	for(int i=1;i<=maxid;i++) maxd=max(maxd,len[i]);
//	for(int i=1;i<=maxid;i++) printf("%d ",len[i]);
	printf("%d\n",maxd);
	}
}
