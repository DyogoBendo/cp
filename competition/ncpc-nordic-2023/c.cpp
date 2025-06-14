#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    string s;
    cin >> s;

    map<char, int> values = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int sz = s.size();
    int mx = 0, ans = 0;
    for (int i = sz - 1; i >= 0; i--)
    {
        int x = values[s[i]];
        if(x < mx) ans -= x;
        else ans += x;

        mx = max(x, mx);
    }

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}