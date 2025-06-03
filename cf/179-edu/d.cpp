#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> v;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
                
        v.push_back(x);
    }

    sort(v.begin(), v.end());        

    int k = 0;

    int idx = 0, used = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(used % 2 == 0) cout << v[idx] << " " << v[m - idx - 1] << " ";
            else cout << v[m - idx - 1] << " " << v[idx] << " ";            
        }
        cout << endl;
        used ++;
        
        if(used == 2){
            used = 0;
            idx ++;
        }
        
    }        

}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}