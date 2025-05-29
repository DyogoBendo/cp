#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n;
    cin >> n;
    
    vector<vector<pair<char, int>>> tree(10*n);

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

    int tamanho_total=n;
    function<void(int)> dfs2 = [&](int curr){
        
        vector<vector<int>> filhos (26);
        for (auto [c, e] : tree[curr]){
            filhos[c-'a'].push_back(e);
        }
        vector<pair<char, int>> novas;
        for (int i=0; i<26; i++){
            if (filhos[i].size() == 0) continue;
            tamanho_total++;
            for (auto f: filhos[i]){
                for (auto [c, e]: tree[f]){
                    tree[tamanho_total].push_back({c, e}); 
                }
            }            
            novas.push_back({i+'a', tamanho_total}); // 
            dfs2(tamanho_total);
        }
        tree[curr].clear();
        for (auto [c, e]: novas){
            tree[curr].push_back({c, e});
        }

    };

    dfs2(0);

    int ans = 0;
    vector<int> p;
    string s;
    function<void(int, int, int)> dfs = [&](int curr, int j, int i){
        vector<int> st(26), mp(26);
        for (auto [c, e] : tree[curr])
        {
            s.push_back(c);                        
            int idx = c - 'a';
            int sz = i + 1;
            if(i != 0 && !st[idx]){                
                while (j and s[j] != s[i]) j = p[j-1];
                if(s[j] == s[i]) j++;                

                int k = sz - j;
                if(k and j and (sz % k == 0)){

                    ans= max(ans, k);
                } 
                mp[idx] = j;
                st[idx] = 1;
            }
            p.push_back(mp[idx]);
            dfs(e, mp[idx], sz);
            s.pop_back();
            p.pop_back();
        }
    };

    dfs(0, 0, 0);

    cout << ans << endl;

}