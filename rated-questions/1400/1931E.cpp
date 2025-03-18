#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'


void solve(){
    int n, m;
    cin >> n >> m;

    int total_digits = 0;
    vector<int> right_zeros;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        int cnt_zero = 0;        
        bool found_nonzero = false;
        while(a){
            if(a % 10 == 0 && !found_nonzero) cnt_zero ++;
            else found_nonzero = true;
            total_digits ++;
            a /= 10;
        }
        right_zeros.push_back(cnt_zero);        
    }
    
    sort(right_zeros.rbegin(), right_zeros.rend());

    for (int i = 0; i < n; i+=2)
    {
        total_digits -= right_zeros[i];
    }    

    cout << (total_digits <= m ? "Anna" : "Sasha") << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}