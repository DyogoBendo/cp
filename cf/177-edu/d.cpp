#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int MOD = 998244353;
const int MAXV = 5e5+10;

int sz, ans;
vector<int> oc(26);

int fat[MAXV];
int inv_fat[MAXV];

int mul(int a, int b){
    return (ll) a * b % MOD;
}

int expo(int x, int k){
    int ans=1, curr = x;
    while(k){
        if(k%2){
            ans = mul(curr, ans);                        
        }
        curr = mul(curr, curr);
        k/=2;
    }
    return ans;
}

int inv(int x){
    return expo(x, MOD-2);
}

int divide(int a, int b){
    return mul(a, inv(b));
}

void solve(){
    sz = 0, ans = 0;
    int in = 1;
    vector<int> oc(26);
    for (int i = 0; i < 26; i++)
    {
        cin >> oc[i];
        sz += oc[i];
        in = mul(in, inv_fat[oc[i]]);
    }
    
    // knpasack dp -> quantas formas diferentes temos de obter a soma X, usando até K elementos
    vector<int> dp(sz+1, 0);
    dp[0] = 1;
    for (int k = 0; k < 26; k++)
    {
        if(!oc[k]) continue;
        for (int x = sz-oc[k]; x >= 0; x--)
        {
            dp[x+oc[k]] += dp[x];
        }        
    }    
    
    ans = mul(mul(dp[sz/2],mul(fat[sz/2], fat[sz - sz/2])), in); 
        
    cout << ans << endl;
}

void init(){
    fat[0] = 1;
    for (int i = 1; i < MAXV; i++)
    {
        fat[i] = mul(fat[i-1], i);
    }    

    inv_fat[MAXV-1] = divide(1, fat[MAXV-1]);
    
    for (int i = MAXV-2; i >=0; i--)
    {
        inv_fat[i] = mul(inv_fat[i+1], i+1);
    }         
}


signed main(){
    init();
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}