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
int a[MAXN], L[MAXN], R[MAXN];

void solve() {
    int n; cin >> n;

    // L[i] = valor do filho da esquerda
    // R[i] = valor do filho da direita
    // -1 caso algum filho esteja vazio
    rep(i,1,n) L[i] = R[i] = -1;
    rep(i,1,n) cin >> a[i];

    int qtdcomp = 0;
    rep(i,2,n) {
        int tmp = a[1];
        while(1) {
            qtdcomp++;
            if(a[i] > tmp) {
                if(R[tmp] == -1) {
                    R[tmp] = a[i];
                    break;
                }
                tmp = R[tmp];
            } else {
                if (L[tmp] == -1) {
                    L[tmp] = a[i];
                    break;
                }
                tmp = L[tmp];
            }
        }
        
    }
    cout << qtdcomp << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    
    solve();
}
