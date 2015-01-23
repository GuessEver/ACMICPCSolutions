    #include <stdio.h>    
    #include <stdlib.h>    
    #define INF 100000000    
    struct Edge    
    {    
        int e, v;    
    } edge[150005];    
    int neg;    
    int node[30005];    
    int next[150005];    
    int n;    
    int dis[30005], vst[30005];    
    int Q[30005];    
    void add(int s, int e, int v)    
    {    
        edge[neg].e = e;    
        edge[neg].v = v;    
        next[neg] = node[s];    
        node[s] = neg++;    
    }    
    int relax(int s, int e, int v)    
    {    
        if (dis[s]+v < dis[e])    
        {    
            dis[e] = dis[s]+v;    
            return 1;    
        }    
        return 0;    
    }    
    /*  用栈来实现试试  */    
    int SPFA(int s0)    
    {    
        int i, t, p, top;    
        for (i=1; i<=n; i++)    
            dis[i] = INF;    
        dis[s0] = 0;    
        Q[0] = s0;    
        top = 1;    
        vst[s0] = 1;    
        while (top)    
        {    
            t = Q[--top];    
            p = node[t];    
            while (p != -1)    
            {    
                if (relax(t, edge[p].e, edge[p].v) && !vst[edge[p].e])    
                {    
                    Q[top++] = edge[p].e;    
                    vst[edge[p].e] = 1;    
                }    
                p = next[p];    
            }    
            vst[t] = 0;    
        }    
        return 1;    
    }    
    int main()    
    {    
        int m, k, a, b;    
        memset(node, -1, sizeof(node));    
        scanf("%d %d", &n, &m);    
        while (m--)    
        {    
            scanf("%d %d %d", &a, &b, &k);    
            add(a, b, k);    
        }    
        SPFA(1);    
        printf("%d/n", dis[n]);    
return 0;
    }  