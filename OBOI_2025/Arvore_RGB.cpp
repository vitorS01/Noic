#include<bits/stdc++.h>
using namespace std;

/*
(10 pontos) N,Q <= 500:
Para essa subtarefa basta simular o processo literalmente como descrito no enunciado para cada query
O(N^2*Q)
(10 pontos) N <= 2000:
Observe que se montarmos a pirâmide com a base completa de 1 a N cada bloquinho dela representa um intervalo. 
Da pra visualizar isso pegando qualquer bloco e ir descendo na pirâmide vendo quem são os caras adjacentes em baixo, vendo daonde saiu cada bloco.
Ou seja podemos precalcular todos os bloquinhos da pirâmide em O(N^2) e depois responder cada query em O(1) só vendo o bloco respectivo
O(N^2+Q)

(40 pontos) Q = 1:
Essa é uma das partes mais cruciais pro problema, vamos primeiro fazer algumas transformações convenientes defina vermelho -> 0, verde -> 1 azul -> 2
Seria muito bom se pudesse-mos achar o cara que será posto no topo de dois blocos adjacentes com cores x1,x2 apenas fazendo alguma continha. E realmente da
o bloco do topo é (-x-y) mod 3 (verifique!). Para facilitar nossa vida podemos considerar que essa operação é a soma (x+y) mod 3 e negar o valor depois se
a linha do bloco do topo for par ou ímpar, Considere o caso N = 3:
    a
  b1   b2
c1   c2   c3
Vamos tentar achar o topo baseado na base temos que
a = (b1+b2) mod 3
b1 = (c1+c2) mod 3
b2 = (c2+c3) mod 3
ou seja a = c1+2*c2 + c3 mod 3
podemos generalizar isso como no triangulo de pascal onde
a = c1+(n-1 escolhe 1)*c2 + (n-1 escolhe 2)*c3 + ... + (n-1 escolhe n-1)*cn mod 3
E assim podemos resolver essa subtarefa iterando pelo intervalo [L,R] e calculando a expressão dada.
Nota: temos que usar o teorema de Lucas para calcular os binomiais pois n pode ser bem maior que 3 e não seria possivel achar o inverso
de alguns termos que seriam multiplos de 3

(40 pontos) sem restrições adicionais:
Observe o caso n = 4
         1
       1   1
     1   2   1
   1   3   3   1
Veja que os termos do meio vão ser multiplicados por 3 e vão acabar sendo zerados quando tomar-mos mod 3
dessa forma para calcular o topo basta ver quem ficaria no topo das pontas da base!
é possível generalizar essa propriedade para todo n da forma 3^k+1 usando indução (a prova vai ficar de exercicio pro leitor)
tome k = 5, temos que B = 244. Que é aproximadamente sqrt(n).
Para resolver o problema podemos precalcular algumas fileiras da piramide usando a propriedade para calcular a fileira B caras acima bem rápido
Assim podemos responder as queries considerando a fileira mais no topo da query para termos que iterar por no máximo sqrt(n) caras fazendo da mesma forma
que a subtarefa 3. Finalizando assim o problema com um algoritmo que funciona em O((n+q)*B*log_3(N)) onde B é aproximadamente sqrt(n)
*/

#define rep(i,a,b) for(int i = a; i <= b; ++i)
#define pb push_back

const int MAXN = 1e5 + 10;
int a[MAXN], B=244, calc[500][MAXN], ch[3][3] = {{1,0,0},{1,1,0},{1,2,1}};

int comb_mod3(int n, int k) {
	if (k > n) return 0;
	int ans = 1;

	while (n || k) {
		int ni = n%3, ki = k%3;
		if (ki > ni) return 0;
		ans = (ans*ch[ni][ki]) %3;
		n/=3, k/=3;
	}
	return ans;
}

map<char,int> mp = {{'R', 0}, {'G', 1}, {'B', 2}};
char mp2[] = {'R','G','B'};

int32_t main() {
	int n,q;cin >> n >> q;
	string s; cin >> s;
	rep(i,1,n) {
		a[i] = mp[s[i-1]];
		calc[0][i] = a[i];
	}

	rep(j,1,n/B) {
		int sz = (B-1)*j+1;
		rep(i,1,n-sz+1) calc[j][i] = (6-calc[j-1][i]-calc[j-1][i+B-1])%3;
	}

	while(q--) {
		int l,r;cin >> l >> r;

		int k = (r-l+1)/B, sz = r-l-(B-1)*k+1;
		int ans = 0;
		rep(i,l,sz+l-1) {
			int chh = comb_mod3(sz-1,i-l);

			ans = (ans + chh*calc[k][i])%3;
		}
		if (sz%2==0) ans = (2*ans)%3;
		cout << mp2[ans] << '\n';
	}
	return 0;
}
