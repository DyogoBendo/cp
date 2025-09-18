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

#define int long long

int n, m, q, f, k;
map<string, pair<int, int>> dict_vector;
map<string, int> dict_idx;
vector<string> base;

string get_candidate(vector<string> &words, int idx, int x){    
    for(int i = 0; i < x; i++){
        if(words[f - x + i] != base[idx + i]) return "";
    }
    return base[idx+x];
}

int calc(pair<int, int> v, vector<string> &candidates){
    int tot = 0;    
    for(auto &s : candidates){        
        pair<int, int> w = dict_vector[s];
        tot += v.first*w.first + v.second*w.second;        
    }
    return tot;
}

string solve(vector<string> &words, int x){
    vector<string> candidates;
    for(int i = 0; i < m - x ; i++){
        string c = get_candidate(words, i, x);
        if(c != "") candidates.push_back(c);
    }
    if(candidates.size() == 0) return "";    

    string ans = "";
    int ap = 1e5, bst = 0;

    for(auto [d, v] : dict_vector){
        int similarity = calc(v, candidates);        
        if(similarity > bst){
            bst = similarity;
            ans = d;
            ap = dict_idx[d];
        } else if(similarity == bst and dict_idx[d] < ap){
            ans = d;
            ap = dict_idx[d];
        }
    }
    
    return ans;
}

signed main(){
    darvem;
    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        int x, y;
        cin >> s >> x >> y;
        dict_vector[s] = {x, y};
        dict_idx[s] = i+1;
    }
    
    cin >> m;
    base.resize(m);

    for(int i = 0; i < m; i++) cin >> base[i];
    
    cin >> q >> k;
    while(q--){        
        cin >> f;
        vector<string> words(f);
        for(int i = 0; i < f; i++) cin >> words[i];  
        for(int i = 0; i < f; i++) cout << words[i] << " ";  
        
        bool found = false;
        for(int x = k; x >= 1; x--){
            string ans = solve(words, x);
            if(ans != ""){                
                cout << ans << endl;
                found = true;
                break;
            } 
        }
        if(!found) cout << "*" << endl;
    }

}