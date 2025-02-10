    #include <bits/stdc++.h>

    using namespace std;

    #define ll long long

    void solve(){
        ll l, r, g;
        cin >> l >> r >> g;
        ll lb = l / g;
        if(l%g) lb++;

        ll rb = r / g;        

        for (ll i = rb - lb; i >= 0; i--)
        {        
            // cout << "i: " << i << endl;
            for (ll j = lb; j <= rb - i; j++)
            {
                //cout << "j: " << j << endl;
                if(gcd(j, j + i) == 1){
                    cout << j * g << " " << (j + i) * g << endl;
                    return;
                }
            }
            cout << endl;
            
        }
        
        cout << "-1 -1" << endl;
    }

    signed main(){
        int t;
        cin >> t;
        while(t--) solve();
    }