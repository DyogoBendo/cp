#include <bits/stdc++.h>

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

using namespace std;

int n;
string s;
int calc(char c, int m){    
    int l = 0, r = 0, cnt = 0, ans = 0;
    while(l < n){
        while(r < n && cnt + (s[r] != c) <= m){                        
            cnt += s[r] != c;            
            r ++;
        }                                
        ans = max(ans, r - l);
        cnt -= s[l] != c;
        l++;
    }    
    return ans;
}

void solve(){
    cin >> n >> s;    

    vector<vector<int>> dp(26, vector<int>(n + 1));
    
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = calc('a' + i, j);
        }
        
    }
    int q;
    cin >> q;
    while(q--){
        int m;
        char c;
        cin >> m >> c;

        cout << dp[c - 'a'][m] << endl;
    }
}

signed main(){
    darvem;
    int t = 1;    
    while(t--) solve();
}