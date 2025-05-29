#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<vector<pair<char, int>>> tree(n);

    vector<int> edges(n-1);
    for (int i = 0; i < n-1; i++)
    {
        cin >> edges[i];
    }

    string tmp;
    cin >> tmp;

    for (int i = 0; i < n-1; i++)
    {
        int e = edges[i];
        e--;
        tree[e].push_back({tmp[i], i+1});         
    }

    for (int i = 0; i < n; i++)
    {
        sort(tree[i].begin(), tree[i].end());
    }


    function<vector<pair<char, int>>(int)> dfs2 = [&](int curr){
        vector<pair<char, int>> v;         
        for (auto [c, e] : tree[curr])
        {
            dfs2(e);
        }
        
    };


    int ans = 0;
    vector<int> p;
    string s;
    function<void(int, int, int)> dfs = [&](int curr, int j, int i){                
        vector<int> st(26), mp(26);                
        for (auto [c, e] : tree[curr])
        {                        
            s.push_back(c);
            int idx = c - 'a';
            int n = i + 1;                   
            if(i != 0 && !st[idx]){                
                while (j and s[j] != s[i]) j = p[j-1];        
                if(s[j] == s[i]) j++;  
                
                int k = n - j;                                            
                if(k and j and (n % k == 0)){                                

                    ans= max(ans, k);            
                } 
                mp[idx] = j;
                st[idx] = 1;
            }                                    
            p.push_back(mp[idx]);            
            dfs(e, mp[idx], n);
            s.pop_back();
            p.pop_back();
        }            
    };

    dfs(0, 0, 0);

    cout << ans << endl;
    
}