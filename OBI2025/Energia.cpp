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
 
const int MAXN = 2e5+10;
const int INF = 1e18+4;
const int MOD = 998244353;
int a[MAXN];

void solve() {
    int n,q,k; cin >> n >> q >> k;
    rep(i,1,n) cin >> a[i];

    map<int,vector<int>> m[2];
    // m[0] -> {ai + i} -> {i}
    // m[1] -> {i - ai} -> {i}

    rep(i,1,n) {
        m[0][i+a[i]].pb(i);
        m[1][i-a[i]].pb(i);
    }

    auto cnt_k = [&](int l, int r, int x, int k) -> int {
        if(r<l)return 0;
        auto it = m[k].find(x);
        if(it==m[k].end()) return 0;
        
        return upper_bound(all(it->se), r) - lower_bound(all(it->se),l);
    };

    int ans = 0;
    rep(i,2,n) {
        ans += cnt_k(max(1LL,i-k),i-1,i+a[i]-k,0);
        ans += cnt_k(max(1LL,i-k+1),i-1,i-a[i]-k,1);
    }
    cout << ans << '\n';

    set<int> mk={0,n+1};

    rep(_,1,q) {
        int pos; cin >> pos;

        int lrm = *prev(mk.lower_bound(pos))+1;
        int rrm = *mk.lower_bound(pos)-1;
        //[lrm,pos-1] pos [pos+1,rrm]

        if(pos-lrm-1<rrm-pos) {
            rep(i,lrm,pos) {
                int r = min(rrm,i+k-1);
                ans -= cnt_k(pos,min(rrm,r+1),i+a[i]+k,0);
                ans -= cnt_k(pos,r,i-a[i]+k,1);
            }
        } else {
            rep(i,pos,rrm) {
                int l = max(lrm,i-k+1);
                ans -= cnt_k(max(lrm,l-1),pos,i+a[i]-k,0);
                ans -= cnt_k(l,pos,i-a[i]-k,1);
            }
        }
        
        mk.insert(pos);
        cout << ans << '\n';
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;

    while (tt--) solve();
}
