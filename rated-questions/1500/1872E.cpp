#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    string s;
    cin >> s;
    int total = 0;
    int active = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i] == '1') active ^= v[i];
        total ^= v[i];
    }
    
    vector<int> pxor(n+1, 0);
    for (int i = 0; i < n; i++)
    {
        pxor[i+1] = pxor[i] ^ v[i]; 
    }
    
    int q;
    cin >> q;
    while(q--){
        int o;
        cin >> o;
        if(o == 1){
            int l, r;
            cin >> l >> r;

            active ^= pxor[r] ^ pxor[l-1];            
        } else{
            int k;
            cin >> k;
            if(k == 1) cout << active << " ";
            else cout << (total ^ active )<< " ";
        }
    }
    cout << endl;
    
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}