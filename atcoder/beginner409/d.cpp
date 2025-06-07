#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    string s;
    cin >> n >> s;

    int idx = -1;
    for (int i = 0; i < n-1; i++)
    {
        if(s[i] > s[i+1] ){
            idx = i;
            break;
        }
    }

    if(idx == -1){
        cout << s << endl;
        return;
    }

    int idx_lst = n;
    for (int i = idx+1; i < n; i++)
    {
        if(s[i] > s[idx]){
            idx_lst = i;
            break;
        } 
    }
    

    for (int i = 0; i <= n; i++)
    {        
        if(i == idx_lst){
            cout << s[idx];
            if(i<n){
                cout << s[i];
            }
        } else if(i != idx && i < n){
            cout << s[i];
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