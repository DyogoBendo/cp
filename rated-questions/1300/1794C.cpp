#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'


void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int sz = 1;
    int curr = v[0];
    cout << sz << " ";
    for (int i = 1; i < n; i++)
    {        
        int pos = i - sz;
        if(sz + 1 <= v[pos]) sz++;
        cout << sz << " ";
    }
    cout << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}