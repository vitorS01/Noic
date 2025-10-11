#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;cin >> n >> m;
    int cnt = 0;
    
    for(int i = 1; i <= m; i+=5) {
        cnt++;
    }
    
    if(cnt<n) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }

    return 0;
}
