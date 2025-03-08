#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
    int n, x, ans = 0;
    cin >> n;

    set<int> s;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int l = 0, r = 0;    

    while(r < n){
        x = v[r];
        while(s.count(x)){
            s.erase(v[l]);
            l++;
        }
        s.insert(x);
        ans = max(ans, (int) s.size());
        r++;
    }
    
    cout << ans << endl;
}

signed main(){
    flash;
    solve();
}