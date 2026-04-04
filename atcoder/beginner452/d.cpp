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

ll calc(ll x){
    return x* (x-1) / 2;
}

void solve(){
    string s, t;
    cin >> s >> t;

    vector<vector<int>> ap(sz(t));

    for(int i = 0; i < sz(s); i++){
        for(int j = 0; j < sz(t); j++){
            if(s[i] == t[j]) ap[j].push_back(i);
        }
    }
    for(int i = 0; i < sz(t); i++) reverse(ap[i].begin(), ap[i].end());


    ll invalid = 0;
    int prev_l = -1;    
    while(1){
        if(ap[0].empty()) break;        
        int curr = ap[0].back();
        ap[0].pop_back();

        int l = curr;        
        bool possible = true;        
        for(int i = 1; i < sz(t); i++){
            while(!ap[i].empty() and ap[i].back() <= curr ) ap[i].pop_back();
            if(ap[i].empty()){
                possible = false;
                break;
            }                
            curr = ap[i].back();            
        }
                
        if(possible){
            ll cnt_before = (l - prev_l);
            ll cnt_after = (sz(s) - curr);
            dbg(l, curr, prev_l, cnt_before, cnt_after);
            invalid += cnt_before * cnt_after;
            prev_l = l;
        } else{
            break;
        }
    }

    ll tot = calc(sz(s) + 1);
    cout << tot - invalid << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}