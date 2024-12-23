#include <bits/stdc++.h>

using namespace std;

int main(){
    long double a, b, c, d;
    cin >> a >> b >> c >> d;

    long double cima = (a * b *d);
    long double baixo = (a*d + b*c - a*c) * b;

    printf("%.11LF\n", cima/baixo);
}