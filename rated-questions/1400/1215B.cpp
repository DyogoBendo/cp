#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[i] = x ;
    }

    ll neg = 0, pos = 0;
    ll qtd_odd= 0, qtd_even = 1, curr = 0;


    for (int i = 0; i < n; i++)
    {
        curr += (v[i] < 0);
        curr %= 2;
            
        if(curr == 0){                       
            pos += qtd_even;
            neg += qtd_odd;
            qtd_even ++;
        } else{            
            pos += qtd_odd;
            neg += qtd_even;
            qtd_odd ++;
        }
    }
    
    cout << neg << " " << pos << endl;
    
}

signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}