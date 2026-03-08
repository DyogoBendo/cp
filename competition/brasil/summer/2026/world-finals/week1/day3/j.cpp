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

    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<int> flip(n), has_flipped(n);    
    bool can_flip = true;

    int ans = 0;
    for(int b = 30; b >= 0; b--){
        int cnt = 0;
        vector<int> flip_now;        
        for(int i = 0; i < n; i++){
            int x = ((v[i] >> b) & 1) ^ has_flipped[i];
            if(x) cnt++;            
            else if(!x and flip[i] and can_flip) cnt++, flip_now.push_back(i);        

            if(x) flip[i] = 1;
        }
        
        if(cnt == n){
            can_flip = false;
            ans += (1 << b);
            for(auto x : flip_now){
                assert(has_flipped[x] == 0);
                has_flipped[x] = 1;        
            } 
        } 
    }

    cout << ans << endl;
}