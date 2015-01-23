#include<cstdio>
#include<string>
using namespace std;
#define MAXN 200000+10

int a[MAXN],n;

void qs(int l,int r)
{
  int i=l,j=r,x=a[i+(j-i)/2];
  do 
  {
    while(a[i]<x)i++;
    while(a[j]>x)j--;
    if(i<=j)
    {
      swap(a[i],a[j]);
      i++;j--;
    }
  }
  while(i<=j);
  if(i<r)qs(i,r);
  if(l<j)qs(l,j);
}

int main()
{
  //freopen("rqn133.in","r",stdin);
  //freopen("rqn133.out","w",stdout);
  scanf("%d",&n);
  int i;
  for(i=1;i<=n;i++) scanf("%d",&a[i]);
  qs(1,n);  
  int k=a[1],sum=1;
  printf("%d ",k);
  for(i=2;i<=n;i++)
  {
    if(a[i]==k)sum++;
    else
    {
      k=a[i];
      printf("%d\n%d ",sum,k);
      sum=1;
    }
  }
  printf("%d",sum);
  return 0;
}

