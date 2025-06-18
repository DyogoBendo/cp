#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){   
    int n, s, x;
    cin >> n >> s >> x;

    vector<vector<int>> m;

    vector<int> tmp;
    for (int i = 0; i < n; i++)
    {
        int curr;
        cin >> curr;
        

        if(curr > x){            
            m.push_back(tmp);
            tmp.clear();
        } else{            
            tmp.push_back(curr);
        }
    }
    
    m.push_back(tmp);

    
    int ans = 0;
    for (auto v: m)
    {        
        int sz = v.size();
        vector<int> psum(sz + 1);

        for (int i = 0; i < sz; i++)
        {
            psum[i + 1] = psum[i] + v[i];
        }

        map<int, int> cnt;        
        vector<int> same_qtd;
        int cnt_equal = 0;
        cnt[0] = 1;

        for (int i = 1; i <= sz; i++)
        {                   
            if(v[i - 1] == x){                
                for (auto k : same_qtd)
                {                    
                    cnt[k] ++;
                }         
                cnt_equal ++;
                same_qtd.clear();                       
                same_qtd.push_back(psum[i]);                
            } else{
                same_qtd.push_back(psum[i]);
            }            
            if(cnt_equal) ans += cnt[psum[i] - s];                    
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