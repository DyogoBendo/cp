#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 6e5;
const int SIGMA = 26;

int n;
string s;

int nodes = 0;
int trie[MAX_N][SIGMA];
int fail[MAX_N];
int seen[MAX_N];
int ans[MAX_N];

vector<int> leaf[MAX_N];
vector<int> g[MAX_N];

void add_word(const string &word, const int &idx){
    int node =1;
    for (char ch : word)
    {
        if(trie[node][ch - 'a'] == 0) trie[node][ch - 'a'] = ++nodes;
        node = trie[node][ch - 'a'];
    }

    leaf[node].push_back(idx);
}

void build(){
    queue<int> q;
    int node = 1;
    fail[node] = 1;
    for (int i = 0; i < SIGMA; i++)
    {
        if(trie[node][i]){
            fail[trie[node][i]] = node;
            q.push(trie[node][i]);
        } else{
            trie[node][i] = 1;
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for (int i = 0; i < SIGMA; i++)
        {
            if(trie[node][i]){
                fail[trie[node][i]] = trie[fail[node]][i];
                q.push(trie[node][i]);
            } else{
                trie[node][i] = trie[fail[node]][i];
            }
        }
        
    }

    for (int i = 2; i <= nodes; i++)
    {
        g[fail[i]].push_back(i);
    }
}

void search(){
    int node =1;
    for(char ch: s){
        node = trie[node][ch - 'a'];
        seen[node]++;
    }
}

int dfs(int node){
    int sol = seen[node];
    for (int son : g[node])
    {
        sol += dfs(son);
    }
    for (int idx: leaf[node])
    {
        ans[idx] = sol;
    }

    return sol;
    
}

int main(){
    cin >> s >> n;

	vector<string> words(n);
	for (int i = 0; i < n; i++) {
		cin >> words[i];
		add_word(words[i], i);
	}

	build();
	search();
	dfs(1);

	for (int i = 0; i < n; i++) { cout << (ans[i] ? "YES" : "NO") << '\n'; }
}