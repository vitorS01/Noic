#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    int n;
    long double money;
    cin >> n >> money;
    vector<long double> v(n + 1);
    for (int i = 0; i < n; i++) cin >> v[i];
    long double stock;
    money = log(money);
    bool noStock = 1;
    bool noMoney = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] < v[i + 1]) {
            // price will rise
            if (!noMoney) {
                stock = money - log(v[i]);
                noStock = 0;
                noMoney = 1;
            }
        } else {
            // price will fall
            if (noStock) continue;
            money = stock + log(v[i]);
            noStock = 1;
            noMoney = 0;
        }
    }
    cout << fixed;
    cout << setprecision(12);
    cout << money << "\n";
}
