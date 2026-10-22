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
int dp[MAXN];

void solve() {
    int n; cin >> n;

    dp[0] = 1;
    rep(i,1,n) {
        dp[i] = (dp[i] + dp[i-1])%MOD;
        if(i >= 2) dp[i] = (dp[i] + 2*dp[i-2])%MOD;
        if(i >= 3) dp[i] = (dp[i] + 2*dp[i-3]) %MOD;
    }
    cout << dp[n] << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    
    solve();
}
