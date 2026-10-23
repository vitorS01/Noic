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
int a[MAXN], pfx[MAXN], mx[MAXN];

void solve() {
    int n; cin >> n;
    rep(i,1,n) cin >> a[i];

    rep(i,1,n) {
        mx[i] = max(mx[i-1],a[i]);
        pfx[i] = pfx[i-1];
        if(a[i]==mx[i]) pfx[i]++;
    }

    int qtdcomp = 0;
    rep(i,1,n) {
        if (i >= 20) qtdcomp += pfx[i-20];
        int j = max(0LL, i-20);

        int l = mx[j], r = n;
        while (j < i-1) {
            j++;
            if(a[j] < l || a[j] > r) continue;
            qtdcomp++;

            if(a[j] > a[i]) {
                r=a[j];
            }
            else {
                l=a[j];
            }
        }
    }
    cout << qtdcomp << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    
    solve();
}
