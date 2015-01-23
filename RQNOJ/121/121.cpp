#include<cstdio>
#include<queue>
using namespace std;
#define oo 99999999
#define MAXN 100

int n,a[MAXN];
queue<int> q1,q2;

void qs(int l,int r)
{
  int i=l,j=r,x=a[i+(j-i)/2];
  do 
  {
    while(a[i]<x) i++;
    while(a[j]>x) j--;
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

int getmin()
{
  int x,y;
  if(q1.empty()){x=q2.front();q2.pop();return x;}
  if(q2.empty()){x=q1.front();q1.pop();return x;}
  x=q1.front();y=q2.front();
  if(x<=y){q1.pop();return x;}
  q2.pop();return y;
}

void issushu(int x)
{
  int i;
  for(i=2;i<x;i++)
    if(x%i==0)
    {
      printf("No\n");
      exit(0);
    }
  printf("Yes\n");
  exit(0);
}

int main()
{
  //freopen("rqn121.in","r",stdin);
  //freopen("rqn121.out","w",stdout);
  scanf("%d",&n);
  int i,min=oo;
  for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
  qs(1,n);
  for(i=1;i<=n;i++)q1.push(a[i]);
  int x,total=a[1];//摘取最小的耗费最小 
  for(i=1;i<n;i++)
  {
    x=getmin()+getmin();
    q2.push(x);
    total+=x;
  }
  printf("%d\n",total);
  issushu(total);
  return 0;
}

