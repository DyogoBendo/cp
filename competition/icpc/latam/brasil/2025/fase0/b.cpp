#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    // darvem;

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

    int ans = 0;
    vector<int> p;
    vector<vector<int>> aut(n, vector<int>(26));
    string s;

    function<void(char)> calc_kmp = [&](char ch){
        s.push_back(ch);

        int i = s.size() - 1;

        for (int c = 0; c < 26; c++){
            if(i > 0 && 'a' + c != ch) aut[i][c] = aut[p[i-1]][c];
            else aut[i][c] = i + (s[i] == ('a' + c));
        }

    };

    function<void(int)> dfs = [&](int curr){      
        //cout << "curr: " << curr << endl;
        for (auto [c, e] : tree[curr])
        {                  
            calc_kmp(c);
            int n = s.size();
            int j = n >=2 ? aut[p[n-2]][c - 'a'] : 0;                   
            p.push_back(j);            
            int k = n - j;                                            
            //cout << "c: " << c << " E: " << e << " s: " << s << " j: " << j << " n: " << n << endl;      
            if(k and j and (n % k == 0)){                                
                ans= max(ans, k);            
            }    
            dfs(e);
            s.pop_back();
            p.pop_back();
        }            
        if(s.size()){
            aut.pop_back();
        }
    };

    dfs(0);

    cout << ans << endl;
    
}