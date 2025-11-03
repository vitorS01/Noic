#include <bits/stdc++.h>
using namespace std;

/*
A ideia é verificar todas as substrings possíveis, calcular seu “grau de beleza” e atualizar a resposta com o maior valor encontrado.
Percorremos cada posição i da string, assumindo-a como início da substring. Se o caractere inicial não for ‘N’, ignoramos. Caso contrário, iteramos sobre cada posição final j >= i, mantendo a contagem de ‘N’ na substring S[i..j].
Se o caractere final for ‘N’ e o tamanho da substring for pelo menos 3, calculamos o “grau de beleza” e atualizamos o máximo.
Como utilizamos dois loops aninhados e cada passo mantém a contagem de ‘N’ acumulada, a complexidade final é O(n^2).

*/

#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s; cin >> s;
    double res = 0;
    for (int l = 0; l < (int)s.size() - 2; l++) {
        if(s[l] != 'N') continue;
        int qtdT = 1;
        for (int r = l + 1; r < (int)s.size(); r++) {
            if(s[r] != 'N') continue;
            qtdT++;
            if(r - l + 1 >= 3)
                res = max(res, (double)(qtdT - 2)/(double)(r - l -1));
        }
    }

    cout << fixed << setprecision(9) << res << '\n';
    return 0;
}
