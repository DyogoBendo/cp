#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int MAX = 2010;
const int MAX_LOG = 12;

pair<int, int> prefix[MAX];
int suffix[MAX][MAX];
pair<int, int> go[MAX_LOG][MAX][MAX];

namespace aho {
    map<char, int> to[MAX];
    int link[MAX], idx, term[MAX], exit[MAX], sobe[MAX];

    void insert(string& s) {
        int at = 0;
        for (char c : s) {
            auto it = to[at].find(c);
            if (it == to[at].end()) at = to[at][c] = ++idx;
            else at = it->second;
        }
        term[at]++, sobe[at]++;
    }
    void build() {
        queue<int> q;
        q.push(0);
        link[0] = exit[0] = -1;
        while (q.size()) {
            int i = q.front(); q.pop();
            for (auto [c, j] : to[i]) {
                int l = link[i];
                while (l != -1 and !to[l].count(c)) l = link[l];
                link[j] = l == -1 ? 0 : to[l][c];
                exit[j] = term[link[j]] ? link[j] : exit[link[j]];
                if (exit[j]+1) sobe[j] += sobe[exit[j]];
                q.push(j);
            }
        }
    }
    int query(string& s) {
        int at = 0, ans = 0;
        for (char c : s){
            while (at != -1 and !to[at].count(c)) at = link[at];
            at = at == -1 ? 0 : to[at][c];
            ans += sobe[at];            
        }
        return ans;
    }

    void prefix_query(string& s) {
        int at = 0, ans = 0, i = 0;        
        for (char c : s){            
            while (at != -1 and !to[at].count(c)) at = link[at];
            at = at == -1 ? 0 : to[at][c];
            ans += sobe[at];            
            prefix[i++] = {ans, at};               
        }        
    }
}

signed main(){
    //darvem;
    int n, m;
    
    string s;
    cin >> s;
    n = (int) s.size();
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        string cliche;
        cin >> cliche;

        aho::insert(cliche);
    }

    aho::build();
    aho::prefix_query(s);
    int ans = aho::query(s);        

    for (int i = n-1; i >= 0; i--)
    {
        for(int j = 0; j < aho::idx + 1; j++){
            int at = j;
            while (at != -1 and !aho::to[at].count(s[i])) at = aho::link[at];
            at = at == -1 ? 0 : aho::to[at][s[i]];
            int next_s = at;
            suffix[i][j] = aho::sobe[next_s] + suffix[i+1][next_s];            
        }
    }        

    for(int i = 0; i < MAX_LOG; i++){
        for(int pos = (1<<i) - 1; pos < n; pos ++){
            for(int state = 0; state < aho::idx + 1; state++){
                if(i == 0){                    
                    int at = state;
                    while (at != -1 and !aho::to[at].count(s[pos])) at = aho::link[at];
                    at = at == -1 ? 0 : aho::to[at][s[pos]];
                    int next_s = at;
                    go[i][pos][state] = {aho::sobe[next_s], next_s};                    
                } else{
                    auto p1 = go[i-1][pos][state];
                    int prev_state = p1.second;
                    int prev_pos = pos - (1 << (i-1));        
                                  
                    auto p2 = go[i-1][prev_pos][prev_state];
                    go[i][pos][state] = {p1.first + p2.first, p2.second};                    
                }
            }
        }
    }    
        
    for(int i = 0; i < n; i++){
        int st=0, st_state = 0;
        if(i > 0){
            st += prefix[i-1].first;
            st_state = prefix[i-1].second;
        }                
        for(int j = i; j < n; j++){
            int at = st_state;
            int mid = 0;                      
            int sz = j - i + 1;
            int lst = j;
            for(int b = MAX_LOG - 1; b >= 0; b--){
                if(sz & (1 << b)){
                    auto mov = go[b][lst][at];
                    mid += mov.first;
                    at = mov.second;
                    lst -= (1<<b);
                }
            }                        
                        
            ans = max(ans, mid + suffix[j+1][at] + st);            
        }
    }    

    cout << ans << endl;

}
