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
 
const int MAXN = 1e2 + 10;
const int INF = 1e18 + 4;
const int MOD = 1e9 + 7;
vector<array<int,3>> g[MAXN][MAXN][MAXN];
int a[MAXN], mk[MAXN][MAXN][MAXN];

void dfs(int u, int x, int y) {
    if(mk[u][x][y]) return;
    mk[u][x][y] = 1;
    for (auto &[v,xi,yi] : g[u][x][y]) dfs(v,xi,yi); 
}

void solve() {
    int n,m, X, Y; cin >> n >> m >> X >> Y;
    rep(i,1,n) cin >> a[i];
    rep(i,1,m) {
        int u,v; cin >> u >> v;
        if(a[v]<a[u]) swap(u,v);
        rep(x,0,X) rep(y,0,Y) {
            if(x+a[v]-a[u] <= X) g[u][x][y].pb({v,x+a[v]-a[u],y});
            if(y+a[u]-a[v] <= Y) g[v][x][y+a[u]-a[v]].pb({u,x,y});
        }
    }

    dfs(1,0,0);
    bool ok = 0;
    rep(x,0,X) rep(y,0,Y) ok |= mk[n][x][y];
    cout << (ok?"S\n":"N\n");
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    
    solve();
}
