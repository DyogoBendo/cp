#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
    string s;
    cin >> s;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if(s[i] == 'p') cout << 'q';
        else if(s[i] == 'q') cout << 'p';
        else cout << 'w';
    }
    cout << endl;
    
}

signed main(){
    flash;
    int t;
    cin >> t;

    while(t--) solve();
}