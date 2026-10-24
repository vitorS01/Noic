#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,a,b) for (int i = a; i >= b; i--)
#define pii pair<int,int>
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
 
const int MAXN = 1e3 + 10;
const int INF = 1e18 + 4;
const int MOD = 1e9 + 7;
vector<array<int,3>> g[MAXN][MAXN];
int a[MAXN], mark[MAXN][MAXN], dist[MAXN][MAXN];

void solve() {
    int n,m, X, Y; cin >> n >> m >> X >> Y;
    rep(i,1,n) cin >> a[i];
    rep(i,1,m) {
        int u,v; cin >> u >> v;
        if(a[v]<a[u]) swap(u,v);
        rep(x,0,X) {
            if(x+a[v]-a[u] <= X) g[u][x].pb({v,x+a[v]-a[u],0});
            g[v][x].pb({u,x,a[v]-a[u]});
        }
    }

    using trio = array<int,3>;
    priority_queue<trio, vector<trio>, greater<trio>> pq;

    pq.push({0,1,0});
    rep(i,1,n) rep(x,0,X) dist[i][x] = INF;
    dist[1][0] = 0;

    while(!pq.empty()) {
        auto [cw,u,x] = pq.top();pq.pop();
        if(mark[u][x]) continue;
        mark[u][x] = 1;

        for (auto &[v,xv,w] : g[u][x]) {
            if(dist[v][xv] <= cw+w) continue;
            dist[v][xv] = cw+w;
            pq.push({cw+w, v,xv});
        }
    }

    bool ok = 0;
    rep(x,0,X) if(dist[n][x] <= Y) ok = 1;
    cout << (ok?"S\n":"N\n");
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    
    solve();
}
