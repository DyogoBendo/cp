#include <bits/stdc++.h>

using namespace std;

int main(){
    int m[10][10];

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }

    int soma = 0;
    bool possivel = true;

    for (int i = 0; i < n; i++)
    {
        soma += m[i][i];
    }

    for (int i = 0; i < n; i++)
    {
        int soma_linha = 0;
        for (int j = 0; j < n; j++)
        {
            soma_linha += m[i][j];
        }
        if(soma_linha != soma) possivel = false;
    }
    
    for (int i = 0; i < n; i++)
    {
        int soma_coluna = 0;
        for (int j = 0; j < n; j++)
        {
            soma_coluna += m[j][i];
        }

        if(soma_coluna != soma) possivel = false;
    }

    int soma_diagonal_secundaria = 0;
    for (int i = 0; i < n; i++)
    {
        soma_diagonal_secundaria += m[i][n-i-1];
    }
    
    if(soma_diagonal_secundaria != soma) possivel = false;

    cout << (possivel ? soma : -1) << endl;   
}