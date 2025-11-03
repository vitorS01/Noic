#include <bits/stdc++.h>
using namespace std;

/*
Queremos que a soma de um trecho da lista seja múltiplo de M. A melhor forma de pensar nisso é com prefixos.
A ideia é: se dois prefixos têm o mesmo resto módulo M, por exemplo nas posições [1, L] e [1, R], 
então o subarray [L + 1, R] terá soma divisível por M. Queremos o prefixo mais à esquerda possível, pois ele gera o maior intervalo ao ser removido.
Então, vamos iterar o vetor e usar um map. Se o resto do prefixo atual nunca apareceu, 
guardamos a posição atual no map. Caso contrário, encontramos uma possível resposta e atualizamos o máximo.                                                                                                          Usando map, a complexidade do código é de O(n log n).

*/

#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, mod;
    cin >> n >> mod;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }

    map<int,int> modd;
    int pref = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
        pref += v[i];
        if (pref%mod != 0 && modd[pref % mod] == 0) {
            modd[pref % mod] = i;
        } else {
            ans = max(ans, i - modd[pref % mod]);
        }
    }

    cout << ans << '\n';
    return 0;
}
