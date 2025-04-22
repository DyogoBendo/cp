#include <bits/stdc++.h>

using namespace std;
int n;

int soma_diagonal(vector<vector<int>> m){
    int soma = 0;

    for (int i = 0; i < n; i++)
    {
        soma += m[i][i];
    }
    return soma;
}

bool checa_linhas(vector<vector<int>> m, int soma){
    bool possivel = true;

    for (int i = 0; i < n; i++)
    {
        int soma_linha = 0;
        for (int j = 0; j < n; j++)
        {
            soma_linha += m[i][j];
        }
        if(soma_linha != soma) possivel = false;
    }
    return possivel;
}

bool checa_colunas(vector<vector<int>> m, int soma){
    bool possivel = true;
    for (int i = 0; i < n; i++)
    {
        int soma_coluna = 0;
        for (int j = 0; j < n; j++)
        {
            soma_coluna += m[j][i];
        }

        if(soma_coluna != soma) possivel = false;
    }
    return possivel;
}

bool checa_diagonal_secundaria(vector<vector<int>> m, int soma){
    bool possivel = true;
    int soma_diagonal_secundaria = 0;
    for (int i = 0; i < n; i++)
    {
        soma_diagonal_secundaria += m[i][n-i-1];
    }
    return soma_diagonal_secundaria == soma;
}


int main(){
    cin >> n;
    vector<vector<int>> m(n);
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        m[i] = v;
    }

    int soma = soma_diagonal(m);
    if(checa_colunas(m, soma) && checa_linhas(m, soma) && checa_diagonal_secundaria(m, soma)){
        cout << soma << endl;
    } else{
        cout << -1 << endl;
    }
    
}