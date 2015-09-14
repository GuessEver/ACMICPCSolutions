#include <cstdio>
#include <algorithm>
#define MAXN 20000
#define MAXQ 5000
#define MAXM 100000

using namespace std;

struct node {
    int u, v, w;
    bool operator < (const node &x) const {
        return w < x.w;
    }
} edge[MAXM+5];

struct query {
    int q, id;
    bool operator < (const query & x) const {
        return q < x.q;
    }
} x[MAXQ+5];

int father[MAXN+5], Rank[MAXN+5];
int size[MAXN+5];
int ans[MAXQ+5];

inline int find(int x) {
    if (x != father[x]) {
        father[x] = find(father[x]);
    }
    return father[x];
}

int Ans = 0;

inline int c(int n) {
    return n*(n-1);
}

inline void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (Rank[x] > Rank[y]) {
        father[y] = x;
        Ans = Ans-c(size[x])-c(size[y])+c(size[x]+size[y]);
        size[x] += size[y];
    } else {
        if (Rank[x] == Rank[y]) {
            Rank[y]++;
        }
        father[x] = y;
        Ans = Ans-c(size[x])-c(size[y])+c(size[x]+size[y]);
        size[y] += size[x];
    }
}

int main() {
    int T;
    int limit, m, n, q;
    int edge_pt;
    scanf("%d", &T);
    while (T--) {
        edge_pt = 0;
        Ans = 0;
        scanf("%d%d%d", &n, &m, &q);
        for (int i = 1; i <= n; i++) {
            father[i] = i;
            Rank[i] = 0;
            size[i] = 1;
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
        }
        for (int i = 0; i < q; ++i) {
            scanf("%d", &x[i].q);
            x[i].id = i;
        }
        sort(edge, edge+m);
        sort(x, x+q);
        for (int i = 0; i < q; i++) {
            limit = x[i].q;
            while (edge_pt < m && edge[edge_pt].w <= limit) {
                Union(edge[edge_pt].u, edge[edge_pt].v);
                edge_pt++;
            }
            ans[x[i].id] = Ans;
        }
        for (int i = 0; i < q; i++) {
            printf("%d\n", ans[i]);
        }
    }

    return 0;
}
