#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<map>
using namespace std;

 

int h;            //队列指针
const string g="123804765";
priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > a;   //优先队列，小根堆
map <string,int> hash;     //哈希表
struct kk
{
       string x;
       int i,s;
       }line[200000];       //状态队列
const int w[4]={1,-1,3,-3}; 
      
int f(string now,int x)
{
    int ans=line[x].s;
    for (int i=0; i<9; i++)
        if (now[i]!=g[i]) ans++;
    return ans;
}            //估价函数，由从初始状态到当前状态的步数+当前与目标的不一致的点个数。

 

bool can(int i,int x)
{
     int j=line[x].i;
     if (j % 3==0 && w[i]==-1) return 0;
     if (j % 3==2 && w[i]==1) return 0;
     if (j<3 && w[i]==-3) return 0;
     if (j>5 && w[i]==3)  return 0;
    
     return 1;
 }   //判断是否出界，注意C的字符串下标从0开始。

 

int A_star()
{
    while (!a.empty())
    {
        int x=a.top().second;
        a.pop();
       
        for (int i=0; i<4; i++)
            if (can(i,x))
            {
                string now=line[x].x;
                int j=line[x].i;
                now[j]=now[j+w[i]];
                now[j+w[i]]='0';
               
                if (hash.find(now)==hash.end())
                {
                    h++;
                    hash.insert(make_pair(now,h));
                    line[h].x=now;
                    line[h].i=j+w[i];
                    line[h].s=line[x].s+1;
                    a.push(make_pair(f(now,h),h));
                                               }
                if (now==g)  return line[x].s+1;
                         }
          }
          return -1;
}            //A*启发式搜索。

 

int main()
{
    //freopen("eight.in","r",stdin);
    //freopen("eight.out","w",stdout);
    ios::sync_with_stdio(false);
    string now;
    cin>>now;
   
    line[h=0].x=now;  line[h].s=0;
    for (int i=0; i<now.length(); i++)
        if (now[i]=='0')
        {
            line[h].i=i;
            break;
                        }
    while (!a.empty()) a.pop();
    a.push(make_pair(f(now,h),h));
    hash.insert(make_pair(now,h));       //初始入队
   
    int ans=A_star();
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
return 0;
}
