#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    vector<int> v(n);
    for(int i =0; i < n; i++){
        cin >> v[i];
        v[i]--;
    }

    vector<vector<int>> prefix(n + 1, vector<int>(10, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            prefix[i][j] = prefix[i - 1][j] + (v[i - 1] == j);
        }
    }
    

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if(i % 2 == n % 2) ans += i;
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        for (int k = 0; k < 10; k++)
        {
            if(prefix[])
        }
        

        int prev = i;
        int after = n - i - 2;

        if()
    }
    

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) solve();
}