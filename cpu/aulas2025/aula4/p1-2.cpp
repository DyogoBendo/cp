#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string gabarito;
    string prova;
    cin >> n >> gabarito >> prova;

    int pontos = 0;
    for (int i = 0; i < n; i++)
    {
        pontos += gabarito[i] == prova[i];
    }
    
    cout << pontos << endl;
}