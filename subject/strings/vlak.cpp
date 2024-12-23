#include <bits/stdc++.h>

using namespace std;
const int WMAX = 4e5 + 1;

int trie[WMAX][26];
int trie_flag_a[WMAX][26];
int trie_flag_b[WMAX][26];
int node_count;
bool stop[WMAX];

void insert(string word, int flag){
    int node = 0;
    for (char c: word)
    {
        if(trie[node][c - 'a'] == 0) trie[node][c - 'a'] = ++node_count;

        if(!flag)trie_flag_a[node][c - 'a'] = 1;
        else trie_flag_b[node][c - 'a'] = 1;
        node = trie[node][c - 'a'];
    }
    stop[node] = true;
}

int bfs(int node, int p){
    int found = 0;

    for (int i = 0; i < 26; i++)
    {
        if(p == 0){
            if(trie_flag_a[node][i] && !trie_flag_b[node][i]) found = 1;
        } else{
            if(trie_flag_b[node][i] && !trie_flag_a[node][i]) found = 1;
        }
    }
    if(found) return p;

    for (int i = 0; i < 26; i++)
    {
        if(p == 0 && trie_flag_a[node][i]){
            found |= bfs(trie[node][i], (p + 1) % 2) == p;
        } else if(p == 1 && trie_flag_b[node][i]){
            found |= bfs(trie[node][i], (p + 1) % 2) == p;
        }
    }
    if(found) return p;
    else return (p + 1) % 2;    
}


int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        insert(s, 0);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        insert(s, 1);
    }


    if(bfs(0, 0)){
        cout << "Emilija";
    } else{
        cout << "Nina";
    }

    cout << endl;    
    
}