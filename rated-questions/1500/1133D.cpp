#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    map<pair<int, int>, int> m;

    int ans = 0, to = 0;

    for (int i = 0; i < n; i++)
    {
        if(a[i] == 0 && b[i] == 0){
            to ++;
        } 

        if(a[i] == 0) continue;

        pair<int, int> k = {b[i]/__gcd(a[i], b[i]), (a[i]/__gcd(a[i], b[i]))};            
        m[k] ++;
        ans = max(ans, m[k]);                            
    }

    cout << ans + to << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}