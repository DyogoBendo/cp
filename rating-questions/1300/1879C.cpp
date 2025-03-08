#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define int long long
const int MOD = 998244353;
const int MAXN = 2e5 + 10;

int fat[MAXN];

int mul(int a, int b){
    return (a * b) % MOD;
}

void calc(){
    fat[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        fat[i] = mul(i, fat[i-1]);
    }
}

int expo(int n, int k){
    int x = n;
    int ans = 1;
    while(k){
        if(k % 2){
            ans = mul(ans, x);        
        }
        x = mul(x, x);
        k /= 2;
    }
    return ans;
}

int divide(int a, int b){
    return mul(a, expo(b, MOD - 2));
}

int comb(int k, int n){
    return divide(fat[n], fat[n-k]);
}

int add(int a, int b){
    return (a + b) % MOD;
}

void solve(){
    string s;
    cin >> s;

    int n = s.size();
    
    int total = 0;     
    int ans = 1;   
    for (int i = 0; i < n; )
    {
        int curr = 0;                
        while(i < n && s[i] == '0'){
            curr ++;
            i++;
        }
        if(!curr){
            while(i < n && s[i] == '1'){
                curr ++;
                i++;
            }            
        }               

        total += (curr - 1);                   
        ans = mul(ans, curr);
    }        
    
    cout << total << " " << mul(ans, fat[total]) << endl;
}

signed main(){
    darvem;
    calc();
    int t = 1;
    cin >> t;

    while(t--) solve();
}