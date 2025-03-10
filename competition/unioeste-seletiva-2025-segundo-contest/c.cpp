#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'


void solve(){
    int n;
    cin >> n;

    vector<tuple<int, int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int a, c;
        cin >> a >> c;
        v[i] = {a, c, i + 1};
    }

    sort(v.rbegin(), v.rend());

    int curr = 1e9 + 10;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int c= get<1>(v[i]);
        if(c > curr) continue;

        curr = c;
        ans.push_back(get<2>(v[i]));
    }
    sort(ans.begin(), ans.end());
    
    cout << ans.size() << endl;
    for (auto a : ans)
    {
        cout << a << " ";
    }
    cout << endl;
    
    
}

signed main(){
    darvem;
    int t = 1;

    while(t--) solve();
}