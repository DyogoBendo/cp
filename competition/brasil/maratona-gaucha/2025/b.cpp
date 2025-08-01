#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

signed main(){
    darvem;

    int l, c;
    cin >> l >> c;
    int n = l*c;
    vector<int> v(n);
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        tot += v[i];
    }    
    
    int x = tot/n, ans = 0, mov = 0; 

    for(int i = 0; i < n; i++){
        ans += abs(x - v[i]);
        mov += x;
    }

    sort(v.rbegin(), v.rend());
    
    for(int i = 0; i < n && mov < tot; i++, mov++) if(v[i] > x) ans--; else ans++;

    ans/=2;
    cout << ans*10 << " " << 1 + (tot % n > 0) << endl;
}