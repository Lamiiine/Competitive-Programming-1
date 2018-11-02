#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 2e5 + 5;
int head[N], nxt[N], to[N], ne = 0;
int par[N], vid = 0;
int nxtnode;
bool ans[N << 1];
 
struct node {
    int v, l, r;
};
 
node nodes[1 << 18];
 
void update(int ni, int ns, int ne, int idx) {
    if (idx < ns || idx > ne)
        return;
    node &n = nodes[ni];
    if (ns == ne) {
        n= {vid,0,0};
        return;
    }
    if (!n.l) {
        n.l = nxtnode;
        nodes[nxtnode++]= {0,0,0};
    }
    if (!n.r) {
        n.r = nxtnode;
        nodes[nxtnode++]= {0,0,0};
    }
 
    int mid = ns + (ne - ns) / 2;
    update(n.l, ns, mid, idx);
    update(n.r, mid + 1, ne, idx);
    n.v = vid;
}
 
bool query(int ni, int ns, int ne, int qs, int qe) {
    if (qe < ns || qs > ne)
        return 0;
    node &n = nodes[ni];
    if (ns >= qs && ne <= qe)
        return n.v == vid;
    int mid = ns + (ne - ns) / 2;
    return (query(n.l, ns, mid, qs, qe) || query(n.r, mid + 1, ne, qs, qe));
}
 
void addedge(int f, int t) {
    nxt[ne] = head[f];
    to[ne] = t;
    head[f] = ne++;
}
 
void addbiedge(int f, int t) {
    addedge(f, t);
    addedge(t, f);
}
 
int chainNo = 0, chainHead[N], chainPos[N], chainInd[N], chainSize[N];
int subsize[N], depth[N];
int l = 0;
int dfs(int i, int p = -1) {
    par[i] = p;
    depth[i] = l;
    subsize[i] = 1;
    for (int k = head[i]; ~k; k = nxt[k]) {
        if (to[k] == p)
            continue;
        ++l;
        subsize[i] += dfs(to[k], i);
        --l;
    }
    return subsize[i];
}
 
void hld(int cur, int p = -1) {
    if (chainHead[chainNo] == -1)
        chainHead[chainNo] = cur;
    chainInd[cur] = chainNo;
    chainPos[cur] = chainSize[chainNo];
    chainSize[chainNo]++;
 
    int ind = -1, mai = -1;
    for (int i = head[cur]; ~i; i = nxt[i]) {
        if (to[i] == p)
            continue;
        if (subsize[to[i]] > mai) {
            mai = subsize[to[i]];
            ind = to[i];
        }
    }
 
    if (ind >= 0)
        hld(ind, cur);
 
    for (int i = head[cur]; ~i; i = nxt[i]) {
        if (to[i] == p)
            continue;
        if (to[i] != ind) {
            chainNo++;
            hld(to[i], cur);
        }
    }
}
 
int lca(int a, int b) {
    while (chainInd[a] != chainInd[b]) {
        if (depth[chainHead[chainInd[a]]] < depth[chainHead[chainInd[b]]])
            b = par[chainHead[chainInd[b]]];
        else
            a = par[chainHead[chainInd[a]]];
    }
    if (depth[a] < depth[b])
        return a;
    return b;
}
 
bool get_path(int u, int v) {
    int chain = chainInd[u];
    if (chain == chainInd[v])
        return query(chain, 0, chainSize[chain] - 1, chainPos[v], chainPos[u]);
 
    int vv = chainHead[chain];
    if (query(chain, 0, chainSize[chain] - 1, chainPos[vv], chainPos[u]))
        return true;
    return get_path(par[vv], v);
}
 
void solve(int a, int b, int qid) {
    int l = lca(a, b);
    ans[qid] = get_path(a, l) || get_path(b, l);
}
 
void init() {
    memset(head, -1, n * sizeof(head[0]));
    memset(chainHead, -1, n * sizeof(chainHead[0]));
    memset(chainSize, 0, n * sizeof(chainSize[0]));
    ne = 0;
    chainNo = 1;
}
int val[N];
 
struct event {
    int v, t, nid, a, b, qid;
} events[N << 2];
 
int sorted[N << 2];
#ifndef ONLINE_JUDGE
#define getchar_unlocked getchar
#endif
void scanint(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    for (; (c < 48 || c > 57); c = getchar_unlocked())
        ;
    for (; c > 47 && c < 58; c = getchar_unlocked()) {
        x = (x << 1) + (x << 3) + c - 48;
    }
}
 
int main() {
    int q;
    while (~scanf("%d%d", &n, &q)) {
 
        int x;
        int es = 0;
        for (int i = 0; i < n; ++i) {
            scanint(x);
            event e = { x, 0, i, -1, -1, -1 };
            events[es++] = e;
 
        }
        init();
        int u, v;
        for (int i = 1; i < n; ++i) {
            scanint(u), scanint(v);
            addbiedge(--u, --v);
        }
        int c;
        for (int i = 0; i < q; ++i) {
            scanint(u), scanint(v), scanint(c);
            event e = { c, 1, -1, --u, --v, i };
            events[es++] = e;
        }
        dfs(0);
        hld(0);
        //for(int i = 0 ; i < n ; i++){
        //  printf("%d %d\n",i+1,chainInd[i]);
        //}
        nxtnode = ++chainNo;
        memset(nodes, 0, nxtnode * sizeof(nodes[0]));
        iota(sorted, sorted + es, 0);
        sort(sorted, sorted + es,
                [](int a,int b) {
                    return (make_pair(events[a].v,events[a].t)<make_pair(events[b].v,events[b].t));
                });
 
        int prev = -1;
        for (int i = 0; i < es; ++i) {
            event &e = events[sorted[i]];
            vid += (prev != e.v);
            prev = e.v;
 
            if (e.t) {
                solve(e.a, e.b, e.qid);
            } else {
                int v = e.nid;
                int chain = chainInd[v];
                update(chain, 0, chainSize[chain] - 1, chainPos[v]);
            }
        }
        for (int i = 0; i < q; ++i)
            if (ans[i])
                puts("Find");
            else
                puts("NotFind");
 
        puts("");
    }
}
