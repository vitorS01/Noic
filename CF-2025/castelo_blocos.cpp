#include <bits/stdc++.h>
using namespace std;
 
//#define int long long
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,a,b) for (int i = a; i >= b; i--)
#define pii pair<int,int>
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
 
const int MAXN = 31;
const int INF = 1e9+4;
const int MOD = 998244353;
vector<int> g[MAXN];
int indeg[MAXN];

int dp[(1<<22)][2];

int dfs(int u, int mask) {
    int ans = (1<<u);

    for (int &v : g[u]) {
        if(!(mask>>v&1)) continue;

        if(--indeg[v]>0) continue;
        ans |= dfs(v,mask);
    }

    return ans;
}

void solve() {
    int n,m; cin >> n >> m;
    rep(i,1,m) {
        int u,v; cin >> u >> v;
        u--;
        v--;
        g[u].pb(v);
    }

    rep(mask,1,(1<<n)-1) {
        dp[mask][0] = INF;
        vector<int> basedeg(n);
        rep(j,0,n-1) if(mask>>j&1) for (int &v : g[j]) basedeg[v]++;

        rep(i,0,n-1) {
            if((mask>>i&1) == 0) continue;
            rep(i,0,n-1) indeg[i] = basedeg[i];

            int fd = dfs(i, mask); // os bits ligados em fd são quem desmorona
            int cnt = __builtin_popcount(fd); // quantidade de bits ligados

            int nmask = (~fd)&mask;

            dp[mask][0] = min(dp[nmask][1]+cnt-1, dp[mask][0]);
            dp[mask][1] = max(dp[nmask][0]+cnt-1, dp[mask][1]);
        }
    }

    cout << dp[(1<<n)-1][0] << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    
    solve();
}
