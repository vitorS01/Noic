#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 5e5+10;
const int INF = 1e18+4;
const int MOD = 998244353;
int a[MAXN],n,k,m;

bool check(int x) {
    int cnt = 0, gps = 0;
    for(int i = 1; i <= n; i++) {
        // conseguimos vencer ela
        if(a[i]<x) cnt++;
        // ja temos m vitorias no grupo podemos começar outro
        if(cnt==m) {
            gps++;
            cnt=0;
        }
    }
    return gps>=k;
}

void solve() {
    cin >> n >> k >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    int lo = 1, hi = 1e5+1, res=-1;

    while (lo<=hi) {
        int mid = (lo+hi)>>1;

        // se for possivel com mid guardamos possivel resposta e tentamos com menos agora
        if(check(mid)) {
            res = mid;
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }
    cout << res << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;

    while (tt--) solve();
}
