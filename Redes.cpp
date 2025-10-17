#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+10;
int cnt[MAXN];

int main() {
    int n, N=0;cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;cin >> x;
        cnt[x]++;
        N=max(N,x);
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        ans += cnt[i]/2;
    }
    cout << ans << '\n';
    return 0;
}
