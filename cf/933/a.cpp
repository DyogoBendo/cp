#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> b(n), c(m);

    for (auto &x : b)
    {
        cin >> x;
    }
    for (auto &x : c)
    {
        cin >> x;
    }

    int total = 0;

    for (int i = 0; i < n; i++)
    {
        int current_b = b[i];
        for (int j = 0; j < m; j++)
        {
            int current_c = c[j];
            if(current_b + current_c <= k) total ++;
        }        
    }
    
    cout << total << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}