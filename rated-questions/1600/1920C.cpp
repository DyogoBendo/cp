#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    auto check = [&](int k){
        int g = 0;

        for (int i = 0; i < k; i++)
        {
            for (int j = i; j < n; j+=k)
            {
                if(g == 0 && abs(v[i] - v[j]) == 0) continue;
                g = gcd(g, abs(v[i] - v[j]));
            }
            
        }
        return g;
    };

    int ans = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if(n % i) continue;

        ans += check(i) != 1;
        if(i != n/i) ans += check(n/i) != 1;
    }
    
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}