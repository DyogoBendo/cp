#include <bits/stdc++.h>

using namespace std;

int n, m;
bool check(char s[]){
    return s[0] == '1' && s[1] == '5' && s[2] == '4' && s[3] == '3';
}

int procura_nivel(vector<vector<char>> &matrix, int nivel){
    char s[4] = {'X', 'X', 'X', 'X'};

    int i = nivel, j = nivel;

    int total = 2 *(n + m) - (8 *nivel) - 1;
    int ans = 0;
    int direction = 0;           
    while(total--){
        s[0] = s[1];
        s[1] = s[2];
        s[2] = s[3];        
        s[3] = matrix[i][j];        

        ans += check(s);
        if(direction == 0){
            if(j < m - nivel - 1) j ++;
            else direction = 1;
        } 
        if(direction == 1){
            if(i < n - nivel - 1) i ++;
            else direction = 2;
        } 
        if(direction == 2){
            if(j > nivel) j --;
            else direction = 3;
        } 
        if(direction == 3){
            if(i > nivel) i --;
            else{
                j ++;
                direction = 0;
            } 
        } 

    }

    return ans;
}

void solve(){
    cin >> n >> m;

    vector<vector<char>> matrix(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
        
    }

    // preciso percorrer um nivel no sentido horario


    int qtd_niveis = min(n, m) / 2;

    int nivel = 0;
    int ans = 0;
    while(nivel < qtd_niveis){
        ans += procura_nivel(matrix, nivel);
        nivel ++;
    }

    cout << ans << endl;

}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}