#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, k;
    cin >> n >> k;

    int z = 0, one = 0;

    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if(s[i] == '0') z++;
        else one++;
    }

    int ma = max(z, one);
    int mi = min(z, one);
    
    if(k < (ma - mi) / 2 or (ma-mi)/2 % 2 != k % 2 or  k > (one/2) + (z/2)) cout << "NO" << endl;
    else cout << "YES" << endl; 
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}