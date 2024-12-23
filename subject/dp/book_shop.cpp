#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 1;
const int X = 1e5 + 1;

int dp[N][X], prices[N], pages[N];


int main(){
    int n, x;
    cin >> n >> x;


    for (int i = 1; i <= n; i++)
    {
        cin >> prices[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> pages[i];
    }
        

    for (int i = 1; i <= n; i++)
    {        
        for (int j = 1; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j];

            if(j - prices[i] >= 0){
                dp[i][j] = max(dp[i - 1][j - prices[i]] + pages[i], dp[i][j]);            
            } 
        }
        
    }
    
    cout << dp[n][x] << endl;

}