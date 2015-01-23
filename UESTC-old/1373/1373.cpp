#include<cstdio>

long long n;

void work()
{
	scanf("%lld",&n);
	long long j=1;
	int cnt=0;
	while(j<=n)
	{
		if((j&n)!=0)//当前位为1
		{
			cnt++;//记录需要向右移动的1的个数
			if(((j<<1LL)&n)==0)//前一位为0
			{
				n=n&(~j);
				n=n|(j<<1LL);
				cnt--;//当前位向左移，不需要向右移
				break;
			}
		}
		j=j<<1LL;
	}
	long long tmp=n;
	int one=cnt;//我们用one表示有几个0需要被给城1，用cnt表示有几个1需要被改成0
	int pos=0;
	while(tmp)
	{
		int t=tmp&1;
		if(t && one)//当前位为1
		{
			n=n&(~(1LL<<pos));//当前位改成0
			one--;
			t=0;
		}
		if(!t && cnt)//当前位为0
		{
			n=n|(1LL<<pos);
			cnt--;
		}
		if(one==0 && cnt==0) break;
		pos++;
		tmp>>=1;
	}
	printf("%lld\n",n);
}

int main()
{
	freopen("1373.in","r",stdin);
	freopen("1373.out","w",stdout);
	int t; scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{
		printf("Case #%d: ",cas);
		work();
	}
	return 0;
}
