#include <bits/stdc++.h>

using namespace std;

int m[10][10];
int n;

bool check_lines(int soma){
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = 0; j < n; j++)
        {
            s += m[i][j];
        }
        
        if(s != soma) return false;
    }
    
    return true;
}

bool check_columns(int soma){
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = 0; j < n; j++)
        {
            s += m[j][i];
        }
        
        if(s != soma) return false;
    }
    
    return true;
}

bool check_main_diagonal(int soma){
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += m[i][i];          
    }
    if(s != soma) return false;
    
    return true;
}

bool check_sec_diagonal(int soma){
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += m[i][n - i - 1];          
    }
    if(s != soma) return false;
    
    return true;
}


int main(){
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
        
    }

    int soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma += m[0][i];
    }
    
    if(check_columns(soma) && check_lines(soma) && check_sec_diagonal(soma) && check_main_diagonal(soma)){
        cout << soma << endl;
    } else{
        cout << -1 << endl;
    }
    
}