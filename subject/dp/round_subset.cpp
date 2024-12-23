#include <bits/stdc++.h>

using namespace std;

const int N = 2e2 + 1;

int dp[N][N];
int dp2[N][N];
int dp5[N][N];

int main(){
    int n, k;
    cin >> n >> k;
    
    vector<int> v2(n + 1);
    vector<int> v5(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        
        int c2 = 0, c5 = 0;
        while(v % 2 == 0){
            c2 ++;
            v /= 2;
        }
        while(v % 5 == 0){
            c2 ++;
            v /= 5;
        }

        v2[i] = c2;
        v5[i] = c5;
    }

    for (int i = 1; i <= n; i++)
    {
        dp[1][i] = min(v2[i], v5[i]);
        dp2[1][i] = 
    }
    

    for (int i = 2; i <= k; i++)
    {
        for (int j = i; j <= n; j++)
        {
            dp[i][j] = 0;
            for (int l = 1; l < j; l++)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][l])
            }
            
        }
        
    }
    
    
    
}