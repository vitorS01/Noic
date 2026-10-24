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
 
const int MAXN = 5e5 + 10;
const int INF = 1e18 + 4;
const int MOD = 1e9 + 7;
vector<pii> g[MAXN];
int h[MAXN], dist[MAXN], mark[MAXN];

void solve() {
    int n,m,X,Y; cin >> n >> m >> X >> Y;
    rep(i,1,n) cin >> h[i];
    rep(i,1,m) {
        int u,v; cin >> u >> v;
        if(h[v]<h[u]) swap(u,v);

        g[u].pb({v,h[v]-h[u]});
        g[v].pb({u,0});
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,1});
    rep(i,1,n) dist[i] = INF;
    dist[0] = 0;

    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if(mark[u]) continue;
        mark[u] = 1;

        for (auto &[v,w] : g[u]) {
            if(dist[v] <= d + w) continue;
            dist[v] = d+w;
            pq.push({dist[v], v});
        }
    }

    int y = h[1]-h[n]+dist[n];
    cout << ((dist[n] <= X && y <= Y) ? "S\n" : "N\n"); 
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    
    solve();
}
