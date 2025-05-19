#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

const int MOD = 1e9+7;
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
    int n, k;
    cin >> n >> k;

    map<int, int> cnt;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
        v[i] = x;
    }

    sort(v.rbegin(), v.rend());

    int soma = 0, lst = -1, used= 0;

    for (int i = 0; i < k; i++)
    {
       soma += v[i];
       if(v[i] != lst){
            lst = v[i];
            used = 1;
       } else{
            used ++;
       }
    }
    
    cout << comb(cnt[lst], used) << endl;
}


signed main(){
    init();
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}