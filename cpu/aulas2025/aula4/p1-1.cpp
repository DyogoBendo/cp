#include <bits/stdc++.h>

using namespace std;

int main(){
    char gabarito[80];
    char prova[80];
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> gabarito[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> prova[i];
    }
    
    int pontuacao = 0;
    for (int i = 0; i < n; i++)
    {
        if(gabarito[i] == prova[i]){
            pontuacao ++;
        } 
    }
    
    cout << pontuacao << endl;
}