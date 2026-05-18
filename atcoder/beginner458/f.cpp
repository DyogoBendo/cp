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

#define int ll

const int MOD = 998244353;

signed main(){
    darvem;

    int n, k;
    cin >> n >> k;

    vector<string> v(k);
    for(int i = 0; i < k; i++) cin >> v[i];

    set<string> words;

    map<string, int> mp;
    mp[""] = 0;
    int id_cnt = 0;        
    for(int i = 0; i < k; i++){
        words.insert(v[i]);
        for(int j = 1; j <= sz(v[i]); j++){
            string s = v[i].substr(0, j);
            if(!mp.count(s) and !words.count(s)) mp[s] = ++id_cnt;            
        }
    }

    vector<vector<int>> trans(id_cnt+1, vector<int>(id_cnt+1));

    for(auto [s, id] : mp){
        dbg(s, id);
        string tmp = s;        
        for(char c = 'a'; c <= 'z'; c++){
            tmp.push_back(c);
            bool can = true;
            for(int i = 0; i < sz(tmp); i++){
                string tmp2 = tmp.substr(i);
                if(words.count(tmp2)){
                    can = false;
                    break;
                }                
            }    
            if(can){
                bool found= false;
                for(int i = 0; i < sz(tmp) and !found; i++){
                    string tmp2 = tmp.substr(i);                    
                    if(mp.count(tmp2)){                     
                        if(!found) trans[id][mp[tmp2]]++;
                        found = true;
                    }
                }            
                if(!found) trans[id][0]++;            
            }
            
            tmp.pop_back();
        }
    }


    auto mul = [&](vector<vector<int>> a, vector<vector<int>> b){
        vector<vector<int>> c(id_cnt+1, vector<int>(id_cnt+1));
        for(int i = 0; i < id_cnt+1; i++){
            for(int j = 0; j < id_cnt+1; j++){
                for(int t = 0; t < id_cnt+1; t++){
                    int m = (1LL * a[i][t] * b[t][j]) % MOD;
                    c[i][j] = (c[i][j] + m) % MOD;
                }
            }
        }
        return c;
    };

    auto fexpo = [&](){
        vector<vector<int>> base(id_cnt+1, vector<int>(id_cnt+1));
        for(int i = 0; i < id_cnt+1; i++) base[i][i] = 1;

        while(n){            
            if(n&(1LL)) base = mul(base, trans);            
            trans = mul(trans, trans);
            n >>= 1LL;
        }
        return base;    
    };

    auto calc = fexpo();

    int ans = 0;
    for(int i = 0; i < id_cnt+1; i++) ans = (ans + calc[0][i]) % MOD;
    cout << ans << endl;
}