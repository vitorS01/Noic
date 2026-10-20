#include <bits/stdc++.h>
using namespace std;
 
//#define int long long
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,a,b) for (int i = a; i >= b; i--)
#define pii pair<int,int>
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
 
const int MAXN = 6e5 + 10;
const int MAXQ = 6e5 + 10;
//const int INF = 1e18 + 4;
const int MOD = 998244353;
int a[MAXN];
pii ans[MAXN];

void solve() {
    int n,q; cin >> n >> q;
    rep(i,1,n) cin >> a[i];

    vector<array<int,3>> qrs;
    rep(i,1,q) {
        int l,r; cin >> l >> r;
        qrs.pb({l,r,i});
    }
    sort(all(qrs), [&](const array<int,3> x, const array<int,3> y) {
        return x[1]-x[0] < y[1]-y[0];
    });


    set<array<int, 3>> ranges;
    vector<pair<set<pii>, set<pii>>> sts(n+1);
    rep(i,1,n) {
        ranges.insert({i, i, 1});
        sts[i].fi.insert({-1,a[i]});
        sts[i].se.insert({a[i],1});
    }

    auto range_has = [&](set<pii>& st, int val) -> bool {
        auto it = st.lower_bound({val,-1});
        if(it==st.end() || it->fi != val) return 0;
        return 1;
    };

    for (auto &[l,r,id] : qrs) {
        while(1) {
            auto it = ranges.lower_bound({l,0});

            if ((*it)[1] == r) break;

            auto it2 = it;
            it2++;

            if(sts[(*it)[0]].fi.size()>sts[(*it2)[0]].fi.size()) swap(it,it2);

            auto [l1,r1,sz1] = *it;
            auto [l2,r2,sz2] = *it2;
            ranges.erase(it);
            ranges.erase(it2);
            ranges.insert({min(l1,l2), max(r1,r2), sz1+sz2});

            auto &[inv1, val1] = sts[l1];
            auto &[inv2, val2] = sts[l2];

            for (auto &[val,cnt] : val1) {
                int ctemp = cnt;
                if (range_has(val2, val)) {
                    int cnt2 = val2.lower_bound({val,-1})->se;
                    
                    val2.erase({val,cnt2});
                    inv2.erase({-cnt2,val});
                    ctemp += cnt2;
                } 
                val2.insert({val,ctemp});
                inv2.insert({-ctemp,val});

            }
            val1.clear();
            inv1.clear();

            if(l1 < l2) {
                swap(val1,val2);
                swap(inv1,inv2);
            }
        }

        auto &inv = sts[l].fi;
        ans[id] = {inv.begin()->se, -inv.begin()->fi};
    }
    rep(i,1,q) cout << ans[i].fi << ' ' << ans[i].se << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    
    solve();
}
