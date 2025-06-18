#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, s;
    cin >> n >> s;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    if(v[0] >= s){
        cout << v[n-1] - s << endl;
    } else if (v[n-1] <= s){
        cout << s - v[0] << endl;
    } else{
        cout << min(s - v[0], v[n-1] - s) + v[n-1] - v[0] <<endl;
    }

}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}