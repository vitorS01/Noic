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
int a[MAXN];

void solve() {
    int n; cin >> n;
    set<array<int,3>> st = {{1,n,0}};
    rep(i,1,n) cin >> a[i];

    int ans = 0;
    rep(i,1,n) {
        auto it = st.lower_bound({a[i]+1,0,0});
        it--;

        auto [l,r,cmp] = *it;
        st.erase(it);

        ans += cmp;
        if(a[i] != l) st.insert({l,a[i]-1, cmp+1});
        if(a[i] != r) st.insert({a[i]+1,r,cmp+1});
    }
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    
    solve();
}
