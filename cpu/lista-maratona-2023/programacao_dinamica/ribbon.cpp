#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<vector<int>> dp;

    for(int i = 0; i <= n; i++) dp.push_back({-1, -1, -1, -1});

    for (size_t i = 0; i <= n; i++)
    {
        for (size_t j = 1; j < 4; j++)
        {
            int value;
            switch (j)
            {
            case 1:
                value = a;
                break;
            case 2:
                value = b;
                break;
            case 3:
                value = c;
                break;
            default:
                break;
            }
            if(i == value){
                dp[i][j] = 1;
            } else{
                int ignore = dp[i][j - 1];            
                int previous = i > value ? dp[i - value][j - 1] + 1 : -1;
                int keep = i > value ? dp[i - value][j] + 1 : - 1;
                if(!previous) previous = -1;
                if(!keep) keep = - 1;
                dp[i][j] = max(ignore, max(previous, keep));
            }
        }        
    }

    cout << dp[n][3] << endl;
    
}