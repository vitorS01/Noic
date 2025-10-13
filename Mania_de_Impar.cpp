#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define per(i,a,b) for (int i = a; i >= b; --i)
#define pb push_back

const int MAXN = 2e5 + 10;
int a[101][101];

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int n,m;cin >> n >> m;
    rep(i,1,n) rep(j,1,m) cin >> a[i][j];

    int cur1 = 0;
    rep(i,1,n) {
        rep(j,1,m) {
            if (((m*i + j) %2) == (a[i][j]%2)) cur1++;
        }
    }

    if (2*cur1 < n*m) {
        cout << cur1 << '\n';
        rep(i,1,n) rep(j,1,m) cout << a[i][j] + (((m*i + j) %2) == (a[i][j]%2)) << " \n"[j==m];
    } else {
        cout << n*m-cur1 << '\n';
        rep(i,1,n) rep(j,1,m) cout << a[i][j] + (((m*i + j) %2) != (a[i][j]%2)) << " \n"[j==m];
    }
}
