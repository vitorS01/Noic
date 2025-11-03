#include <bits/stdc++.h>
using namespace std;

/*
-Subtarefa 1: (N<=20)
Nessa subtarefa podemos iterar por todos os números possiveis números vitorianos de tamanho <= N e ver qual é o menor que é multiplo de N
O(2^n*N)

-Subtarefa2: (N<=2000):
A principal ideia dessa subtarefa é que podemos quebrar qualquer número vitoriano na soma de várias potências de 10. 
Isso motiva o uso de dp e podemos terminar o problema com uma construção descrita a seguir.
Defina dp [i][j] = 1 quando é possível achar um número vitoriano com i dígitos ou menos que deixa resto j mod n. 
A observação é que para construir um múltiplo vitoriano mínimo podemos primeiramente minimizar seu tamanho 
fazendo ser 1 na primeira posição i tal que dp i,0 = 1, e então iterar de i-1 à 0 tentando gulosamente tentando 
definir a[i] = 0 sempre que possível mantendo uma variável R,inicialmente 0, para marcar qual é o resto atual e atualizando devidamente. 
Quando estivermos no i-ésimo dígito e dp[i-1][1-R] == 1 fazemos a[i] = 0. 
Caso contrário temos que fazer a[i] = 1 e R = (R + p10[i])%n onde p10[i] = 10^i%n

-Subtarefa 3: (N<=10^6):
Para a solução completa do problema vamos tomar uma abordagem completamente diferente, vamos usar um grafo para descobrir 
o menor X vitoriano tal que (X mod n = i) para todo i de 0 a n-1, nossa resposta é simplesmente i = 0.
Sabemos que 1 com certeza será o menor x que deixa resto 1 para qualquer N > 1(se N=1, 1 já é a resposta do problema).
então veja que 10 e 11 são os próximos menores números vitorianos que podem ser obtidos a partir de 10*1 e 10*1 + 1,
ou seja podemos finalizar o problema fazendo um bfs partindo de 1 e então caso já tivemos visitado x%i então esse cara não vai melhorar a resposta. 
Caso contrario adicionamos 10*x mod n e 11*x mod n à fila e marcamos que visitamos x mod n. Para construir a resposta podemos guarda 
os vertices que nos levaram à i para cada i e vamos de trás pra frente a partir do N buscand o 1.

*/

#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,a,b) for (int i = a; i >= b; i--)

const int MAXN = 1e6;

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int n;cin >> n;
	if (n==1) {
		cout << "1\n";
		return 0;
	}
	vector<bool> mk(n);
	vector<pair<int,string>> inv(n);
	queue<int> q;
	q.push(1);
	mk[1] = 1;

	while (!q.empty()) {
		int x = q.front();q.pop();

		if (!mk[(10*x)%n]) {
			mk[(10*x)%n] = 1;
			inv[(10*x)%n] = {x,"0"};
			q.push((10*x)%n);
		}

		if (!mk[(10*x+1)%n]) {
			mk[(10*x+1)%n] = 1;
			inv[(10*x+1)%n] = {x,"1"};
			q.push((10*x+1)%n);

		}
	}

	string s = "";
	int ptr = 0;
	while (ptr != 1) {
		s+=inv[ptr].second;
		ptr = inv[ptr].first;
	}
	s+="1";
	reverse(s.begin(),s.end());
	cout << s << '\n';

	return 0;
}
