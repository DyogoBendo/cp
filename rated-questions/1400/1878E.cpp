#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'


void solve(){
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<vector<int>> psum(n + 1, vector<int>(32, 0));

    for (int i = 0; i < n; i++)
    {        
        int k = v[i];
        for (int j = 0; j < 32; j++)
        {
            psum[i + 1][j] = psum[i][j] + (k % 2);
            k /= 2;
        }                
    }        

    int q;
    cin >> q;
    while(q--){
        int l, k;
        cin >> l >> k;

        auto check = [&](int x){            
            if(x == l-1) return false;                 
            if(x > n) return false;       

            int en = x;            
            int total = 0;

            for (int i = 0; i < 32; i++)
            {                
                int active = (psum[en][i] - psum[l - 1][i]) == en - l + 1;
                if(active) total += (1 << i);                
            }                                    
            return total >= k;            
        };

        int a = l-1, b = n + 1;
        while(a < b){
            int m = (b - a) / 2 + a;            

            if(check(m)){                
                a = m + 1;
            } else{                
                b = m;
            }
        }        
        if(b == l-1) cout << -1 << " ";
        else cout << b-1 << " ";
    }
    cout << endl;
    
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}