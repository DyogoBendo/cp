#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<int> fs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> fs[i];
    }

    sort(fs.rbegin(), fs.rend());

    ll ans = 0;
    
    int pos = 1;
    while(pos < fs.size()){
        fs.pop_back();
        ans += fs[pos];
        pos += 2;        
    }
    
    cout << ans << endl;
    
}