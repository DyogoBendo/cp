#include <bits/stdc++.h>
using namespace std;

int n, m, s;
int soma;

int main(){
    soma = 0;
    cin >> n >> m >> s;
    int x, y, r, x2, y2;
    for (int i=0; i<s; i++){
        cin >> x >> y >> r;
        x2 = min(n, x+r) - max(1, x-r) + 1;
        y2 = min(m, y+r) - max(1, y-r) + 1;
        cout << x2 << " " << y2 << endl;
        soma += x2*y2;
    }
    cout << soma/(n*m) << endl;
}