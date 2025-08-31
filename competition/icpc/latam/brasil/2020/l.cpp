#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

char grid[40][40];
int l, c;

bool compare_anagram(string s1, string s2){
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1 == s2;
}

void mark_row(string word, int i, int j, vector<vector<int>> &ap){
    string r = "";
    for(int k = 0; k < word.size() && k + j < c; k++){
        r += grid[i][k+j];
    }
    if(compare_anagram(word, r)){
        for(int k = 0; k < word.size(); k++){
            ap[i][k+j] = 1;
        }   
    }
}

void mark_column(string word, int i, int j, vector<vector<int>> &ap){
    string r = "";
    for(int k = 0; k < word.size() && k + i < l; k++){
        r += grid[k+i][j];
    }
    if(compare_anagram(word, r)){
        for(int k = 0; k < word.size(); k++){
            ap[i+k][j] = 1;
        }   
    }
}

void mark_diagonal(string word, int i, int j, vector<vector<int>> &ap){
    string r = "";
    for(int k = 0; k < word.size() && k + j < c && k + i < l; k++){
        r += grid[i+k][k+j];
    }
    if(compare_anagram(word, r)){
        for(int k = 0; k < word.size(); k++){
            ap[i+k][k+j] = 1;
        }   
    }
}


void mark_reverse_diagonal(string word, int i, int j, vector<vector<int>> &ap){
    string r = "";
    for(int k = 0; k < word.size() && j - k >= 0 && k + i < l; k++){
        r += grid[i+k][j-k];
    }
    if(compare_anagram(word, r)){
        for(int k = 0; k < word.size(); k++){
            ap[i+k][j-k] = 1;
        }   
    }
}

signed main(){
    darvem;

    cin >> l >> c;
    
    for(int i = 0; i < l; i++) for(int j = 0; j < c; j++) cin >> grid[i][j];

    int n;
    cin >> n;

    vector<string> words(n);
    for(int i = 0; i < n; i++) cin >> words[i];
    vector<vector<int>> ans(l, vector<int>(c));    

    for(auto w : words){
        vector<vector<int>> appeared(l, vector<int>(c));

        for(int i = 0; i < l; i++){
            for(int j = 0; j < c; j++){
                mark_row(w, i, j, appeared);
                mark_column(w, i, j, appeared);
                mark_diagonal(w, i, j, appeared);
                mark_reverse_diagonal(w, i, j, appeared);
            }
        }
        for(int i = 0; i < l; i++) for(int j = 0; j < c; j++) ans[i][j] += appeared[i][j];
    }
    
    int tot =0;
    for(int i = 0; i < l; i++) for(int j = 0; j < c; j++) tot += ans[i][j] >= 2;    

    cout << tot << endl;
}