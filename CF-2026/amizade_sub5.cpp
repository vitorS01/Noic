#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int MAXN = 5e5+10;
const int INF = 1e18+4;
const int MOD = 998244353;
int dir[MAXN];

void solve() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        int sz; cin >> sz;
        for (int j = 1; j <= sz; j++) {
            int x; cin >> x;
            if(dir[i]==0) dir[i] = x;
            else dir[i] = min(dir[i],x);
        } 
    }

    int ans = 0;
    stack<int> r_val;
    for (int l = n; l >= 1; l--) {
        if(dir[l]==0) {
            r_val.push(l);
        } else {
            while (r_val.size()>0 && r_val.top() < dir[l]) {
                r_val.pop();
            }
        }

        
        ans += r_val.size();
    }
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;

    while (tt--) solve();
}
