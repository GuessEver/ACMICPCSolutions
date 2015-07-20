#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;
const int NUM = 200000 + 10;
typedef long long LL;
int n, m;
vector<int> vt[NUM];
map<LL, int> mp;
int ans[NUM];
int main()
{
    freopen("intouch.in", "r", stdin);
    freopen("intouch.out", "w", stdout);
    scanf("%d%d", &n, &m);
    int i, j, u, v;
    char s[3];
    LL N = n + 10;
    for(int i = 1; i <= m; i++)
    {
        scanf("%s", s);
        if(s[0] == '!')
        {
            scanf("%d", &u);
            vt[u].push_back(i);
        }
        else if(s[0] == '+')
        {
            scanf("%d%d", &u, &v);
            if(u > v) swap(u, v);
            mp[u*N + v] = i;
        }
        else if(s[0] == '-')
        {
            scanf("%d%d", &u, &v);
            if(u > v) swap(u, v);
            j = mp[u*N + v];
            mp.erase(u*N + v);
            ans[u] += vt[v].end() - lower_bound(vt[v].begin(), vt[v].end(), j);
            ans[v] += vt[u].end() - lower_bound(vt[u].begin(), vt[u].end(), j);
        }
    }
    for(map<LL,int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        u = (it->first)/N, v = (it->first)%N;
        j = it->second;
        ans[u] += vt[v].end() - lower_bound(vt[v].begin(), vt[v].end(), j);
        ans[v] += vt[u].end() - lower_bound(vt[u].begin(), vt[u].end(), j);
    }
    for(i = 1; i <= n; i++)
        printf("%d%c", ans[i], i == n ? '\n' : ' ');
   return 0;
} 
            
