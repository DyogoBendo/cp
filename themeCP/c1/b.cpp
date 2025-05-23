#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    vector<int>v(n);

    if(n == 1){
        cout << 1 << endl;
        return;
    }
    if(n == 2){
        cout << 1 << " " << 2 << endl;
        return;
    }
    v[0] = 3;
    v[n-1] = 2;
    v[n/2] = 1;
    int idx = 1;
    for (int i = 4; i <= n; i++)
    {
        if(!v[idx]){
            v[idx] = i;
        } else{
            idx++;
            v[idx] = i;
        }
        idx++;
    }

    for (auto a : v)
    {
        cout << a << " ";
    }
    cout << endl;
    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}