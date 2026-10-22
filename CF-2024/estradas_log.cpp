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
const int MOD = 998244353;
int rp[MAXN], sz[MAXN], ans[MAXN], d[MAXN], cnt[MAXN];

int find(int u) {
    if (u == rp[u]) return u;
    return rp[u] = find(rp[u]);
}

void join(int u, int v, int x) {
    u=find(u); v=find(v);

    ans[v] += ans[u] + x*sz[u]*sz[v] + d[u]*sz[v] + d[v]*sz[u];
    d[v] += d[u] + x*(sz[u]);

    rp[u] = v;
    sz[v] += sz[u];
}

void solve() {
    int n,q; cin >> n >> q;
    rep(i,1,n) rp[i] = i, sz[i] = 1;

    vector<array<int,4>> qrs;
    rep(i,1,q) {
        int t; cin >> t;
        if(t==1) {
            int u,v,w; cin >> u >> v >> w;
            cnt[u]++;
            cnt[v]++;
            qrs.pb({t,u,v,w});
        } else {
            int c; cin >> c;
            qrs.pb({t,c,0,0});
        }
    }

    for (auto &[t,u,v,w] : qrs) {
        if(t==1) {
            cnt[u]--;
            cnt[v]--;
            if(cnt[v]==0) swap(u,v);
            join(u,v,w);
        } else {
            u = find(u);
            cout << ans[u] << '\n';
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    
    solve();
}
