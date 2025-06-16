#include <bits/stdc++.h>
#define flash ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

using namespace std;
#define int long long

const int MOD = 1e9 + 7;

int fastexpo(int n, int k){
    int x = 1;
    int p = n;
    while(k){
        if(k % 2){
            x *= p;
            x %= MOD;
        }
        p *= p;
        p %= MOD;
        k/=2;
    }

    return x;
}

int mul(int a, int b){
    return (a*b) % MOD;
}

int add(int a, int b){
    return (a+b) % MOD;
}

int sub(int a, int b){
    return ((a-b)+MOD) % MOD;
}

int division(int a, int b){
    return mul(a, fastexpo(b, MOD - 2));
}

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> psum(n + 1, 0);
    vector<int> psqsum(n+1, 0);
    for (int i = 0; i < n; i++)
    {
        psum[i + 1] = add(psum[i], v[i]);
        psqsum[i + 1] = add(psqsum[i], mul(v[i], v[i]));
    }
    
    while(q--){
        int l, r;
        cin >> l >> r;

        int i = sub(psum[r], psum[l-1]);        

        int ans = division(sub(mul(i, i), sub(psqsum[r], psqsum[l-1])), 2LL);
        cout << ans << endl;
    }
    
}

signed main(){
    flash;
    int t = 1;

    while(t--) solve();
}