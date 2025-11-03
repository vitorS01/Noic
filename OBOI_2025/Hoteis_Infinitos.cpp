#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,a,b) for (int i = a; i >= b; i--)

const int MAXN = 1e6+10;
const int INV2 = 500000004;
const int MOD = 1e9 + 7;
int a[MAXN],lf[MAXN],rg[MAXN];

/*
Vamos analisar uma subarray definida por [L,R] , seja x1,x2,y1,y2 as cordenadas que definem a submatriz. x1<=x2, y1<=y2
(sendo M[x1][y1] o canto superior esquerdo da foto e M[x2][y2] o canto superior direito da foto).
Seja M = max(a[L], a[L+1],...a[R]). Temos então que x1=L, x2=R. Vamos contar agora a quantidade de y1<=y2 satisfazem a condição 
para ser uma foto, primeiro observe que é necessário e suficiente que y2 <= M. pois caso contrário a foto ficaria mostraria o fim do maior hotel. 
e se for verdade com certeza temos uma foto em que pelo menos o maior hotel parece infinito. 
Ou seja basta contar quantos 1<=y1<=y2 <= M. Isso é (M+1 escolhe 2). Agora basta calcular M+1 escolhe 2 para todo [L,R].

Perceba que podemos calcular a contribuição de cada elemento, A[i]. 
Ou seja para cada elemento contar em quantas subarrays esse é o máximo mais a esquerda e então adicionar a resposta A[i]*(A[i]+1)/2*(contribuição)
á resposta. Para calcular a contribuição basta achar o j mais próximo a esquerda tal que A[i] <= A[j] 
e o k mais próximo a direita tal que A[i] < a[k]. então a contribuição é (i-j)*(k-i). 
Para calcular j e k só usar uma stack monotônica e dois passes na array. Resolvendo o problema em O(N)

explicação das parciais:
- Subtarefa 1: 
podemos só brutar todos os x1,x2,y1,y2 e verificar se a condição é satisfeita em O(N) iterando pela linha do topo
e vendo se ela tem pelo menos um andar de um prédio, complexidade final O(n^5)
- Subtarefa 2:
da pra otimizar a subtarefa 1, usando soma de prefixo para uma complexidade em O(N^4)
- Subtarefa 3:
Para essa subtarefa podemos brutar todos L,R e adicionar o máximo desse range escolhe 2
- Subtarefa 4:
Nesse caso é bem mais fácil calcular as contribuições já que i é o máximo de todos os intervalos com L<=i e R=i.
Assim é só iterar pela array e adicionar i*(a[i]+1)*a[i]/2 a resposta.

*/

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int n;cin >> n;
	rep(i,1,n) cin >> a[i];

	int ans = 0;
	a[0]=a[n+1] = 1e9+1;
	stack<int> stk;
	stk.push(0);

	rep(i,1,n) {
		while (a[i] > a[stk.top()]) stk.pop();
		lf[i] = stk.top();
		stk.push(i);
	}
	while (!stk.empty()) stk.pop();
	stk.push(n+1);
	per(i,n,1) {
		while (a[i] >= a[stk.top()]) stk.pop();
		rg[i] = stk.top();
		stk.push(i);
	}

	rep(i,1,n) {
		int k = a[i]*(a[i]+1)%MOD;
		k = (k*INV2)%MOD;
		k = (k*(i-lf[i]))%MOD;
		k = (k*(rg[i]-i))%MOD;
		ans = (ans+k)%MOD;
	}
	cout << ans << '\n';
}
