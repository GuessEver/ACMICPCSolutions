#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define MAXN 50010
#define L(u) (u<<1)
#define R(u) (u<<1|1)

//写在类里面爆栈
int n, m, q;
int tim;       //时间戳
int num[MAXN]; //树上每个节点的初始值
int siz[MAXN]; //siz[u]表示以u为根的子树的节点数
int top[MAXN]; //树链上深度最小的点
int son[MAXN]; //重儿子
int dep[MAXN]; //深度
int tid[MAXN]; //节点的时间戳
int _tid[MAXN]; //tid[i]=j表示时间戳为i的节点是j
int father[MAXN]; //父节点
bool vis[MAXN];
vector<int> edge[MAXN];

void init(int n)
{
    for(int i = 1; i <= n; i++)
    {
        siz[i] = top[i] = son[i] = 0;
        dep[i] = tid[i] = _tid[i] = father[i] = 0;
        vis[i] = false;
        tim = 0; //时间戳
        edge[i].clear();
    }
}

void addedge(int u, int v) //无根树加双向边
{
    edge[u].push_back(v);
    edge[v].push_back(u);
}

//树链剖分
void dfs1(int u, int pre)
{
    vis[u] = true;
    siz[u] = 1;
    father[u] = pre;
    dep[u] = dep[pre] + 1; //注意根节点比较特殊
    int sz = edge[u].size();
    for(int i = 0; i < sz; i++)
    {
        int v = edge[u][i];
        if(v != father[u] && vis[v] == false)
        {
            dfs1(v, u);
            siz[u] += siz[v];
            if(son[u] == 0) son[u] = v;
            else if(siz[son[u]] < siz[v]) son[u] = v;
        }
    }
}

void dfs2(int u, int tp)
{
    vis[u] = true;
    tid[u] = ++tim;
    _tid[tim] = u;
    top[u] = tp;
    if(son[u] != 0)
        dfs2(son[u], tp); //同一条重链的顶部相同

    int sz = edge[u].size();
    for(int i = 0; i < sz; i++)
    {
        int v = edge[u][i];
        if(v != father[u] && v != son[u] && vis[v] == false) //注意去掉重儿子
            dfs2(v, v);
    }
}

void update(int u, int l, int r, int v); //线段树的更新函数

void change(int x, int y, int val)
{
    while(top[x] != top[y])
    {
        if(dep[top[x]] < dep[top[y]])
            swap(x, y);
        update(1, tid[top[x]], tid[x], val); //dfs2时顶部先访问，故tid[top]较小
        x = father[top[x]]; //因为top[x]->x路径上的所有点已经被更新了
    }

    if(dep[x] > dep[y]) //同一条重链上深度小的tid小
        swap(x, y);
    update(1, tid[x], tid[y], val);
}


//线段树部分
struct NODE {
    int l, r, val, lazy;
}node[MAXN*4];

void build(int u, int l, int r)
{
    node[u].l = l;
    node[u].r = r;
    node[u].lazy = node[u].val = 0;
    if(l == r)
    {
        node[u].val = num[_tid[l]];
        return;
    }

    int mid = (l + r) >> 1;
    build(L(u), l, mid);
    build(R(u), mid + 1, r);
}

void pushdown(int u)
{
    if(node[u].lazy != 0)
    {
        node[L(u)].val += node[u].lazy;
        node[R(u)].val += node[u].lazy;
        node[L(u)].lazy += node[u].lazy;
        node[R(u)].lazy += node[u].lazy;
        node[u].lazy = 0;
    }
}

void update(int u, int l, int r, int v)
{
    if(node[u].l == l && node[u].r == r)
    {
        node[u].val += v;
        node[u].lazy += v;
        return;
    }

    pushdown(u);
    int mid = (node[u].l + node[u].r) >> 1;
    if(r <= mid)
        update(L(u), l, r, v);
    else if(l > mid)
        update(R(u), l, r, v);
    else
    {
        update(L(u), l, mid, v);
        update(R(u), mid + 1, r, v);
    }
}

int query(int u, int x)
{
    if(node[u].l == x && node[u].r == x)
        return node[u].val;

    pushdown(u);
    int mid = (node[u].l + node[u].r) >> 1;
    if(x <= mid) return query(L(u), x);
    else return query(R(u), x);
}


int main()
{
    char oper[2];
    int a, b, c;
    while(scanf("%d%d%d",&n,&m,&q) != EOF)
    {
        init(n);

        for(int i = 1; i <= n; i++)
            scanf("%d", &num[i]);

        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d",&a, &b);
            addedge(a, b);
        }

        dfs1(1, 0);
        memset(vis, 0, sizeof(vis));
        dfs2(1, 1);
        build(1, 1, n);

        while(q--)
        {
            scanf("%s", oper);
            if(oper[0] == 'Q')
            {
                scanf("%d", &a);
                printf("%d\n", query(1, tid[a]));
            }
            else
            {
                scanf("%d%d%d", &a, &b, &c);
                if(oper[0] == 'I')
                    change(a, b, c);
                else
                    change(a, b, -c);
            }
        }
    }
    return 0;
}

