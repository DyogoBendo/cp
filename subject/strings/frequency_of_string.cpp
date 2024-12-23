#include <bits/stdc++.h>

using namespace std;


const int MAX_N = 2e5 + 10;
const int SIGMA = 26;

map<char, int> to[MAX_N];
int lk[MAX_N], idx, term[MAX_N], ks[MAX_N], len[MAX_N], lst[MAX_N];
vector<int> pos[MAX_N];

void insert(string& s, int i){
    int at = 0;
    for (char c : s)
    {        
        auto it = to[at].find(c);
        if(it == to[at].end()) at = to[at][c] = ++idx;
        else at = it->second;
    }
    lst[at] = at;    
    term[at] = i;
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
        if(!lst[i]) lst[i] = lst[lk[i]];                      
        }
    }        
}

void query(string& s){
    int at = 0;
    int i = 0;
    for (char c : s)
    {        
        while(at != -1 and !to[at].count(c)) at = lk[at];
        at = at == -1 ? 0 : to[at][c];             

        int u = lst[at];
        while(u){                                   
            pos[term[u]].push_back(i), u = lst[lk[u]];
        }
        
        i ++;
    }        
}


int main(){
    string s;
    cin >> s;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int k;
        string m;
        cin >> k >> m;
        ks[i] = k;
        len[i] = m.size();
        insert(m, i);
    }

    build();

    query(s);

    for (int i = 1; i <= n; i++)
    {        
        if(pos[i].size() < ks[i]){
            cout << -1 << endl;
            continue;
        }
        int ans = 1e9;
        for (int j = 0; j + ks[i] - 1 < pos[i].size(); j++)
        {
            ans = min(ans, pos[i][j + ks[i] - 1] - pos[i][j]);
        }
        
        cout << ans + len[i]<< endl;
    }
    
    
    
}