#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main(){
    int n;
    cin >> n;

    int id_cnt = 0;
    map<string, int> m;
    vector<set<string>> trees;
    vector<vector<int>> tree;
    m["-1/"] = 0;
    trees.push_back(set<string>());
    tree.push_back(vector<int>());

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        
        int prev = 0;
        int lst = 0;
        for (int i = 1; i <= s.size(); i++)
        {            
            if(i == s.size() || s[i] == '/'){
                string curr = s.substr(lst, i - lst);                                   
                if(!trees[prev].count(curr) || i == s.size()){                          
                    trees[prev].insert(curr);                         

                    tree[prev].push_back(++id_cnt);
                    trees.push_back(set<string>());
                    tree.push_back(vector<int>());
                    m[to_string(prev)+curr] = id_cnt;
                } 
                prev = m[to_string(prev)+curr];
                lst = i;
            }
        }                
    }

    vector<pair<int, int>> cost(tree.size());

    function<pair<int, int>(int, int)> dfs = [&](int curr, int prev){        
        pair<int, int> p = {0, 0};        
        for (auto e : tree[curr])
        {                        
            if(e != prev){                    
                auto x= dfs(e, curr);                                
                if(x.second == 0){
                    p.second ++;
                } else{
                    p.second += x.second;
                }
                p.first += x.first;                                
            }
        }    
        p.first += p.second;        
        cost[curr] = p;
        return p;
    };

    int ans = dfs(0, -1).first;    
    function<void(int, int, pair<int, int>)> dfs2 = [&](int curr, int prev, pair<int, int> c){                    
        pair<int, int> p = cost[curr];      
        int cst = c.first;                                
        ans = min(ans, c.first);
        for (auto e : tree[curr])
        {                        
            if(e != prev){                    
                dfs2(e, curr, {
                    c.first + c.second + p.second - 2* cost[e].second,
                    c.second + p.second - cost[e].second
                });                                                
            }
        }                       
    };

    dfs2(0, -1, {ans, 0});
    
    cout << ans << endl;
}