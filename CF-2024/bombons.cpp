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
const int MOD = 998244353;
int a[MAXN][MAXN], dist[MAXN][MAXN], mark[MAXN][MAXN];

void solve() {
    int n,m,d; cin >> n >> m >> d;
    rep(i,1,n) rep(j,1,m) cin >> a[i][j];
    rep(i,1,n) rep(j,1,m) dist[i][j] = INF;

    priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> pq;

    pii st; 
    cin >> st.fi >> st.se;

    pq.push({0,st.fi,st.se});
    dist[st.fi][st.se] = 0;

  //função que retorna uma lista dos vizinhos válidos de (i,j)
    auto get_ngh = [&](int i, int j) -> vector<pii> {
        vector<pii> cur = {{i+1,j},{i-1,j},{i,j+1},{i,j-1}};
        vector<pii> ans;
        for (auto &[x,y] : cur) {
            if(x>0 && x <=n && y > 0 && y <= m && a[x][y] != -1) ans.pb({x,y});
        }
        return ans;
    };

    while(!pq.empty()) {
        auto [d,i,j] = pq.top(); pq.pop();
        if(mark[i][j]) continue;
        mark[i][j] = 1;

        for (auto &[x,y] : get_ngh(i,j)) {
            if(dist[x][y] <= d + a[i][j]) continue;
            dist[x][y] = d+a[i][j];
            pq.push({dist[x][y], x, y});
        }
    }

    pii tg; 
    cin >> tg.fi >> tg.se;
    cout << d/dist[tg.fi][tg.se] << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    
    solve();
}
