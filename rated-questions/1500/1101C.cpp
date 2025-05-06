#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    vector<tuple<int, int, int>> entries;

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;

        entries.push_back({l, 1, i});
        entries.push_back({r+1, -1, i});
    }

    sort(entries.begin(), entries.end());
    
    vector<int> ans(n);
    set<int> actives;
    int lst = 0, cnt[2] = {0};

    for (auto [p, d, i] : entries)
    {
        // cout << "p: " << p << " d: " << d << " i: " << i << endl;        
        if(d == 1){
            if(actives.size() == 0) lst = !lst;
            int c= lst;                        
            cnt[c]++;
            //cout << "c: " << c << endl;
            ans[i] = c;
            actives.insert(i);            
        } else{                                                
            actives.erase(i);
        }
    }
    
    if(cnt[0] == 0 || cnt[1] == 0) cout << -1 << endl;
    else{
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] + 1 << " ";
        }
        cout << endl;
    }
    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}