#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    vector<int> v(4);
    for (int i = 0; i < n; i++)
    {
        v[i%4] ++;
    }

    if(v[3] < v[0] or v[2] < v[1]) cout << "Alice" << endl;
    else cout << "Bob" << endl; 
    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}