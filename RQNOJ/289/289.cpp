#include<cstdio>
#include<iostream>

bool h[12];
int a[12][12];
int ti[12]= {0,1,1,1,4,4,4,7,7,7};
int tii[12]={0,3,3,3,6,6,6,9,9,9};
int tj[12]= {0,1,4,7,1,4,7,1,4,7};
int tjj[12]={0,3,6,9,3,6,9,3,6,9};

int main()
{
  //freopen("rqn289.in","r",stdin);
  //freopen("rqn289.out","w",stdout);
  int i,j,k;
  for(i=1;i<=9;i++)
    for(j=1;j<=9;j++)
      scanf("%d",&a[i][j]);
  
  for(k=1;k<=9;k++)
  {
    for(j=0;j<=10;j++)h[j]=false;
    for(i=ti[k];i<=tii[k];i++)
      for(j=tj[k];j<=tjj[k];j++)
      {
        if(!h[a[i][j]]){h[a[i][j]]=true;continue;}
        if(h[a[i][j]]){printf("0");exit(0);}
      }    
  }
  
  for(i=1;i<=9;i++)
  {
    for(j=0;j<=10;j++)h[j]=false;
    for(j=1;j<=9;j++)
    {
      if(!h[a[i][j]]){h[a[i][j]]=true;continue;}
      if(h[a[i][j]]){printf("0");exit(0);}
    }
  }
  for(i=1;i<=9;i++)
  {
    for(j=0;j<=10;j++)h[j]=false;
    for(j=1;j<=9;j++)
    {
      if(!h[a[j][i]]){h[a[j][i]]=true;continue;}
      if(h[a[j][i]]){printf("0");exit(0);}
    }
  }
  printf("1");
  return 0;
}

