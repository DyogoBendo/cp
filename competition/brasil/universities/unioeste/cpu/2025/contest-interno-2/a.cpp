#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i] == 'B'){
            ans ++;
            for (int j = 0; j < k && j + i < n; j++)
            {
                s[i + j] = 'W';
            }
            
        }
    }
    
    cout << ans << endl;
}

signed main(){
    flash;
    int t;
    cin >> t;

    while(t--) solve();
}