#include <iostream>
#include<cstdio>
#include <cstring>
#include<vector>
#include<queue>
using namespace std;
int m,n,h[4][2]={1,0,-1,0,0,1,0,-1},bz[55][55];
char map[55][55];
struct point
{
	int x,y,step;
}s,e;
vector<int> aa[28];
queue<point> my;
int BFS(point s)
{   int x,y,i,a,b;
    point t,tt;
	while(!my.empty()) my.pop();
	my.push(s);
	bz[s.x][s.y]=1;
	while(!my.empty())
    {
    	t=my.front();
    	my.pop();
    	for(i=0;i<4;i++)
    	{   x=t.x+h[i][0];y=t.y+h[i][1];
	    	if(x==e.x&&y==e.y) return t.step+1;
 	        if(x>=0&&x<m&&y>=0&&y<n&&bz[x][y]==0&&map[x][y]!='#')
 	        {   bz[x][y]=1;
 	          if(map[x][y]!='.') 
	    	   { 
 		        if(aa[map[x][y]-'a'][0]==x&&aa[map[x][y]-'a'][1]==y)
					 {tt.x=aa[map[x][y]-'a'][2]; tt.y=aa[map[x][y]-'a'][3];}
			    else {tt.x=aa[map[x][y]-'a'][0]; tt.y=aa[map[x][y]-'a'][1];}
				 tt.step=t.step+1;
   	    	   }
   	    	   else
        	    {tt.x=x; tt.y=y; tt.step=t.step+1;}
				my.push(tt);	
   	        }
	    }
    }
    return -1;
}
int main(void)
{
	freopen("1002.in","r",stdin);
	freopen("std.out","w",stdout);
   int t,i,j,k,x,y;
   point p;
   cin>>t;
   while(t--)
   { memset(bz,0,sizeof(bz));
   	  cin>>m>>n;
   	  for(i=0;i<m;i++)
   	  for(j=0;j<n;j++)
   	    {cin>>map[i][j];
   	       if(map[i][j]>='a'&&map[i][j]<='z')
           { 
		   aa[map[i][j]-'a'].push_back(i);
		   aa[map[i][j]-'a'].push_back(j);
   		   }
		   if(map[i][j]=='L') { s.x=i; s.y=j; s.step=0; }
		   if(map[i][j]=='Q') { e.x=i; e.y=j; e.step=0; }
   	    }
   	    cout<<BFS(s)<<endl;
   	    for(i=0;i<28;i++) aa[i].clear();    
   } 
}


