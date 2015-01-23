#include<cstdio>

int n;
int a[10]={6,2,5,5,4,5,6,3,7,6};

int match(int x)
{
  int sum=0;
  do
  {
    sum+=a[x%10];
    x=x/10;
  }
  while(x!=0);
  return sum;
}

int main()
{
  //freopen("rqn394.in","r",stdin);
  //freopen("rqn394.out","w",stdout);
  scanf("%d",&n);
  n-=4;
  int ans=0;
  for(int i=0;i<=1000;i++)
    for(int j=0;j<=1000;j++)
      if(match(i)+match(j)+match(i+j)==n) ans++;
  printf("%d",ans);
  return 0;
}

