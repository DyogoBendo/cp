#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 998244353;

int fast_expo(int b, int e){    
    int ans = 1;
    int p = b;
    while(e){        
        if(e % 2){            
            ans *= p;            
            ans %= MOD;            
        }
        p *= p;
        p %= MOD;        
        e /= 2;
    }
    return ans % MOD;
}

void solve(){
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    vector<int> b(n);

    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    vector<int> ao = a;
    vector<int> bo = b;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 1;

    for (int i = 0; i < n; i++)
    {
        ans *= min(a[i], b[i]);
        ans %= MOD;
    }
    
    cout << ans;
    while(q--){
        int o, x;
        cin >> o >> x;

        x--;        
        int old, curr;
        if(o == 1){
            int v = ao[x];
            ao[x]++;
            int p = upper_bound(a.begin(), a.end(), v) - a.begin() - 1;            
            old=  min(a[p], b[p]);
            a[p]++;  
            curr =           min(a[p], b[p]);
        } else{
            int v = bo[x];
            bo[x]++;
            int p = upper_bound(b.begin(), b.end(), v) - b.begin() - 1;
            old=  min(a[p], b[p]);
            b[p]++;            
            curr = min(a[p], b[p]);
        }                
        if(curr > old) ans += (ans * fast_expo(old, MOD - 2));
        ans %= MOD;

        cout << " " << ans;
    }   
    cout << endl;
    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); std::cout.tie(nullptr);    
    
    int t;
    cin >> t;
    while(t--) solve();
    
}