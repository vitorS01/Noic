#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int MAXN = 5e5+10;
const int INF = 1e18+4;
const int MOD = 998244353;
int esq[MAXN], dir[MAXN];

void solve() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        int sz; cin >> sz;
        for (int j = 1; j <= sz; j++) {
            int x; cin >> x;
            if (x<i) esq[i] = max(esq[i], x);
            if(x>i) {
                if(dir[i]==0) dir[i] = x;
                else dir[i] = min(dir[i],x);
            }
        } 
    }

    int ans = 0;
    for (int l = 1; l<=n; l++) {
        int cnt = 0;
        vector<int> acc(n+1,0); // quantos caras que são amigos de i vão ficar validos 

        for (int r = l; r<=n; r++) {
            if(esq[r] >= l || (!esq[r] && !dir[r])) cnt++;
            else if(dir[r]) acc[dir[r]]++;

            cnt += acc[r];
            if(cnt==r-l+1) ans++;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;

    while (tt--) solve();
}
