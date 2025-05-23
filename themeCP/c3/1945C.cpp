#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        v[i] = s[i] - '0';
    }

    vector<int> psum(n+1);
    vector<int> ssum(n+1);

    for (int i = 0; i < n; i++)
    {
        psum[i+1] = psum[i] + (v[i] == 0);
        ssum[n-i-1] = ssum[n-i] + v[n-i-1];        
    }
    
    int ans = -1;

    for (int i = 0; i <= n; i++)
    {        
        int add = psum[i] + ssum[i];        

        if(2*psum[i] >= i && 2*ssum[i] >= n-i){
            if(ans == -1) ans = i;
            else{                
                if(abs(n - 2*i) < abs(n - 2*ans) ) ans = i;
            }
        }
    }
    
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}