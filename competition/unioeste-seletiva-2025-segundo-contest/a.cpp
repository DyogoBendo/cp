#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'


void solve(){
    string s;
    cin >> s;
    int n = s.size();

    vector<int> v(26, 0);

    for (int i = 0; i < n; i++)
    {
       v[s[i] - 'a']++;
    }
    
    int mx = 0;
    char ans;

    for (int i = 0; i < 26; i++)
    {
        if(v[i] > mx) mx= v[i], ans = 'a' + i;
    }
    
    cout << ans << endl;

}

signed main(){
    darvem;
    int t = 1;

    while(t--) solve();
}