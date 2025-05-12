#include <bits/stdc++.h>

using namespace std;

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

int calc(int p, int k, int b){
    ll d_1 = inv((p - 1 + MOD) % MOD);
    ll dk_1 = (pow(p, (k * (b % (MOD - 1)) + 1) % (MOD - 1)) - 1 + MOD) % MOD;
    return  mul(d_1, dk_1);
}

signed main() {
	ifstream fin("sumdiv.in");
	ll a, b;
	fin >> a >> b;

	ofstream fout("sumdiv.out");
    if (b == 0) {
        fout << '1' << '\n';  // a^0 = 1]
        return 0;
    }
    ll ans = 1;
    for (ll i = 2; i * i <= a; i++) {
        if (a % i == 0) {				
            ll cnt = 0;
            while (a % i == 0) {
                cnt++;
                a /= i;
            }							
            ans = mul(ans, calc(i, cnt, b));
        }
    }

    if (a > 1 && (a - 1) % MOD) {			
        ans = mul(ans, calc(a, 1, b));
    } else if (a > 1) {			
        ans = mul(ans, add(b, 1));
    }

    fout << ans << '\n';
}