#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;
    
    set<int> squares;

    for (int i = 1; i <= n; i++)
    {
        squares.insert(i * i);
    }
    
    set<int> s;

    for (int i = 0; i < n; i++)
    {
        s.insert(i + 1);
    }
    

    bool possible = true;
    int curr = 0;
    vector<int> ans;
    while(possible && ans.size() < n){
        bool found = false;
        for(auto k : s){            
            int x = k + curr;
            if(!squares.count(x)){
                found = true;
                ans.push_back(k);
                s.erase(k);
                curr = x;
                break;
            }            
        }
        if(!found) possible = false;
    }

    if(!possible) cout << -1 << endl;
    else{
        for (auto v : ans)
        {
            cout << v << " ";
        }
        cout << endl;
        
    }
    
}

signed main(){
    flash;
    int t;
    cin >> t;

    while(t--) solve();
}