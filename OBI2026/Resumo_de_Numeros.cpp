#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int cnt = 0;

    while(n != 321) {
        int t = 0,i = 0,p = 0;

        while (n>0) {
            int d = n%10;
            n/=10;

            t++;
            if(d%2==0) p++;
            else i++;
        }
        n = 100*t + 10*i + p;
        cnt++;
    }

    cout << cnt << '\n';
}
