#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);

    vector<int> psum(2 * n + 1);
    vector<int> cnt(2*n + 1);

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        if(l == r){
            cnt[l] ++;
            psum[l] = 1;
        }
        v[i] = {l, r};
    }

    for (int i = 1; i < 2* n + 1; i++)
    {
        psum[i] += psum[i - 1];
    }
    

    string s = "";
    for (auto a : v)
    {        
        if(a.first == a.second){
            if(cnt[a.first] > 1) s += '0';
            else s+= '1';
        } else{            
            int sm = psum[a.second] - psum[a.first - 1];                            
            if(sm == a.second - a.first + 1){
                s+='0';
            } else{
                s+='1';
            }
        }
    }
    
    cout << s << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}