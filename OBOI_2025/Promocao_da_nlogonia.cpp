#include <bits/stdc++.h>
using namespace std;

/*
Vamos primeiro tentar resolver o problema para apenas uma query e considere v como o vértice mais profundo da aresta i.

Note que podemos tratar a promoção como a venda de dois produtos distintos, um custando a[i] e outro custando b[i]-a[i] reais. 
Pela condição do enunciado, como a[i]b[i]-a[i], então só faz sentido comprar o segundo produto se já tiver comprado o primeiro.

Com isso, podemos realizar o seguinte algoritmo guloso na hora das compras: compramos os k produtos com menor custo a[i] e,
para cada ponto turístico na subárvore de v, compramos o segundo produto por b[i]-a[i] reais  b[i]-a[i] for menor do que o custo do
maior produto comprado até agora. 

Assim, sejam a[1]a[2] ...a[k] os k produtos com menores preços e seja c o vetor ordenado de forma crescente de b[i]-a[i] 
(somente considerando a subárvore do v).

Então sabemos que vamos trocar um produto até o ponto em que c[i]>a[i] e, como c está em ordem crescente e a em ordem decrescente, 
sabemos que essa condição é monotônica, então i pode ser encontrado com uma busca binária.
Agora queremos basicamente, para cada query, fazer uma busca binária e, na função de checagem, 
devemos ser capazes de determinar o i’ésimo menor valor de c dentro da subárvore do v.

Isso pode ser feito com divisão e conquista nas queries: 

Antes de tudo, devemos transformar as queries em queries de intervalo na pré-ordem da DFS, e vamos respondê-las offline.

Se você está no intervalo [l, r] e m=(l+r) / 2, podemos responder as queries que começam antes e terminam depois de m, 
e as demais serão respondidas posteriormente no algoritmo.

E, pela própria estrutura da árvore, sabemos que todas essas queries que passam por m estão contidas umas nas outras:
		        ___            1 
	        _______          2
       ____________        3
		        .
		        .
		        .
    __________________     q

Assim, podemos resolver essa camada da recursão fazendo o seguinte:
 
Vamos passando pelas queries de 1 até q, e adicionando os valores de c que ainda não haviam sido adicionados numa seg. 

Então, para cada query, podemos fazer busca binária e encontrar o i’ésimo elemento em O(logN),
o que torna a complexidade para responder uma query O(log2N). 
Além disso, uma vez encontrado i, podemos calcular a soma dos i primeiros valores de c facilmente com a seg, 
além da soma dos i primeiros elementos de a (que é estático). 

Toda vez que terminamos de processar uma camada, podemos limpar a seg e, assim, obtemos uma complexidade de O((r-l+1)*logN) por camada e, 
então, no total, a complexidade do código fica O((N+Q)*log2N).

Explicação parciais:
- (10 pontos) N<=20
Sem entendimento profundo, bruta masks de quais da subárvore pegará 2 por b[i]
- (10 pontos) b[i] >= 2*maior a[i]
Noção de pegar primeiro os produtos ordenados por a, sempre será os k menores + prefix sum.
- (20 pontos) estrela
Fazer na mão e ver que b[i] é equivalente a um outro produto
- (20 pontos) N <= 2000
Fazer brute considerando b[i]-a[i]
- (40 pontos) Sem restrições adicionais
Conhecer estruturas como D&C ou seg persistente

Nota: Nesse código usamos a achamos o k-ésimo menor C usando seg persistente se você quiser mais detalhes pode aprender mais sobre aqui:
https://cp-algorithms.com/data_structures/segment_tree.html#finding-the-k-th-smallest-number-in-a-range
*/

typedef long long ll;

const int MAXN = 1e5;
const ll INF = 2e9;

pair<int, int> eds[MAXN];
ll b[MAXN], pfA[MAXN+1], a[MAXN];
int pA[MAXN], pC[MAXN];
int tin[MAXN], tout[MAXN]; int t = -1;
vector<int> adj[MAXN];

void dfs(int v, int pai) {
    tin[v] = ++t;
    for (int viz : adj[v]) {
        if (viz == pai) continue;
        dfs(viz, v);
    }
    tout[v] = t;
}

struct Node {
    ll sum, mx; int actives;
    Node(ll _sum=0, ll _mx=0, int _actives=0):
        sum(_sum), mx(_mx), actives(_actives) {}
    Node operator+(Node right) {
        Node left = *this;
        return Node(
            left.sum + right.sum,
            max(left.mx, right.mx),
            left.actives + right.actives
        );
    }
};

struct SEG {
    int n; vector<Node> seg; vector<int> ls, rs;

    SEG(int _n=0) {
        n = 1;
        while (n < _n) n <<= 1;
        seg.reserve(30*n);
        createNode();
    }

    int createNode(int src = -1) {
        if (src == -1) {
            seg.push_back(Node());
            ls.push_back(-1);
            rs.push_back(-1);
        } else {
            seg.push_back(seg[src]);
            ls.push_back(ls[src]);
            rs.push_back(rs[src]);
        }
        return (int)seg.size()-1;
    }

    int getLeft(int v) {
        return ls[v] = (ls[v] == -1 ? createNode() : ls[v]);
    }

    int getRight(int v) {
        return rs[v] = (rs[v] == -1 ? createNode() : rs[v]);
    }

    int set(int v, int l, int r, int i, Node val) {
        v = createNode(v);
        if (l == r) {
            seg[v] = val;
            return v;
        }
        int m = (l + r) / 2;
        if (i <= m) ls[v] = set(getLeft(v), l, m, i, val);
        else rs[v] = set(getRight(v), m+1, r, i, val);
        seg[v] = seg[getLeft(v)] + seg[getRight(v)];
        return v;
    }

    Node rng(int v, int l, int r, int a, int b) {
        if (a <= l and r <= b) return seg[v];
        if (r < a or b < l) return Node();
        int m = (l + r) / 2;
        return rng(getLeft(v), l, m, a, b) + rng(getRight(v), m+1, r, a, b);
    }
};

bool cmpA(int i, int j) {
    return a[i] < a[j];
}

bool cmpC(int i, int j) {
    return (b[i]-a[i]) < (b[j]-a[j]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    for (int i=0; i<n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        eds[i] = {u, v};
    }
    for (int i=0; i<n; i++)
        pA[i] = pC[i] = i;

    sort(pA, pA+n, cmpA);
    pfA[0] = 0;
    for (int i=0; i<n; i++)
        pfA[i+1] = pfA[i] + a[pA[i]];

    dfs(0, -1);

    sort(pC, pC+n, cmpC);
    vector<int> versions; versions.push_back(0);
    SEG seg(n);
    for (int i=0; i<n; i++) {
        int idx = pC[i];
        versions.push_back(
            seg.set(versions.back(), 0, seg.n-1, tin[idx], Node(b[idx] - a[idx], b[idx] - a[idx], 1))
        );
    }

    int qs; cin >> qs;
    for (int q=0; q<qs; q++) {
        int edIdx, k; cin >> edIdx >> k; edIdx--;
        auto [v1, v2] = eds[edIdx];
        int subSrc = (tin[v1] < tin[v2] ? v2 : v1);
        int l=0, r=n; ll ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            Node rng = seg.rng(versions[mid], 0, seg.n-1, tin[subSrc], tout[subSrc]);
            if (rng.actives <= k and rng.mx <= a[pA[k-rng.actives]]) {
                ans = pfA[k-rng.actives] + rng.sum;
                l = mid+1;
            } else r = mid-1;
        }
        cout << ans << '\n';
    }

    return 0;
}
