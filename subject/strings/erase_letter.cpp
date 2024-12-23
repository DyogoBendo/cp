#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans[n];
    ans[n - 1] = 1;
    ans[n - 2] = 1 + (s[n - 1] != s[n - 2]);

    for (int i = n - 3; i >= 0; i--)
    {
        ans[i] = ans[i + 1];
        if(s[i] != s[i + 1]){
            ans[i] += ans[i + 2];
        }
    }
    
    
    cout << ans[0] << endl;
}

int main(){
    int t;
    cin >> t;

    while(t--) solve();
}