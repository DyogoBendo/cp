#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)(a).size())

const int MOD = 998244353;

int mul(int a, int b){
    return 1LL * a * b % MOD;
}

int fast_expo(int x, int k){
    int ans = 1;
    while(k){
        if(k&1){
            ans = mul(ans, x);
        }

        x = mul(x, x);
        k >>= 1;
    }
    return ans;
}

int inv(int x){
    return fast_expo(x, MOD-2);
}

int divide(int a, int b){
    return mul(a, inv(b));
}

int add(int a, int b){
    return (a + b) % MOD;
}

int sub(int a, int b){
    a -= b;
    if(a < 0) a += MOD;
    return a;
}


void solve(){
    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    for (int i=0; i<n; i++){
        cin >> va[i];
    }

    for (int i=0; i<n-1; i++){
        cin >> vb[i];
    }

    vector<int> mul_suffix(n);
    mul_suffix[n-1] = 1;

    for(int i = n-2; i>= 0; i--){
        mul_suffix[i] = mul(mul_suffix[i+1], vb[i]);
    }

    vector<int> psum(n+1);

    for(int i = 0; i < n; i++){
        psum[i+1] = add(psum[i], mul(va[i], mul_suffix[i]));
    }

    int q;
    cin >> q;

    while(q--){
        int l, r;
        cin >> l >> r;

        int tot = psum[r];
        int remove = psum[l-1];

        int curr = sub(tot, remove);
        curr = divide(curr, mul_suffix[r-1]);

        cout << curr << endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int cases = 1;
    //cin >> cases;
    for (int i=0; i<cases; i++) solve();
}