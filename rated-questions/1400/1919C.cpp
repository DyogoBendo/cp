#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'


void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ans=0;
    vector<int> a(1, n+1);
    vector<int> b(1, n+1);

    for (int i = 0; i < n; i++)
    {
        if(a.back() > b.back()) swap(a.back(), b.back());
        if(v[i] <= a.back()){
            a.push_back(v[i]);
        } else if(v[i] <= b.back()){
            b.push_back(v[i]);
        } else{
            a.push_back(v[i]);
            ans ++;
        }
    }
    
    cout << ans << endl;

}   

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}