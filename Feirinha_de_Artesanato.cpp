#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

using pii = pair<int,int>;

const int MAXN = 1e5+10;
pii a[MAXN]; //{preco,tipo}
vector<int> p[3];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].se;
    for (int i = 1; i <= n; i++) cin >> a[i].fi;
    sort(a+1,a+n+1,greater<pii>()); // ordem decrescente

    for(int i = 1; i <= n; i++) p[a[i].se].push_back(a[i].fi);

    int c, s = 0;cin >> c;
    for (int i = 1; i <= c; i++) {
        int x; cin >> x;

        if(x>0 && !p[x].empty()) {
            s+=p[x].back();
            p[x].pop_back();
        } else if (x==0) {
            if(p[1].empty() && p[2].empty()) continue;

            if(!p[1].empty() && (p[2].empty() || p[1].back() <=p[2].back())) {
                // ele escolhe o tipo 1 caso o tipo 2 esteja vazio ou o menor preço do tipo 1 <= menor preço tipo 2
                s+=p[1].back();
                p[1].pop_back();
            } else {
                //caso contrário o tipo 2 é escolhido, note que se o 2 não tinha elementos a gente teria ido pro primeiro loop e é garantido que pelo menos um dos dois tenha elementos
                s+=p[2].back();
                p[2].pop_back();
            }          
        }
    }

    cout << s << '\n';

    return 0;
}
