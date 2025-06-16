#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> v(n);
    int dst = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if(i > 0){
            dst += v[i] - v[i-1] - 1;
        }
    }

    int problems = 0;
    while(q--){
        int idx, x;
        cin >> idx >> x;
        idx--;

        int p = 0;        
        if(idx > 0){            
            if(v[idx-1] < v[idx] && v[idx-1] >= x) p ++;
            if(v[idx-1] >= v[idx] && v[idx-1] < x) p --;            
            dst += x - v[idx];
        }
        if(idx < n - 1){
            if(v[idx] < v[idx+1] && x >= v[idx+1]) p++;
            else if(v[idx] >= v[idx+1] && x < v[idx+1]) p--;            
            dst += v[idx] - x;            
        }        
        problems += p;
        v[idx] = x;
                
        if(!problems && dst >= k) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}