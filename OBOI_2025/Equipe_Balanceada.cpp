#include <bits/stdc++.h>
using namespace std;

/*
A observação do problema é perceber que o processo definido no enunciado independe
da forma como você realiza as operações. Mais especificamente, 
o conjunto dos alunos que vão restar na equipe são os ⌊k-1 / 2⌋  com menor habilidade (A) e os ⌈k-1 / 2⌉ com maior habilidade (B).
A prova é feita simplesmente por contradição:
É mais fácil dividir em dois casos:
1) k par:
|A|=⌊k-1 / 2⌋ = k / 2 -1
Quando um elemento é removido, sabemos que há k / 2-1 elementos menores que ele. Então, se um elemento de A fosse removido, isso implicaria que(k / 2-1)+1k / 2 - 1, um absurdo!
|B|= ⌈k-1 / 2⌉ = k / 2
Quando um elemento é removido, sabemos que há k / 2 maiores que ele. Daí ficamos com 
k / 2 +1k / 2

2) k ímpar:
|A|=⌊k-1 / 2⌋=⌈k-1 / 2⌉=|B|=k-1 / 2
Quando um elemento é removido, sabemos que há k-1 / 2 elementos menores/maiores que ele. Daí, k-1 / 2+1k-1 / 2

Depois disso, podemos ir passando pelas possíveis divisões do grupo e ir mantendo o MEX da união dos conjuntos com alguma estrutura de dados. 

Um jeito possível é:
Manter alguns sets, que vão ir guardando os ⌊k-1  / 2⌋  "piores" e os ⌈k-1 / 2⌉ "melhores" alunos do primeiro e segundo grupo.
Toda vez que você mudar a divisão de i para i + 1, você deve atualizar cada um desses sets em O(logN).
Por fim, podemos também ir guardando as habilidades atuais numa seg, daí dá para fazer os updates também em O(logN) e,
para calcular o MEX atual, basta fazer uma busca binária no primeiro valor tal que soma[valor] != valor (pois então significa que tem alguém faltando). 
Também dá para fazer só usando sets e busca binária na resposta.
Assim, a complexidade fica O(N * logN).

Explicação parciais:
(5 pontos): N <= 5
Qualquer tipo de brute pode funcionar, inclusive fazer os casos na mão
(10 pontos): 2K- 2 = N 
Nessa parcial, basta perceber que só há uma maneira de formar as duas equipes, então só é preciso saber calcular o MEX de um conjunto.
(15 pontos): Para i < k, h[i] =i
Nesse caso, deve-se perceber que sempre é ótimo escolher dividir o grupo nos k-1 primeiros alunos e aplicar o processo de seleção nos demais. 
Isso porque as ⌊k-1 / 2⌋ menores habilidades sempre permanecerão no conjunto e qualquer outra divisão excluiria alguma das ⌈k-1 / 2⌉ 
maiores habilidades entre [1,k-1] e, portanto, diminuiria a resposta. Assim, para essa parcial deve-se ter uma ideia de quais 
elementos vão sobrar no conjunto, ou conseguir simular alguma estratégia em O(N) para o segundo grupo.
(20 pontos): K=3
Nessa parcial, deve-se concluir que o menor e maior elemento sempre ficarão no conjunto. Assim, 
dá para ir mantendo máximo/mínimo de prefixo/sufixo.
(25 pontos): N<=1000
Solução quadrática (sem estruturas de dados).
(25 pontos): Sem restrições adicionais

*/

const int MAXN = 1e5 + 10;

int h[MAXN];

int pref[MAXN], suf[MAXN];

int n, k;

int sz_A, sz_B;

set<int> A, B;

int cnt;

void init(){

  cnt = 0;
  A.clear(); B.clear();

}

void add(int x, int mex){

  if(!A.empty() && x < *A.rbegin()){

    if(*A.rbegin() < mex) cnt --;
    A.erase(*A.rbegin());
      
    A.insert(x);
    if(x < mex) cnt ++;

  } else if(!B.empty() && x > *B.begin()){

    if(*B.begin() < mex) cnt --;
    B.erase(*B.begin());
    
    B.insert(x);
    if(x < mex) cnt ++;

  }

}

bool check(int mex){

  init();

  for(int i=1; i<k; i++){
    if(h[i] < mex) cnt ++;
    B.insert(h[i]);
  }

  while(A.size() < sz_A){
    A.insert(*B.begin());
    B.erase(*B.begin());
  }

  pref[k - 1] = cnt;

  for(int i=k; i<=n; i++){
    add(h[i], mex);
    pref[i] = cnt;
  }

  init();

  for(int i=n; i>(n - k + 1); i--){
    if(h[i] < mex) cnt ++;
    B.insert(h[i]);
  }

  while(A.size() < sz_A){
    A.insert(*B.begin());
    B.erase(*B.begin());
  }

  suf[n - k + 2] = cnt;

  for(int i=(n - k + 1); i>=1; i--){
    add(h[i], mex);
    suf[i] = cnt;
  }

  for(int i=1; i<n; i++){
  
    if(i < k - 1 || n - i < k - 1) continue;

    if(pref[i] + suf[i + 1] == mex - 1) return true;

  }

  return false;

}

int bs(){

  int l = 1, r = n + 1;

  while(l < r){
    int m = l + (r - l + 1) / 2;
    if(check(m)) l = m;
    else r = m - 1;
  }

  return l;

}

int main(){
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> k;

  for(int i=1; i<=n; i++) cin >> h[i];

  sz_A = (k - 1) / 2, sz_B = k / 2;

  cout << bs() << "\n";

  return 0;
}
