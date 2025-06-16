#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    string m, n;
    cin >> m >> n;

    int y = 0;

    reverse(m.begin(), m.end());
    reverse(n.begin(), n.end());

    vector<int> v1;
    for (int i = 0; i < n.size(); i++)
    {
        int curr = (1 << i);        
        if(n[i] == '1'){
            y += curr;
        } else if(n[i] == '*'){
            v1.push_back(curr);
        }
        
    }

    vector<int> all_n, all_m;
    
    all_n.push_back(y);    
    for (int v : v1)
    {
        vector<int> tmp;

        for (auto k : all_n)
        {
            tmp.push_back(k + v);
        }
        for (auto k : tmp)
        {
            all_n.push_back(k);
        }
    }

    
    for (auto b : all_n)
    {
        if(!b) continue;        
        
        int curr = 1 % b;
        int total = 0;
        vector<pair<int, int>> verify;
        for (int i = 0; i < m.size(); i++)
        {                                                
            if(m[i] == '1') total = (total + curr) % b;
            else if(m[i] == '*') verify.push_back({curr, i});
            curr = (2 * curr) % b;
        }

        vector<pair<int, vector<int>>> ps;
        ps.push_back({total, vector<int>()});
                
        vector<int> ans_idx;
        bool ans_found = false;        
        if(total == 0){
            ans_found = true;            
        } else{
            for (auto v : verify)
            {            
                vector<pair<int, vector<int>>> tmp;                
                for (auto p : ps)
                {
                    vector<int> t = p.second;
                    t.push_back(v.second);
                    int mod = (p.first + v.first) % b;                    
                    tmp.push_back({mod, t});                
                }
    
                for (auto t : tmp)
                {                    
                    ps.push_back(t);
                    ans_idx = t.second;
                    if(t.first == 0){
                        ans_found = true;
                        break;
                    } 
                }             
                if(ans_found) break;       
            }
        }        

        
        if(ans_found){
            string ans = m;                    
    
            for (int i = 0; i < m.size(); i++)
            {
                if(ans[i] == '*'){
                    bool found = false;
                    for (auto idx : ans_idx)
                    {
                        if(i == idx) found = true;
                    }
                    
                    if(found) ans[i] = '1';
                    else ans[i] = '0';
                }
            }    
            
            reverse(ans.begin(), ans.end());
    
            cout << ans << endl;
    
            return 0;        
        }
                
    }
        
    
    
}