#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin >> s;
    int n = s.length();

    int ans = 0;
    for (int d = 1; d <= n / 2; d++)
    {
        int cnt = 0;
        for (int i = 0; i < n - d; i++)
        {
            cnt += (s[i] == s[i + d] || s[i] == '?' || s[i + d] == '?');

            if(i - d >= 0){
                cnt -= (s[i] == s[i - d] || s[i] == '?' || s[i - d] == '?');                
            }
            if(i - d >= -1 && cnt == d){
                ans = 2* cnt;
            }
        }
        
    }

    cout << ans << endl;
    

}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}