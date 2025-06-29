#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long
const int INF = 1e18;

signed main(){
    darvem;

    int n, f, s;
    cin >> n >> f >> s;

    vector<int> p(n), q(n), perm(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];                
    }

    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
        perm[q[i]] = i;
    }
    
    int l = 0, r = 1;
    int ans = INF;
    while(l < n){
        int curr = p[l];        
        int pq = perm[curr];

        int sz = 1;
        while(pq < n - sz && r < n && q[pq+sz] == p[r]) sz++, r++;        

        int l_sum = (l + pq) * f;
        int r_sum = (n - (pq + sz) + n - r) * s;        

        ans= min(max({l_sum, r_sum}), ans);
        l = r;
        r = l + 1;

    }
    
    cout << ans << endl;

}