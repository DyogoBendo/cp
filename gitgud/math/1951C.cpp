#include <bits/stdc++.h>

using namespace std;

#define int long long

int calc(int x){
    return (x * (x + 1)) / 2;
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ans = 0;

    sort(v.begin(), v.end());    

    int r = 0;
    int qtd = 0;
    for (int i = 0; i < n && k != 0; i++)
    {                
        r = min(k, m);
        ans += r * m * qtd;
        ans += (v[i] * r);
        k -= r;        
        qtd ++;         
    }    

    cout << ans << endl;
}

signed main(){
    int t;
    cin >> t;

    while(t--) solve();
}