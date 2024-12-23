#include <bits/stdc++.h>

using namespace std;

const int NMAX = 5e3;
const int WMAX = 1e6;
const int MOD = 1e9 + 7;

int trie[WMAX][26];
int node_count;
bool stop[WMAX];

void insert(string word){
    int node = 0;
    for (char c: word)
    {
        if(trie[node][c - 'a'] == 0) trie[node][c - 'a'] = ++node_count;

        node = trie[node][c - 'a'];
    }
    stop[node] = true;
}


int main(){
    string s;    

    int n;
    cin >> s >> n;

    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        insert(word);
    }

    vector<int> dp(s.size() + 1);
    dp[s.size()] = 1;

    for (int i = s.size(); i >= 0; i--)
    {
        int node = 0;

        for (int j = i; j < s.size(); j++)
        {
            if(trie[node][s[j] - 'a'] == 0) break;
            node = trie[node][s[j] - 'a'];


            if(stop[node]) dp[i] = (dp[i] + dp[j + 1]) % MOD;
        }
        
    }
    
    cout << dp[0] << endl;
    
}