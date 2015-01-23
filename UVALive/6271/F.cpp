#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 1100
using namespace std;
int g[maxn][maxn],a[maxn][maxn],match[maxn],v[maxn],f[maxn],q1[maxn],q2[maxn];
int ans[maxn*4][3];
char s[maxn];
int top1,top2,n,tot,pre;
int Dfs(int k){
	int j;
	for(int i=1;i<=n;i++){
		if(!v[i]&&g[i][k]){
			v[i]=1;
			if(!match[i]||Dfs(match[i])){
				match[k]=i;match[i]=k;
				return(1);
			}
		}
	}
	return(0);
}
int main(){
	//freopen("test.in","r",stdin);
	while(cin>>n){
		for(int i=1;i<=n;i++){
			scanf("%s\n",&s[0]);
			for(int j=0;j<n;j++) a[i][j+1]=s[j]-'0';
		}
		top1=top2=tot=0;
		memset(f,0,sizeof(f));
		for(int t=1;t<=log(n)/log(2);t++){
			top1=top2=0;
			for(int i=2;i<=n;i++)
				if(!f[i]){
					if(a[1][i]) q1[++top1]=i;
						else q2[++top2]=i;
				}
			memset(g,0,sizeof(g));
			memset(match,0,sizeof(match));
			for(int i=1;i<=top1;i++)
				for(int j=1;j<=top2;j++) 
					g[q1[i]][q2[j]]=a[q1[i]][q2[j]],g[q2[j]][q1[i]]=a[q2[j]][q1[i]];
			for(int i=1;i<=top2;i++){
				memset(v,0,sizeof(v));
				Dfs(q2[i]);
			}
			for(int i=1;i<=top2;i++)
				if(match[q2[i]]){
				ans[++tot][1]=q2[i],ans[tot][2]=match[q2[i]];
				if(a[ans[tot][1]][ans[tot][2]]) f[ans[tot][2]]=1;
				else f[ans[tot][1]]=1;
			}
			for(int i=1;i<=top1;i++) if(!match[q1[i]]){
				match[q1[i]]=1;
				ans[++tot][1]=1;ans[tot][2]=q1[i];
				f[q1[i]]=1;
				break;
			}
			pre=1;
			for(int i=1;i<=top2;i++)
			if(!match[q2[i]])
				if(pre==1) ans[++tot][1]=q2[i],pre=2;
					else{
						ans[tot][2]=q2[i],pre=1;
						if(a[ans[tot][1]][ans[tot][2]]) f[ans[tot][2]]=1;
							else f[ans[tot][1]]=1;
					}
			for(int i=1;i<=top1;i++)
				if(!match[q1[i]])
					if(pre==1) ans[++tot][1]=q1[i],pre=2;
					else{
						ans[tot][2]=q1[i],pre=1;
						if(a[ans[tot][1]][ans[tot][2]]) f[ans[tot][2]]=1;
							else f[ans[tot][1]]=1;
					}
			}
			for(int i=1;i<=tot;i++) printf("%d %d\n",min(ans[i][1],ans[i][2]),max(ans[i][1],ans[i][2]));
			//printf("\n");
	}
	return 0;
}
