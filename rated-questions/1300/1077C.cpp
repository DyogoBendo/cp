#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    map<int, int> cnt;
    int s = 0;    
    for (int i = 0; i < n; i++)
    {        
        cin >> v[i];

        cnt[v[i]]++;
        s += v[i];
    }    

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int x = v[i];
        cnt[x]--;        
        int look = s - x;        
        if(look % 2==0 && cnt[look/2]){
            ans.push_back(i + 1);
        }
        cnt[x]++;
    }
    
    cout << ans.size() << endl;
    for (auto a : ans)
    {
        cout << a << " ";
    }
    cout << endl;
    
}

signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}