#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    int n, k;
    cin >> n >> k;
    
    set<char> s;

    string a, b;
    cin >> a >> b;

    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }

    vector<char> sv;
    for (auto c : s)
    {
        sv.push_back(c);
    }    

    auto check = [&](set<char> &change){
        int ans = 0, curr = 0;
        for (int i = 0; i < n; i++)
        {
            if(change.count(a[i]) or a[i] == b[i]){
                curr++;
            } else{
                ans += ((curr * curr) + curr) / 2;
                curr = 0;
            }
        }
        ans += ((curr * curr) + curr) / 2;
        return ans;        
    };

    int ans = 0;    
    for (int i = 0; i < 1 << sv.size(); i++)
    {
        int x = __builtin_popcount(i);
        if(x > k or (x < k && x < sv.size())) continue;
        
        set<char> curr;
        for (int j = 0; j < sv.size(); j++)
        {
            if((1 << j) & i) curr.insert(sv[j]);
        }        
        
        ans = max(ans, check(curr));
    }
    

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}