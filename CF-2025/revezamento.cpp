#include <bits/stdc++.h>
#include <cassert>
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
const int MOD = 998244353;
vector<array<int,4>> A[2];

int find_min(vector<vector<int>> &a) {
    int mn[2] = {INF,INF}, mn2[2]={INF,INF};

    pii mng = {INF,INF};

    int n = a.size();
    rep(i,0,n-1) {
        rep(j,0,1) {
            if(mn[j] > a[i][j]) {
                swap(mn[j],mn2[j]);
                mn[j] = a[i][j];
            }
            else if (mn2[j] > a[i][j]) mn2[j] = a[i][j];
        }
        mng = min(mng, {a[i][0], a[i][1]});
    }

    if((pii){mn[0],mn[1]} == mng) return min(mn[0]+mn2[1], mn[1]+mn2[0]);
    
    return mn[0]+mn[1];
}

void solve() {
    int n; cin >> n;
    rep(i,1,n) {
        int g,a,b,c,d; cin >> g >> a >> b >> c >> d;
        A[g].pb({a,b,c,d});
    }

    if(A[0].size() <2 || A[1].size()<2) {
        cout << "-1\n";
        return;
    }

    int ans = INF;
    vector<int> div = {0,0,1,1};

    do {
        int csum = 0;
        rep(g,0,1) {
            vector<vector<int>> a; // vetor de pares de modalidade pro genero atual

            int num_g = A[g].size();
            rep(i,0,num_g-1) {
                vector<int> prs; // 2 valores vão para esse vetor
                rep(j,0,3) if(div[j] == g) {
                    prs.pb(A[g][i][j]);
                }
                a.pb(prs);
            }
            csum += find_min(a);
        }
        ans = min(ans, csum);
    } while(next_permutation(all(div)));

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    
    solve();
}
