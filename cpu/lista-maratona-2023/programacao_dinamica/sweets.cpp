#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;

    cin >> n >> m;

    vector<int> sweets(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> sweets[i];
    }

    sort(sweets.begin(), sweets.end());    
    vector<long long> dp(n);
    long long value = 0;
    for (size_t i = 0; i < n; i++)
    {        
        int k = i;
        value += sweets[i];        
        if(k >= m){
            dp[k] = sweets[k - m] + dp[k - m];            
            value += dp[k];
        }
        cout << value << " ";
    }
    cout << endl;
}