#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> v;

    vector<int> kv(k, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x % k);
        kv[x%k] ++;
    }

    for (int i = 0; i < k; i++)
    {
        if(kv[i] == 1){
            cout << "YES" << endl;
            for (int j = 0; j < n; j++)
            {
                if(v[j] == i){
                    cout << j + 1 << endl;
                }
            }
            return;
        } 
    }

    cout << "NO" << endl;
    
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}