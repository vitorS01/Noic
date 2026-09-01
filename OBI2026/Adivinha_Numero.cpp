#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B,P; 
    cin >> A >> B >> P;

    int distA = abs(A-P);
    int distB = abs(B-P);

    if(distA < distB) cout << "A\n";
    else if (distB < distA) cout << "B\n";
    else cout << "E\n";
}
