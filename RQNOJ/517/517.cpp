#include<cstdio>
#include<string>
using namespace std;
#define MAXN 5000+10

int n,m,a[MAXN][3];

void qs(int l,int r)
{
  int i=l,j=r,x=a[i+(j-i)/2][2],y=a[i+(j-i)/2][1];
  do 
  {
    while(a[i][2]>x ||(a[i][2]==x && a[i][1]<y))i++;
    while(a[j][2]<x ||(a[j][2]==x && a[j][1]>y))j--;
    if(i<=j)
    {
      swap(a[i][2],a[j][2]);
      swap(a[i][1],a[j][1]);
      i++;j--;
    }
  }
  while(i<=j);
  if(i<r)qs(i,r);
  if(l<j)qs(l,j);
}

int main()
{
  //freopen("rqn517.in","r",stdin);
  //freopen("rqn517.out","w",stdout);
  scanf("%d%d",&n,&m);
  m=int(m*1.5);
  int i;
  for(i=1;i<=n;i++) scanf("%d%d",&a[i][1],&a[i][2]);
  qs(1,n);
  int k=m;
  while(a[k][2]==a[m][2]) k++;
  k--;
  printf("%d %d\n",a[m][2],k);
  for(i=1;i<=k;i++) printf("%d %d\n",a[i][1],a[i][2]);
  return 0;
}

