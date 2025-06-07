#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

signed main(){
    darvem;

    int n, q;
    cin >> n >> q;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> psum(n+1);

    for (int i = 0; i < n; i++)
    {
        psum[i+1] = psum[i] + v[i];
    }

    vector<int> minsum(n+1);

    for (int i = 1; i <= n; i++)
    {
        minsum[i] = minsum[i-1] + i;
    }
    
    while(q--){
        int l, r;
        cin >> l >> r;                

        if(psum[r] - psum[l-1] > minsum[r-l+1]) cout << "NIE" << endl;
        else cout << "TAK" << endl;
    }
    
}