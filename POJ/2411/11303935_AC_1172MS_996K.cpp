#include<cstdio>
#include<cstring>
typedef long long LL;
const int N=13;
int n,m,all;
LL f[N][1<<N];

void PT(int s)//_Debug用的，打印01序列
{
	int a[N];
	for(int i=m;i>0;i--)
	{
		a[i]=s&1;
		s>>=1;
	}
	for(int i=1;i<=m;i++) printf("%d",a[i]);
	puts("");
}

bool hash(int s)//判断剩下的0能否用横着的填满
{
	for(int i=0;i<m;)
	{
		if((s&(1<<i))==0)
		{
			if(i==m-1) return false;//如果第m-1位为0，但是已经是最后一位，显然无法满足了
			if ((s&(1<<(i+1)))!=0) return false;//当前为0，但是下一位不为0，显然不成立
			i+=2;
		}
		else i++;
	}
	return true;
}

bool could(int s1,int s2)
{
	bool flag1=(s1&s2)==0;//可行的话两个1必定不会重叠位置
	bool flag2=hash(s1|s2);//看剩下的位置能否用横着的木板填满
	return flag1&&flag2;
}

void work()
{
	all=(1<<m)-1;
	f[1][0]=1;
	for(int i=1;i<=n;i++)
	for(int S=0;S<=all;S++)
	for(int st=0;st<=all;st++)
	{
		//PT(S);PT(st);
		if(could(S,st))
		{
			//printf("%d\n",f[i+1][S]);
			f[i+1][S]+=f[i][st];
		}
	}
	printf("%lld\n",f[n+1][0]);
}

int main()
{
	//freopen("poj2411.in","r",stdin);
	//freopen("poj2411.out","w",stdout);
	while(scanf("%d%d",&n,&m)==2 && n && m)
	{
		memset(f,0,sizeof(f));
		work();
	}
	return 0;
}
