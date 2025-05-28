#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    string s;
    cin >> s;

    int k = stoi(s);

    for (int i = 0; i * i <= k; i++)
    {
        if(i * i == k){
            cout << i << " " << 0 << endl;
            return;
        }
    }
    cout << -1 << endl;
    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}