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

    int curr= 0;
    bool ans = false;
    for (int i = 0; i < n-1; i++)
    {
        curr ^= v[i];
        bool possible = true;
        int j = i + 1;
        int groups = 1;
        while(j < n){
            int x= v[j];
            while(j < n - 1 && x != curr){
                j++;
                x ^= v[j];
            }                
            if(x != curr){                
                if(x != 0 || (x == 0 && groups == 1) ) possible = false;
            } 
            groups ++;
            j++;
        }
        ans |= possible;
    }
    
    cout << (ans ? "YES" : "NO") << endl;
    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}