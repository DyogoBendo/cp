#include <bits/stdc++.h>

using namespace std;
const int WMAX = 1e6;

int trie[WMAX][26];
int node_count;
bool stop[WMAX];

string biggest;
string ans;

void insert(string word){
    int node = 0;

    for (int i = 0; i < word.size(); i++)
    {
        char c = word[i];
        if(trie[node][c - 'a'] == 0) trie[node][c - 'a'] = ++node_count;
        
        node = trie[node][c - 'a'];
    }
    
    stop[node] = true;
}

void dfs(int node, int depth, int flag){    
    if(stop[node]) ans += 'P';
    for (int i = 0; i < 26; i++)
    {
        if((i != biggest[depth] - 'a' || !flag) && trie[node][i]){
            char c = 'a' + i;
            ans += c; 
            dfs(trie[node][i], depth + 1, 0);
            ans += '-';    
        }
    }    
        
    if(depth < biggest.size() && trie[node][biggest[depth] - 'a'] && flag){        
        ans += biggest[depth];        
        dfs(trie[node][biggest[depth] - 'a'], depth + 1, 1);                
    }
    
}

int main(){
    int n;
    cin >> n;
    string s;
    biggest = "";

    for (int i = 0; i < n; i++)
    {
        cin >> s;     
        insert(s);   
        if(s.size() > biggest.size()) biggest = s;
    }
    
    dfs(0, 0, 1);
    cout << ans.size() << endl;
    for (auto c : ans)
    {
        cout << c << endl;
    }
    
}