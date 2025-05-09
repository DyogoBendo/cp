#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    int mx = -1e9;
    int mn = 1e9;

    vector<int> v(n);
    vector<int> pos;
    vector<int> neg;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mx = max(mx, v[i]);
        mn = min(mn, v[i]);

        if(v[i] >= 0){
            pos.push_back(v[i]);
        } else{
            neg.push_back(v[i]);
        }
    }    
    
    if(mx == mn){
        cout << "No" << endl;
        return;
    }
    
    sort(pos.begin(), pos.end(), greater<int>());
    sort(neg.begin(), neg.end());

    int a = 0, b = 0, curr = 0, cnt = 0;
    vector<int> ans;

    while(cnt < n){        
        if(a < pos.size() && b < neg.size()){
            int o1 = curr + pos[a];
            int o2 = curr + neg[b];

            if(abs(o1) < abs(o2)){
                curr = o1;
                ans.push_back(pos[a++]);
            } else{
                curr = o2;
                ans.push_back(neg[b++]);
            }
        } else if(a < pos.size()){
            ans.push_back(pos[a++]);
        } else{
            ans.push_back(neg[b++]);
        }
        cnt++;
    }

    cout << "Yes" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}