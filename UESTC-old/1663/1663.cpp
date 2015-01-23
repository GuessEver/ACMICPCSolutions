#include<cstdio>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef long long LL;
const int N=40+10;
const int NN=50*50;
const int dx[]={0,0,-1,1};
const int dy[]={1,-1,0,0};
const int inf=0x3f3f3f3f;
const LL  infll=0x3f3f3f3f3f3f3f3fLL;

int n,m;
int map[N][N],color[N][N];
struct EG{int y;LL flow;int next;}edge[NN*10];
int head[NN],L;
int v[NN],h[NN];
int S,T;
LL num[2],sum[2],maxp=0;

void read()
{
	scanf("%d%d",&n,&m);
	int cc=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&map[i][j]);
			color[i][j]=!color[i][j-1];
			if(j==1) color[i][j]=(cc=!cc);
			num[color[i][j]]++;
			sum[color[i][j]]+=map[i][j];
			maxp=max(maxp,map[i][j]);
		}
}

inline int get(int x,int y) { return (x-1)*m+y; }

LL sap(int x,LL flow)
{
	if(x==T) return flow;
	LL res=0;
	for(int i=head[x];i!=-1;i=edge[i].next)
		if(edge[i].flow && h[x]==h[edge[i].y]+1)
		{
			LL t=sap(edge[i].y,min(edge[i].flow,flow-res));
			edge[i].flow-=t;
			edge[i^1].flow+=t;
			if((res+=t)>=flow) return res;
			if(h[S]>T) return res;
		}
	if((--v[h[x]])==0) h[S]=T+1;
	++v[++h[x]];
	return res;
}

void inlink(int x,int y,LL z)
{
	edge[L]=(EG){y,z,head[x]};
	head[x]=L++;
	edge[L]=(EG){x,0,head[y]};
	head[y]=L++;
}

bool check(LL final)
{
	memset(edge,0,sizeof(edge));
	memset(head,-1,sizeof(head));L=0;
	memset(v,0,sizeof(v));
	memset(h,0,sizeof(h));
	S=0;T=get(n,m)+1;
	LL total=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			LL tmp=final-map[i][j];
			//if(tmp<0) return 0;
			if(color[i][j]==0) inlink(S,get(i,j),tmp);
			else inlink(get(i,j),T,tmp);
			total+=tmp;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<4;k++)
			{
				int x=i+dx[k],y=j+dy[k];
				if(x<1||x>n||y<1||y>m) continue;
				if (color[i][j]==0) inlink(get(i,j),get(x,y),infll);
			}
	v[0]=T+1;
	LL maxflow=0;
	while(h[S]<T+1) maxflow+=sap(S,infll);
	//fprintf(stderr,"%lld  ->  %lld %lld\n",final,maxflow,total);
	return total==(maxflow*2);
}

inline LL getans(LL x)
{
	return ((LL)n*m*x-sum[0]-sum[1])/2;
}

void work()
{
	if((n*m)%2==0)
	{
		LL L=1,R=infll/1000,M;
		int ans=-1;
		while(L<=R)
		{
			M=L+((R-L)>>1);
			if(check(M)) R=M-1,ans=M;
			else L=M+1;
			//fprintf(stderr,"L=%lld,R=%lld,M=%lld\n",L,R,M);
		}
		//fprintf(stderr,"%d  ->  ",ans);
		if(ans==-1) printf("%d\n",ans);
		else printf("%lld\n",getans(ans));
	}
	else{
		bool flag=0;
		LL x=(sum[0]-sum[1]);
		if(x>=maxp && check(x)) flag=1;
		if(flag) printf("%lld\n",getans(x));
		else printf("-1\n");
	}
}

int main()
{
	int T; scanf("%d",&T);
	while(T--)
	{
		memset(map,0,sizeof(map));
		memset(color,0,sizeof(color));
		sum[0]=sum[1]=num[0]=num[1]=maxp=0;
		read();
		work();
		/*fprintf(stderr,"begin\n");
		check(1018665183LL);
		fprintf(stderr,"end\n");
		check(1027154059LL);
		fprintf(stderr,"end\n");*/
	}
	//while(1);
	return 0;
} 				    
