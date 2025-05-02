#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

vector<int> calc(vector<int> &v){
    vector<int> cnt(v.size() + 1);
    
    int l = 0;

    while(l < v.size()){
        if(v[l] == 0){
            l ++;
            continue;
        }

        int r = l;
        while(r < v.size() && v[r]) r++;

        int mx_sz = r - l;        
        for (int i = 1; i <= mx_sz; i++)
        {
            cnt[i] += mx_sz - i + 1;
        }
        l = r;        
    }
    
    return cnt;
    
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> v1(n);
    vector<int> v2(m);

    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> v2[i];
    }    

    ll ans = 0;

    vector<int> cnt1 = calc(v1);
    vector<int> cnt2 = calc(v2);

    for (int i = 1; i <= n; i++)
    {
        if(k %i == 0 && m >= k/i){
            int a = i;
            int b = k / i;            

            ans += (ll) cnt1[a] * cnt2[b];                        
        }
    }
    
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}