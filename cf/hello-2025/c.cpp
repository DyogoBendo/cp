    #include <bits/stdc++.h>

    using namespace std;

    #define ll long long


    void solve(){
        int l, r, ol, pr;
        cin >> l >> r;
        ol = l;
        pr = r;

        int n = r - l;

        int change = 0;
        for (int i = 30; i >= 0; i--)
        {
            int x = 1 << i;                

            if((r - x) >= 0 && (l - x) < 0){
                change = x;
                break;
            }
            if(r - x > 0){
                r -= x;
                l -= x;
            }

        }

        int diff = change - l;        

        int a1 = ol + diff;
        int a2 = ol + diff - 1;
        int a3 = ol + diff - 2;

        if(a3 < ol){
            a3 = a1 + 1;
        }

        cout << a1 << " " <<  a2 << " " << a3 << endl;
    }

    signed main(){
        int t;
        cin >> t;
        while(t--) solve();
    }