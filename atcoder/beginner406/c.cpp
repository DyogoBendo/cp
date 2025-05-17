#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    //darvem;

    int n;
    cin >> n;
    vector<int> v(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }    

    int l = 0;

    while(l < n-1 && v[l+1] < v[l]){        
        l++;
    }     
    
    bool state = 0;
    vector<ll> sequences;
    for (int i = l; i < n-1; )
    {                   
        int sz = 0;
        while((state == 0 && i < n-1 && v[i] < v[i+1]) or (state == 1 && i < n-1 && v[i] > v[i+1])){            
            sz ++;
            i++;
        }
        if(!state) sequences.push_back(sz);
        state ^=1;        
    }
    
    ll ans = 0;
    for (int i = 1; i < sequences.size(); i++)
    {
        ans += sequences[i] * sequences[i-1];
    }
    
    
    cout << ans << endl;   
}