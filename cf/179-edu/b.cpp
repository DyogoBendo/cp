#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> cubes;
    cubes.push_back(1);
    cubes.push_back(2);

    for (int i = 2; i < n; i++)
    {
        cubes.push_back(cubes[i-2] + cubes[i-1]);
    }

    reverse(cubes.begin(), cubes.end());
    int biggest = cubes[0];

    while(m--){
        int w, l, h;
        cin >> w >> l >> h;        
        
        int mx = max({w, l, h});
        int mn = min({w, l, h});

        if(mn < biggest) cout << '0';
        else if(cubes[0] + cubes[1] > mx) cout << '0';
        else cout << '1';
    }
    cout << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}