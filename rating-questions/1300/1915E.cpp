#include <bits/stdc++.h>

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if(i%2) v[i] *= -1;
    }
    
    vector<int> psum(n + 1, 0);

    bool found = false;
    set<int> s;
    s.insert(0);
    for (int i = 0; i < n; i++)
    {
        psum[i + 1] = psum[i] + v[i];        
        if(s.count(psum[i+1])) found = true;
        s.insert(psum[i+1]);
    }
    
    cout << (found ? "YES" : "NO") << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}