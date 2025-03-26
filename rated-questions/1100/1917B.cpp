#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    set<char> st;

    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans += st.size();
        if(i < n) st.insert(s[i]);
    }    
    cout << ans << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}