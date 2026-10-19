#include <bits/stdc++.h>
#include <cassert>
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
pii ans[MAXQ];

// DQ codada na mão pra otimizar memória
struct DQ {
    vector<int> front, back;
    int szf = 0, szb = 0;

    void push_back(int x) {
        back.pb(x);
        szb++;
    }

    void push_front(int x) {
        front.pb(x);
        szf++;
    }

    int& operator[](int i) {
        assert(szf+szb>i);
        if(i<szf) return front[szf-i-1]; 
        else return back[i-szf];
    }

    int size() {
        return szf+szb;
    }

    void clear() {
        szf = szb = 0;
        back.clear();
        front.clear();
    }

    void shrink() {
        back.shrink_to_fit();
        front.shrink_to_fit();
    }
};

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


    vector<array<int, 3>> range(n+1); // {r, tam, min}
    vector<pair<pii, DQ>> sts(n+1); // {{res atual}, {contagem dos elementos}}
    rep(i,1,n) {
        range[i] = {i, 1, a[i]};
        sts[i].fi = {-1,a[i]};
        sts[i].se.pb(1);
    }


    for (auto &[l,r,id] : qrs) {
        while(1) {
            if(range[l][0] == r) break;
            int l1 = l;
            int l2 = range[l][0]+1;

            auto it = &range[l];
            auto it2 = &range[l2];

          //Sempre itere do conjunto menor (small-to-large)
            if((*it)[1] > (*it2)[1]) {
                swap(it,it2);
                swap(l1,l2);
            }

            auto [r1,sz1,mn1] = *it;
            auto [r2,sz2,mn2] = *it2;
            range[l] = {max(r1,r2), sz1+sz2, min(mn1,mn2)};

            auto &[cans1, val1] = sts[l1];
            auto &[cans2, val2] = sts[l2];

            cans2 = min(cans2, cans1);
            vector<int> tmp(sz1,0);
            rep(i,l1,r1) {
                //atualiza as contagens
                if(a[i] < mn2) {
                    tmp[a[i]-mn1]++;
                } else{
                    int ni = a[i]-mn2;

                    while(val2.size() <= ni) val2.pb(0);

                    val2[ni]++;
                    cans2 = min(cans2, {-val2[ni],a[i]});
                }
            }
            per(i,mn2-mn1-1,0) {
                val2.push_front(tmp[i]);
            }
            val1.clear();
            val1.shrink();

            if(l1 < l2) {
                swap(val1,val2);
                swap(cans1,cans2);
            }
        }

        ans[id] = {sts[l].fi.se, -sts[l].fi.fi};
    }
    rep(i,1,q) cout << ans[i].fi << ' ' << ans[i].se << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    
    solve();
}
