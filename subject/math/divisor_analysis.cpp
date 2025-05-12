#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

const int MOD = 1e9+7;

ll mul(ll a, ll b){
    return (1LL) * (a % MOD) * (b % MOD) % MOD;
}

ll pow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1){
            ans = mul(ans, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

ll inv(ll a) {
    return pow(a, MOD-2);
}

int add(int a, int b){
    return ((0LL) + (a % MOD) + (b % MOD)) % MOD; 
}
int sub(int a, int b){
    return ((0LL) + (a % MOD) - (b % MOD) + MOD) % MOD; 
}

int number_of_factors(vector<pair<int, int>> &v){
    int ans = 1;

    for (auto [p, k] : v)
    {
        ans = mul(ans, add(k, 1));
    }
    return ans;
}

int sum_of_factors(vector<pair<int, int>> &v){
    int ans = 1;

    for (auto [p, k] : v)
    {
        int x = mul(sub(pow(p, add(k, 1)), 1), inv(sub(p, 1)));
        ans = mul(ans, x);
    }
    return ans;
}

int product_of_factors(vector<pair<int, int>> &v){
    int ans = 1, div_cnt = 1;
    for (auto [p, k] : v)
    {
        ans = mul(pow(ans, k+1), pow(pow(p, k*(k+1)/2), div_cnt));
        div_cnt = (div_cnt * (k+1)) % (MOD-1);
    }        
    return ans;
}

signed main(){
    darvem;

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    
    cout << number_of_factors(v) << " " << sum_of_factors(v) << " " << product_of_factors(v) << endl;
}