#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const ll MOD = 1e9 + 7;

int add(ll x, ll y){
    return (ll) ((x % MOD) + (y%MOD)) % MOD;
}

int mul(ll x, ll y){
    return (ll) (x%MOD) * (y%MOD) % MOD;
}


int sub(ll x, ll y){
    return (ll) ((x % MOD) - (y % MOD) + MOD) % MOD;
}
int calc(ll x, ll y){
    return (ll) mul(mul(add(x, y), sub(y, sub(x, 1))), (MOD + 1) / 2);
}

signed main(){    

    ll x;
    cin >> x;

    int n = x % MOD; 
    int ans = 0;

    vector<pair<int, int>> v1;
    vector<pair<int, int>> v2;
    
    for (ll i = 1; i * i <= x; i++)
    {                        
        v1.push_back({x/i % MOD, i});        
        v2.push_back({i, x/i % MOD});        
    }    

    reverse(v2.begin(), v2.end());
    for (auto x : v2)
    {
        v1.push_back(x);
    }

    for (int i = 0; i < v1.size() - 1; i++)
    {        
        ans = add(ans, mul(calc(add(v1[i+1].first, 1), v1[i].first), v1[i].second));        
    }
    ans = add(ans, n);
    cout << ans << endl;

}