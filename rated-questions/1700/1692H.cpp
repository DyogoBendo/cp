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

void solve(){
    int n;
    cin >> n;

    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mp[x].push_back(i);
    }

    int bst = 0, bl = 0, br = 0, ba = 0;
    for(auto [x, v] : mp){
        int l = -1, curr = -1, lst = -1;        
        for(auto idx : v){
            int diff = idx - lst - 1;
            if(curr - diff < 0){
                curr = 1;
                l = idx;
            } else{
                curr = curr - diff + 1;
            }
            lst=  idx;            
            if(curr > bst){
                bst = curr;
                bl = l;
                br = lst;
                ba = x;
            }
        }
    }
    cout << ba << " " << bl+1 << " " << br+1 << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}