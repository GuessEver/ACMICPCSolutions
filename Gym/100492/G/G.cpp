#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
using std::queue;
using std::stack;

const int N = 500 + 10;

int n, m, c;
struct Link{ int y, z, idx; Link *next; }*head[N];
int dist[N], pre[N], ans[N];
bool inQ[N];
queue<int> Q;
stack<int> st;

void inLink(int x, int y, int z, int idx)
{
    Link *p = new Link;
    p -> y = y; p -> z = z;
    p -> next = head[x];
    p -> idx = idx;
    head[x] = p;
}

void spfa()
{
    memset(inQ, 0, sizeof(inQ));
    memset(dist, 0x3f, sizeof(dist));
    memset(pre, -1, sizeof(pre));
    dist[1] = 0; Q.push(1); inQ[1] = 1;
    while(!Q.empty())
    {
        int x = Q.front(); Q.pop(); inQ[x] = 0;
        for(Link *p = head[x]; p; p = p->next)
            if(dist[p->y] > dist[x] + p->z)
            {
                dist[p->y] = dist[x] + p->z;
                pre[p->y] = x;
                ans[p->y] = p -> idx;
                if(!inQ[p->y])
                {
                    Q.push(p->y);
                    inQ[p->y] = 1;
                }
            }
    }
}

int main()
{
    freopen("gas.in", "r", stdin);
    freopen("gas.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &c);
    for(int i = 1; i <= m; i++)
    {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        inLink(x, y, z, i);
        inLink(y, x, z, i);
    }
    spfa();
    if(dist[n] < c)
    {
        puts("Unfair");
        for(int i = n; pre[i] != -1; i = pre[i])
            st.push(ans[i]);
        printf("%d\n", (int)st.size());
        while(!st.empty())
        {
            printf("%d", st.top());
            st.pop();
            if(st.empty()) putchar('\n'); else putchar(' ');
        }
    }
    else puts("Fair");
    return 0;
}
