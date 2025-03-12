#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'


void solve(){
    string s;
    cin >> s;

    int curr = 0;
    int ans = 0;

    int o_cnt = 0;

    int n = s.size();
    
    for (int i = 0; i < n; i++)
    {
        int cnt= 0;
        while(i < n && s[i] == 'v'){
            cnt ++;
        }
    }
    
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}