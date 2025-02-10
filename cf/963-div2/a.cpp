#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int a = 0, b = 0, c = 0, d = 0;

    for (int i = 0; i < 4 * n; i++)
    {
        if(s[i] == 'A') a++;
        if(s[i] == 'B') b++;
        if(s[i] == 'C') c++;
        if(s[i] == 'D') d++;        
    }

    int ans = min(n, a) + min(n, b) + min(n, c) + min(n, d);
    
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}