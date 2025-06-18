#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> psum(n+1);

    for (int i = 0; i < n; i++)
    {
        psum[i+1] = (psum[i] + v[i]) % 2;
    }
    
    ll ans= 0, cnt_odd = 0, cnt_even =1;

    for (int i = 0; i < n; i++)
    {
        int x = psum[i+1];

        if(x == 1){
            ans += cnt_even;
            cnt_odd ++;
        } else{
            ans += cnt_odd;
            cnt_even ++;
        }
    }
    
    cout << ans << endl;    
}