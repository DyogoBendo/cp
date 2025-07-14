#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_CHARS = 26;
const int MAX_S = 2005;
const int LOG_MAX_S = 12;

// Using short to save memory for the large DP tables
struct StateInfo {
    short state;
    int count;
};

// Aho-Corasick Automaton
struct AhoCorasick {
    vector<vector<int>> trie;
    vector<int> fail;
    vector<int> matches_at;
    int num_states;

    AhoCorasick() {
        trie.assign(1, vector<int>(MAX_CHARS, 0));
        fail.assign(1, 0);
        matches_at.assign(1, 0);
        num_states = 1;
    }

    void add_pattern(const string& p) {
        int current_node = 0;
        for (char ch : p) {
            int c = ch - 'a';
            if (trie[current_node][c] == 0) {
                trie[current_node][c] = num_states++;
                trie.emplace_back(vector<int>(MAX_CHARS, 0));
                fail.emplace_back(0);
                matches_at.emplace_back(0);
            }
            current_node = trie[current_node][c];
        }
        matches_at[current_node]++;
    }

    void build_failure_links() {
        queue<int> q;
        for (int c = 0; c < MAX_CHARS; ++c) {
            if (trie[0][c]) {
                q.push(trie[0][c]);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int c = 0; c < MAX_CHARS; ++c) {
                if (trie[u][c]) {
                    int v = trie[u][c];
                    fail[v] = trie[fail[u]][c];
                    matches_at[v] += matches_at[fail[v]];
                    q.push(v);
                } else {
                    trie[u][c] = trie[fail[u]][c];
                }
            }
        }
    }
};

AhoCorasick ac;
string s;
int n;

StateInfo forward_run[MAX_S];
vector<int> suffix_run[MAX_S];
StateInfo rev_go[LOG_MAX_S][MAX_S];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    n = s.length();

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string p;
        cin >> p;
        ac.add_pattern(p);
    }
    ac.build_failure_links();
    int num_ac_states = ac.num_states;

    // 1. Forward pass
    forward_run[0] = {0, 0};
    for (int i = 0; i < n; ++i) {
        int prev_state = forward_run[i].state;
        int c = s[i] - 'a';
        int next_s = ac.trie[prev_state][c];
        forward_run[i + 1] = { (short)next_s, forward_run[i].count + ac.matches_at[next_s] };        
    }

    // 2. Suffix precomputation
    for(int i = 0; i <= n; ++i) {
        suffix_run[i].resize(num_ac_states);
    }
    for (int u = 0; u < num_ac_states; ++u) {
        suffix_run[n][u] = 0;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int u = 0; u < num_ac_states; ++u) {
            int c = s[i] - 'a';
            int next_s = ac.trie[u][c];
            suffix_run[i][u] = ac.matches_at[next_s] + suffix_run[i + 1][next_s];            
        }
    }

    // 3. Reverse pass precomputation (Binary Lifting)
    vector<vector<vector<StateInfo>>> rev_go_full(LOG_MAX_S, vector<vector<StateInfo>>(n, vector<StateInfo>(num_ac_states)));

    for(int p=0; p<n; ++p) for(int u=0; u<num_ac_states; ++u) {
        int c = s[p] - 'a';
        int next_s = ac.trie[u][c];
        rev_go_full[0][p][u] = {(short)next_s, ac.matches_at[next_s]};        
    }

    for (int k = 1; k < LOG_MAX_S; ++k) {
        for (int p = (1 << k) - 1; p < n; ++p) {
            for (int u = 0; u < num_ac_states; ++u) {
                StateInfo res1 = rev_go_full[k-1][p][u];
                StateInfo res2 = rev_go_full[k-1][p - (1 << (k - 1))][res1.state];
                rev_go_full[k][p][u] = {(short)res2.state, res1.count + res2.count};
            }
        }
    }


    // 4. Main loop
    int max_matches = forward_run[n].count; // Case with no reversal
    
    for (int i = 0; i < n; ++i) {
        int state_prefix = forward_run[i].state;
        int count_prefix = forward_run[i].count;
        cout << "state: " << state_prefix << endl;
        for (int j = i; j < n; ++j) {

            // Middle part
            int len = j - i + 1;
            StateInfo current_res = {(short)state_prefix, 0};
            int current_pos = j;
            for (int k = LOG_MAX_S - 1; k >= 0; --k) {
                if ((len >> k) & 1) {
                    StateInfo step_res = rev_go_full[k][current_pos][current_res.state];
                    current_res.state = step_res.state;
                    current_res.count += step_res.count;
                    current_pos -= (1 << k);
                }
            }
            int count_middle = current_res.count;
            int state_middle = current_res.state;
            
            // Suffix part
            int count_suffix = suffix_run[j + 1][state_middle];            

            max_matches = max(max_matches, count_prefix + count_middle + count_suffix);
        }
    }

    cout << max_matches << endl;

    return 0;
}