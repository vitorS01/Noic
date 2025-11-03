#include <bits/stdc++.h>
using namespace std;

/*
Subtarefa 1: A<=B<=C
Nesse caso, a ordem ótima de entrega das fitinhas para os níveis é A, B, C.

Para que seja possível distribuir as fitinhas, deve haver alguma permutação das cores (A, B, C) tal que A>=N1, B>=N2, C>=N3. Daí, basta fazer todas as 3!=6 possibilidades na mão usando alguns if/else’s.

-=-=-=-=-=
Solução alternativa:
Basta verificar a ordem A<=B<=C
*/

int main(){

  int a, b, c; cin >> a >> b >> c;

  int n1, n2, n3; cin >> n1 >> n2 >> n3;

  if(a >= n1 && b >= n2 && c >= n3) cout << "S\n";

  else if(a >= n1 && c >= n2 && b >= n3) cout << "S\n";
  
  else if(b >= n1 && a >= n2 && c >= n3) cout << "S\n";
  
  else if(b >= n1 && c >= n2 && a >= n3) cout << "S\n";
  
  else if(c >= n1 && a >= n2 && b >= n3) cout << "S\n";
  
  else if(c >= n1 && b >= n2 && a >= n3) cout << "S\n";

  else cout << "N\n";

  return 0;

}
