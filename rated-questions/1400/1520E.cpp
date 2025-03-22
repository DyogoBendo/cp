#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> idx;

    for (int i = 0; i < n; i++)
    {
        if(s[i] == '*') idx.push_back(i);
    }

    int dst = 0;
    vector<int> add(n, 0);
    for (int i = 0; i < idx.size(); i++)
    {
        add[idx[i] - idx[0] - i]++;
        dst += idx[i] - idx[0] - i;
    }        
    int ans = dst;
    int need_add = 0;
    int sub = idx.size();        

    for (int i = 0; i <= n - idx.size(); i++)
    {                        
        ans = min(dst, ans);
        need_add += add[i];
        sub -= add[i];
        dst += need_add - sub;
    }
    
    cout << ans << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}