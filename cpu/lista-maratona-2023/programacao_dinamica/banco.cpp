#include <bits/stdc++.h>

using namespace std;

int main(){
    int v;
    int cedulas[7] = {0};
    int pesos[] = {0, 2, 5, 10, 20, 50, 100};
    cin >> v;

    for (size_t i = 1; i <= 6; i++)
    {
        cin >> cedulas[i];
    }
    
    vector<vector<vector<int>>> dp;

    for(int i = 0; i <= 6; i++) {
        vector<vector<int>> tmpV;
        for(int j = 0; j <= cedulas[i]; j ++){
            vector<int> vet(v + 1, 0);
            tmpV.push_back(vet);
        }
        dp.push_back(tmpV);
    }

    for (size_t i = 1; i <= 6; i++)
    {        
        for (size_t j = 0; j <= cedulas[i]; j++)
        {
            for (size_t k = 0; k <= v; k++)
            {
                if(!k){
                    dp[i][j][k] = 1;
                } else{
                    int skip = dp[i - 1][cedulas[i - 1]][k];                    
                    int get_keep = k >= pesos[i] && j > 0 ? dp[i][j - 1][k - pesos[i]]: 0;
                    dp[i][j][k] = skip + get_keep;
                }
            }            
        }
    }

    cout << dp[6][cedulas[6]][v] << endl;
    
}