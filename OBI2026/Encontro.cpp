#include <bits/stdc++.h>
using namespace std;

int L[3],R[3];

int main(){
    int ans = 0;
    for (int i = 0; i <= 2; i++) {
        cin >> L[i] >> R[i];
    }

    for (int d = 1; d<=31; d++) {
        for (int i = 0; i <= 2; i++) {
            if(d>=L[i] && d <= R[i]) ans++;
        }
    }

    cout << ans << '\n';
    
    return 0;
}
