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
int dp[MAXN][2];

void solve() {
    int n; cin >> n;

    rep(i,1,n) {
        dp[i][0] = (dp[i][0] + dp[i-1][1] +1)%MOD;
        dp[i][1] = (dp[i][1] + 2*dp[i-1][0] + i+2)%MOD;
    }
    cout << dp[n][0] << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    
    solve();
}
