#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define int long long

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int &x: v) cin >> x;

    int ans = 0;
    for (int a = n; a > 0; a--)
    {
        vector<int> tmp;
        for (int i = 0; i < a; i++)
        {
            tmp.push_back(v[i]);
        }
        sort(tmp.begin(), tmp.end());
        
        int curr = k;
        for (int i = a - 1; i >= 0; i-= 2)
        {
            curr -= tmp[i];
        }
        
        if(curr >= 0){
            ans = a;
            break;
        }
    }
    cout << ans << endl;
    
}

signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}