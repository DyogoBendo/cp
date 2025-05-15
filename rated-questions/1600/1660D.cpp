#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> m;

    int s = 1;
    vector<int> v;
    vector<int> idx;
    bool c = false;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;        
        if(x == 0){       
            if(v.size()) m.push_back(v);
            v.clear();
            c = false;
        } else{
            v.push_back(x);
            if(!c) idx.push_back(i);
            c = true;
        }        
    }
    m.push_back(v);

    auto calc = [&](vector<int> &v){
        int sz = v.size();
        int s = 1, l = 0, r = sz - 1;
        int qtd2 = 0;
        for (auto x : v)
        {
            if(x < 0) s *= -1;
            if(abs(x) == 2) qtd2++;
        }                   
        if(s == 1) return make_tuple(0, 0, qtd2);
        
        int l1= l, r1 = r, q1 = qtd2;
        int l2 = l, r2 = r, q2 = qtd2;        

        while(l1 <= r1){
            if(v[l1] < 0){
                if(abs(v[l1]) == 2) q1--;
                l1++;
                break;
            }
            if(abs(v[l1]) == 2) q1--;
            l1++;
        }
        while(r2 >= l2){            
            if(v[r2] < 0){
                if(abs(v[r2]) == 2) q2--;
                r2--;
                break;
            } 
            if(abs(v[r2]) == 2) q2--;
            r2--;            
        }        
        
        if(q1 >= q2){            
            l = l1;
            r = r1;
            qtd2 = q1;
        } else{            
            l = l2;
            r = r2;
            qtd2 = q2;
        }
        r = sz-r-1;             

        return make_tuple(l, r, qtd2);        
    };
    
    int ans = 0, ansl =0, ansr = n;
    for (int i = 0; i < m.size(); i++)
    {
        vector<int> v = m[i];
        auto [l, r, qtd2] = calc(v);
        
        int sz = v.size();
        if(qtd2 > ans){
            int st = idx[i];            
            int en = idx[i] + sz;
            ansl = st + l;
            ansr = r + n - en;
            ans = qtd2;
        }
    }
    
    cout << ansl << " " << ansr << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}