#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1e9 + 7;

int fast_expo(int k,  int e){
    int p = k;
    int a = 1;

    while(e){
        if(e % 2){
            a %= MOD;
            a *= p;
            a %= MOD;
        }
        p %= MOD;
        p *= p;
        p %= MOD;
        e /= 2;
    }

    return a % MOD;
}

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> ps(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++)
    {
        ps[i + 1] = (ps[i] + v[i]) % MOD;
    }


    int p = 0;
    int q = fast_expo((n * (n - 1)) /2, MOD - 2);         

    for (int i = 0; i < n; i++)
    {
        p += (v[i] * ((MOD + ps[n] - ps[i + 1]) % MOD)) % MOD;
        p %= MOD;
    }    

    int ans = (p * q) % MOD;

    cout << ans << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t--)solve();
}