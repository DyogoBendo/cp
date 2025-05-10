#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int MOD = 998244353;
const int MAXN = 3e5+10;
int fat[MAXN];
int inv[MAXN];

int fast_expo(int x, int p){ //x ^ p
    int ans = 1;
    while(p){
        if(p & 1){
            ans = (1LL) * x * ans % MOD;
        }   
        x = (1LL) * x * x % MOD;
        p >>= 1;
    }
    return ans;
}

void init(){
    fat[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        fat[i] = (1LL) * fat[i-1] * i % MOD;
    }
    inv[MAXN-1] = fast_expo(fat[MAXN-1], MOD-2);
    
    for (int i = MAXN-2; i >=0; i--)
    {
        inv[i] = (1LL) * inv[i+1] * (i + 1) % MOD;
    }
    
}

int mul(int a, int b){    
    return (1LL) * a * b % MOD;
}

int comb(int n, int k){    
    return mul(fat[n], mul(inv[n-k], inv[k]));
}

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ans = 1;

    for (int i = 0; i < n; i+=3)
    {
        int mx = 0, qtd = 0;
        auto calc = [&](int e1, int e2){
            if(e1 + e2 > mx){
                mx = e1 + e2;
                qtd = 1;
            } else if(e1 + e2 == mx){
                qtd++;
            }
        };

        calc(v[i], v[i+2]);
        calc(v[i+1], v[i+2]);
        calc(v[i], v[i+1]);        

        ans = (1LL) * ans * qtd % MOD;
    }    
    
    ans = mul(comb(n/3, n/6), ans);
    
    cout << ans << endl;
}


signed main(){
    init();
    darvem;
    int t = 1;    

    while(t--) solve();
}