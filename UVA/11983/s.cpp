#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 30005;

#define lson(x) ((x)<<1)
#define rson(x) (((x)<<1)+1)
typedef long long ll;

int N, K, R;
vector<int> bins, arr;

struct Segment {
    int l, r, h, v;
    void set (int l, int r, int h, int v) {
        this->l = l;
        this->r = r;
        this->h = h;
        this->v = v;
    }
}seg[maxn*2];

struct Node {
    int l, r, add;
    int c[12];
    void set (int l, int r, int add) {
        this->l = l;
        this->r = r;
        this->add = add;
        memset(c, 0, sizeof(c));
    }
}node[maxn*24];

inline bool cmp (const Segment& a, const Segment& b) {
    return a.h < b.h;
}

inline int search (int v) {
    return lower_bound(bins.begin(), bins.end(), v) - bins.begin();
}

void pushup (int u) {
    memset(node[u].c, 0, sizeof(node[u].c));

    if (node[u].l == node[u].r) {
        int x = node[u].l;
        node[u].c[min(K, node[u].add)] = bins[x+1] - bins[x];
    } else {
        for (int i = 0; i <= K; i++) {
            int t = min(K, i + node[u].add);
            node[u].c[t] += node[lson(u)].c[i] + node[rson(u)].c[i];
        }
    }
}

void build_segTree (int u, int l, int r) {
    node[u].set(l, r, 0); 

    if (l == r) {
        pushup(u);
        return;
    }

    int mid = (l + r) / 2;
    build_segTree(lson(u), l, mid);
    build_segTree(rson(u), mid + 1, r);
    pushup(u);
}

void insert_segTree (int u, int l, int r, int v) {
    if (l <= node[u].l && node[u].r <= r) {
        node[u].add += v;
        pushup(u);
        return;
    }

    int mid = (node[u].l + node[u].r) / 2;
    if (l <= mid)
        insert_segTree(lson(u), l, r, v);
    if (r > mid)
        insert_segTree(rson(u), l, r, v);
    pushup(u);
}

int query_segTree (int u, int l, int r) {
    if (l <= node[u].l && node[u].r <= r)
        return node[u].c[K];

    int mid = (node[u].l + node[u].r) / 2;
    int ret = 0;
    if (l <= mid)
        ret += query_segTree(lson(u), l, r);
    if (r > mid)
        ret += query_segTree(rson(u), l, r);
    return ret;
}
void add_hash (int x) {
    if (x)
        arr.push_back(x-1);
    arr.push_back(x);
    arr.push_back(x+1);
}

void init () {
    int x1, y1, x2, y2;
    arr.clear();
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        seg[lson(i)].set(x1, x2, y1, 1);
        seg[rson(i)].set(x1, x2, y2+1, -1);

        add_hash(x1);
        add_hash(x2);
    }
    sort(arr.begin(), arr.end());

    bins.clear();
    bins.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[i-1])
            bins.push_back(arr[i]);
    }

    R = bins.size() - 2;

    build_segTree (1, 0, R);
}

ll solve () {
    sort(seg, seg + 2 * N, cmp);

    ll ret = 0;
    for (int i = 0; i < 2 * N - 1; i++) {
        insert_segTree(1, search(seg[i].l), search(seg[i].r), seg[i].v);
        ll tmp = query_segTree(1, 0, R);
        ret += tmp * (seg[i+1].h - seg[i].h);
    }
    return ret;
}

int main () {
    int cas;
    scanf("%d", &cas);
    for (int kcas = 1; kcas <= cas; kcas++) {
        init();
        printf("Case %d: %lld\n", kcas, solve());
    }
    return 0;
}
