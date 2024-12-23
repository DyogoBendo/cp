#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 6e5;
const int SIGMA = 26;

map<char, int> to[MAX_N];
int lk[MAX_N], idx, a[MAX_N], visited[MAX_N], term[MAX_N];
vector<int> g[MAX_N];
vector<vector<pair<int, int>>> entries;

void insert(string& s, int i){
    int at = 0;
    for (char c : s)
    {        
        auto it = to[at].find(c);
        if(it == to[at].end()) at = to[at][c] = ++idx;
        else at = it->second;
    }    
    term[at]= (i);
}

void build(){
    queue<int> q;
    q.push(0);
    lk[0]  = -1;

    while(q.size()){        
        int i = q.front(); q.pop();
        for(const auto &pair : to[i]){                      
            char c = pair.first;
            int j = pair.second;
            int l = lk[i];            
            while(l != -1 and !to[l].count(c)){                                
                l = lk[l];            
            }             
            lk[j] = l == -1 ?  0 : to[l][c];                        
            q.push(j);
        }
    }    
    for (int i = 1; i <= idx; i++)
    {        
        g[lk[i]].push_back(i);
    }
    
}

void query(string& s){
    int at = 0;
    int i = 0;
    for (char c : s)
    {        
        while(at != -1 and !to[at].count(c)) at = lk[at];
        at = at == -1 ? 0 : to[at][c];        

        if(term[at]){
            entries[term[at]].push_back({i, at});
        }
        i ++;
    }        
}

int bfs(int at){                
    for (auto j: g[at])
    {        
        bfs(j);
    }
    for (auto leaf : term[at])
    {        
        a[leaf] |= found;
    }
    
    return found;
}

int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    entries.resize(n);
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        insert(t, i + 1);
    }

    build();
    query(s);
    bfs(0);

    for (int i = 1; i <= n; i++)
    {
        if(a[i]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    
}