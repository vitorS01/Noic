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
 
const int MAXN = 1e3+10;
const int INF = 1e18+4;
const int MOD = 998244353;
pii id[MAXN*MAXN];
int mk[MAXN*MAXN], a[MAXN][MAXN], pfx[MAXN][MAXN];

void solve() {
    int n,m,q; cin >> n >> m;
    rep(i,1,n) rep(j,1,m) cin >> a[i][j];
    cin >> q;

    //
    rep(i,1,n) rep(j,1,m) {
        pfx[i][j] = pfx[i-1][j] + pfx[i][j-1] - pfx[i-1][j-1];
        if(mk[a[i][j]]) continue;

        mk[a[i][j]]=1;
        id[a[i][j]]={i,j};
        pfx[i][j]++;
    }
    rep(i,1,n) rep(j,1,m) mk[a[i][j]] = 0;

    while (q--) {
        int r1,c1,r2,c2; cin >> r1 >> c1 >> r2 >> c2;
        int ans = pfx[r2][c2]-pfx[r1-1][c2]-pfx[r2][c1-1]+pfx[r1-1][c1-1];

        rep(k,c1,c2) {
            for (auto &i : {r1,r2}) {
                int val = a[i][k];
                if(mk[val]) continue;
                mk[val] = 1;

                auto [x,y] = id[val];
                if(x<r1 || x > r2 || y < c1 || y > c2) ans++;
            }
        }
        rep(k,r1,r2) {
            for (auto &j : {c1,c2}) {
                int val = a[k][j];
                if(mk[val]) continue;
                mk[val] = 1;

                auto [x,y] = id[val];
                if(x<r1 || x > r2 || y < c1 || y > c2) ans++;
            }
        }
        rep(k,c1,c2) {
            for (auto &i : {r1,r2}) {
                mk[a[i][k]]=0;
            }
        }
        rep(k,r1,r2) {
            for (auto &j : {c1,c2}) {
                mk[a[k][j]]=0;
            }
        }

        cout << ans << '\n';
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;

    while (tt--) solve();
}
