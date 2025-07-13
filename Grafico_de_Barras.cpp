#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, H;
    cin >> n;
    vector<int> altura(n);

    for (int &v : altura) cin >> v;

    H = *max_element(altura.begin(), altura.end()); // Pega o maior elemento do vetor
    vector<vector<int>> m(H, vector<int>(n, 0)); // Inicializa com 0's

    for(int j = 0;j < n; j++) {
        for (int i = H-altura[j]; i < H; i++) {
            m[i][j] = 1;
        }
    }

    for(int i = 0;i < H; i++) {
        for (int j = 0; j < n; j++) {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
