#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    string s;
    cin >> s;    
    ll ans = 0;

    int n = s.size();

    vector<int> psum(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        if(i > 0 && s[i] != 'v' && s[i - 1] == 'v') psum[i] --;
        psum[i + 1] += psum[i] + (s[i] == 'v'); 
    }    
    if(s[n - 1] == 'v') psum[n]--;

    for (int i = 0; i < n; i++)
    {
        if(s[i] == 'o'){            
            ans += (ll) (psum[i]) * (psum[n] - psum[i + 1]);
        }
    }
    
    cout << ans << endl;
    
}

signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}