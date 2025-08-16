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
    int mx = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        mx = max(mx, v[i]);
    }

    vector<int> ans(mx+1, -1);
    sort(v.begin(), v.end());
    int j = 0;
    ans[1] = 1;
    for(int i = 2; i<= mx; i++){
        while(j < n && v[j] < i - 1) j++;
        ans[i] = ans[i-1] + n-j;
    }   

    while(q--){
        int b;
        cin >> b;
        if(b >= ans.size()) cout << -1 << endl;
        else cout << ans[b] << endl;
    }
}