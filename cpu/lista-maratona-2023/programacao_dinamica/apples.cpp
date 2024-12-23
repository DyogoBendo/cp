#include <bits/stdc++.h>

using namespace std;

#define INF 100000 

int main(){
    int c;

    cin >> c;
    while(c){
        c--;
        int n, k;
        cin >> n >> k;
        vector<int> prices(k + 1);
        prices.push_back(0);
        for(int i = 1; i <= k; i++) cin >> prices[i];

        vector<vector<vector<int>>> dp;

        for(int i = 0; i <= k; i++){
            vector<vector<int>> v;
            for(int j = 0; j <= k; j ++){
                v.push_back(vector<int>(n + 1, INF));
            }
            dp.push_back(v);
        }

        for (size_t i = 1; i <= k; i++)
        {
            for (size_t j = 0; j <= k; j++)
            {
                for (size_t l = 0; l <= n; l++)
                {
                    if(!j || !l){
                        dp[i][j][l] = 0;
                    } else{
                        if(prices[i] == -1) continue;
                        int skip = dp[i - 1][j][l];
                        int get_next = INF;
                        int get_keep = INF;
                        if(j >= i){
                            get_next = dp[i - 1][j - i][n - 1] + prices[i];
                            get_keep = dp[i][j - i][n - 1] + prices[i];
                        }
                        dp[i][j][l] = min(skip, min(get_next, get_keep));
                    }
                    
                }
                
            }            
        }     
        if(dp[k][k][n] == INF) cout << - 1 << endl;
        else cout << dp[k][k][n] << endl;        
    }
}