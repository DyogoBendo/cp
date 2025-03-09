#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'


void solve(){
    int n;
    cin >> n;    
    map<int, int> m;
    vector<vector<int>> entry(n);
    bool possible = false;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            m[x]++;
            entry[i].push_back(x);            
        }                
    }
    for (int i = 0; i < n; i++)
    {
        bool neutral = true;
        for (int x : entry[i])
        {
            if(m[x] == 1) neutral = false;
        }
        if(neutral) possible = true;
    }
    
    
    if(possible) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}