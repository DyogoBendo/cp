// https://codeforces.com/contest/276/problem/C

#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for (auto &x: v)
    {
        cin >> x;
    }

    vector<int> use(n, 0);

    while(q--){
        int a, b;
        cin >> a >> b;
        a--;
        use[a] ++;
        if(b < n) use[b] --;
    }

    for (int i = 1; i < n; i++)
    {
        use[i] += use[i - 1];
    }
    
    sort(use.begin(), use.end());
    sort(v.begin(), v.end());

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += use[i] * v[i];
    }
    
    cout << ans << endl;
    
}