#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);

    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;
    for(int &x: c) cin >> x;

    vector<int> cnt(n + 1, 0);

    for (auto x : c)
    {
        x --;
        cnt[b[x]] ++;
    }

    int ans =0;
    for (auto x : a)
    {
        ans += cnt[x];
    }
    
    cout << ans << endl;

}