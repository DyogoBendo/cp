#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s, t;
    cin >> s >> t;

    int ans = 0;

    ans += s.size() + t.size();

    for (int i = 0; i < min(s.size(), t.size()); i++)
    {
        if(s[i] == t[i]) ans --;
        else break;
        if(i == 0) ans ++;
    }

    cout << ans << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}