#include<cstdio>
#include<string>
using namespace std;
#define MAXN 900+10

int n,a[MAXN],num[MAXN];

void qs(int l,int r)
{
  int i=l,j=r,x=a[i+(j-i)/2],nnn=num[i+(j-i)/2];
  do 
  {
    while(a[i]<x || (a[i]==x && num[i]<nnn))i++;
    while(a[j]>x || (a[j]==x && num[j]>nnn))j--;
    if(i<=j)
    {
      swap(a[i],a[j]);
      swap(num[i],num[j]);
      i++;j--;
    }
  }
  while(i<=j);
  if(i<r)qs(i,r);
  if(l<j)qs(l,j);
}

int main()
{
  //freopen("rqn255.in","r",stdin);
  //freopen("rqn255.out","w",stdout);
  scanf("%d",&n);
  int i;
  for(i=1;i<=n;i++) {scanf("%d",&a[i]);num[i]=i;}
  qs(1,n);
  for(i=1;i<n;i++) printf("%d ",num[i]);
  printf("%d\n",num[n]);
  int j,total=0,sum;
  for(i=1;i<=n;i++)
  {
    sum=0;
    for(j=1;j<i;j++) sum+=a[j];//由于是等待时间 所以不加本身接水时间 
    total+=sum;
  }
  double totall;
  totall=total;
  printf("%.2lf",totall/n);
  return 0;
}

