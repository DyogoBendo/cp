#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        total += v[i];
    }

    if(total == n){
        cout << "YES" << endl;
        return;
    }
    
    for (int i = 0; i < n; i++)
    {

        if(!v[i]){            
            if(i > 0 && v[i-1] == 0){
                cout << "YES" << endl;
                return;
            }            
        }        
    }
    
    cout << "NO" << endl;    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}