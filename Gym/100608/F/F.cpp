#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using std::vector;
using std::queue;

const int N = 1000 + 10;

int n;
vector<int> path[N], g[N];
int fa[N], color[N];

void dfs(int x, int father)
{
    fa[x] = father;
    for(vector<int>::iterator it = path[x].begin(); it < path[x].end(); it++)
    {
        if(*it == father) continue;
        g[x].push_back(*it);
        dfs(*it, x);
    }
}

void COLOR(int x)
{
    bool vis[5] = {0};
    for(vector<int>::iterator it = path[x].begin(); it < path[x].end(); it++)
        vis[color[*it]] = 1;
    for(int i = 1; i <= 4; i++)
        if(!vis[i])
        {
            color[x] = i;
            printf("%d %d\n", x, i);
            fflush(stdout);
            break;
        }
}

queue<int> Q;
void BFS(int root)
{
    while(!Q.empty()) Q.pop();
    Q.push(root);
    while(!Q.empty())
    {
        int x = Q.front(); Q.pop();
        if(!color[x])
        {
            COLOR(x);
            return;
        }
        for(vector<int>::iterator it = g[x].begin(); it < g[x].end(); it++)
            Q.push(*it);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        int u, v; scanf("%d%d", &u, &v);
        path[u].push_back(v);
        path[v].push_back(u);
    }
    dfs(1, -1);
    printf("%d %d\n", 1, 1);
    fflush(stdout);
    color[1] = 1;
    while(1)
    {
        int x, c; scanf("%d%d", &x, &c);
        if(x == -1 && c == -1) break;
        color[x] = c;
        if(color[fa[x]]) BFS(1);
        else {
            COLOR(fa[x]);
        }
    }
    return 0;
}
