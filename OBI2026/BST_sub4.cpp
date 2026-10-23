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
    rep(i,1,n) cin >> a[i];

    int qtdcomp = 0;
    rep(i,1,n) {
        int l = 1, r = n;
        rep(j,1,i-1) {
            if(a[j] < l || a[j] > r) continue;
                qtdcomp++;

            if(a[i] > a[j]) {
                l = a[j];
            } else {
                r = a[j];
            }
        }
    }
    cout << qtdcomp << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    
    solve();
}
