/*
ID: jiangzh15
TASK: milk3
LANG: C++
*/
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

priority_queue<int,vector<int>,greater<int> > q;

int A,B,C;
bool h[30][30][30];

void dfs(int x,int y,int z)
{
    if(h[x][y][z])return;
    if(x==0) q.push(z);
    h[x][y][z]=true;
    //1->2
    if(x+y<=B) dfs(0,x+y,z);
    else if(x+y>B) dfs(x-(B-y),B,z);
    //1->3
    if(x+z<=C) dfs(0,y,x+z);
    else if(x+z>C) dfs(x-(C-z),y,C);
    //2->1
    if(x+y<=A) dfs(x+y,0,z);
    else if(x+y>A) dfs(A,y-(A-x),z);
    //2->3
    if(y+z<=C) dfs(x,0,y+z);
    else if(y+z>C) dfs(x,y-(C-z),C);
    //3->1
    if(z+x<=A) dfs(x+z,y,0);
    else if(z+x>A) dfs(A,y,z-(A-x));
    //3->2
    if(y+z<=B) dfs(x,y+z,0);
    else if(y+z>B) dfs(x,B,y-(B-z));
}

int main()
{
    freopen("milk3.in","r",stdin);
    freopen("milk3.out","w",stdout);
    scanf("%d%d%d",&A,&B,&C);
    dfs(0,0,C);
    while(q.size()>1){printf("%d ",q.top());q.pop();}
    printf("%d\n",q.top());
    return 0;
}
