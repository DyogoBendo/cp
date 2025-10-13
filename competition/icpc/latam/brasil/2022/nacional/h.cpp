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

signed main(){
    darvem;

    int n, m, r;
    cin >> n;
    vector<string> horses(n);
    map<string, int> horse_map;
    for(int i = 0; i < n; i++){
        cin >> horses[i];
        horse_map[horses[i]] = i;
    } 

    cin >> r;

    map<int, vector<vector<int>>>mp;
    for(int i = 0; i < r; i++){
        int w;
        cin >> m >> w;

        vector<int> v(m);
        for(int j = 0; j < m; j++){
            string s;
            cin >> s;
            v[j] = (horse_map[s]);
        }        
        mp[w-1].push_back(v);
    }

    vector<int> ans(n); 
    set<int> visited;

    queue<int> av;
    for(int i = n - 1; i >= 0; i--){
        auto ma = mp[i];
        vector<int> occ(n);
        int tot = 0;        
        for(auto v : ma){
            tot++;            
            for(auto x : v){                
                occ[x]++;
            }
        }
                
        if(tot == 0){
            av.push(i);
            continue;
        }   
        
        bool found = false;
        for(int j = 0; j < n; j++){
            if(visited.count(j)) continue;

            if(occ[j]){                
                visited.insert(j);
                if(occ[j] == tot and !found){                    
                    found = true;                    
                    ans[i] = j;
                } else{
                    assert(!av.empty());
                    int curr = av.front(); av.pop();                    
                    ans[curr] = j;
                }                
            } 
        }        
    }    

    for(int i = 0; i < n; i++){
        if(!visited.count(i)){
            visited.insert(i);
            assert(!av.empty());
            int curr = av.front(); av.pop();
            ans[curr] = i;
        }
    }

    assert(sz(visited) == n);

    for(int i = 0; i < n; i++) cout << horses[ans[i]] << " ";
    cout << endl;
}