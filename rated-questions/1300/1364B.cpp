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

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if(i== 0 || i == n - 1 || ((v[i - 1] < v[i]) ^ (v[i] < v[i + 1]))) ans.push_back(v[i]);
    }
    

    cout << ans.size() << endl;
    for (auto a : ans)
    {
        cout << a  << " ";
    }
    cout << endl;
    
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}