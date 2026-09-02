#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+10;
int a[MAXN];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int time1 = 0, time2 = 0; // contar os passes do time 1 e 2 respectivamente

    for (int i = 2; i <= n; i++) {
        //a[i]*a[i-1] > 0 -> a[i] e a[i-1] tem mesmo sinal (ambos positivos ou negativos)
        if(a[i]*a[i-1]>0 && a[i]!=a[i-1]) {
            if(a[i]>0) time1++;
            else time2++;
        } 
    }

    cout << time1 << '\n';
    cout << tim2 << '\n';
}
