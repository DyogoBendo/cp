#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 998244353;

int t;

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    vector<int> cnt1(n + 1, 0); // prefix
    vector<int> cnt2(n + 1, 0); // prefix
    vector<int> cnt3(n + 1, 0); // prefix
    for (int i = 0; i < n; i++)
    {
        cnt1[i + 1] = cnt1[i] + (v[i] == 1);
        cnt2[i + 1] = cnt2[i] + (v[i] == 2);
    }
    
    for (int i = n - 1; i >= 0; i--)
    {
        cnt3[i] = cnt3[i + 1] + (v[i] == 3);
    }
    
    int lst_one = -1;

    int prev;

    int ans =  0;
    int qtd2 = 0;
    int curr = 1;
    

    for (int i = 0; i < n; i++)
    {
        if(v[i] == 1){
            if(lst_one == -1){
                lst_one = i; 
                prev = 1;
            } else{
              //  cout << "curr " << curr << endl;
                
                if(prev == 1) prev = curr;
                else{
                    prev --;
                    prev = (prev * curr + curr);
                } 
                prev ++;
                prev %= MOD;
                curr = 1;
            }
        }
        if(v[i] == 2){
            if(lst_one == -1) continue;
            //cout << "i: " << i << " lst one: " << lst_one << " prev: " << prev << " curr: " << curr << " cnt3: " << cnt3[i] << endl;

           // cout << "prev: " << prev << endl;
            int k = (((prev * curr) % MOD) * cnt3[i]) % MOD; 
           // cout << "k: " <<k << endl;
            ans += k;
            ans %= MOD;
            
            curr *= 2;
            curr %= MOD;
        }
    }
  
    cout << ans << endl;
    
}

signed main(){
    cin >> t;

    while(t--) solve();
}