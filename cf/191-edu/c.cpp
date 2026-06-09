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
    int n, k;
    string s;
    cin >> n >> k >> s;


    vector<int> can_remove_open;
    vector<int> can_remove_close;
    int curr_open = 0;
    vector<int> removed(n);
    for(int i = 0; i < n; i++){
        char c = s[i];
        if(c == '('){
            can_remove_open.push_back(i);
            curr_open ++;
        } else{
            if(curr_open > 0){
                can_remove_close.push_back(i);
                curr_open --;
            } else if(curr_open == 0){
                can_remove_close.clear();
                for(auto x : can_remove_open) removed[x] = 1;
                can_remove_open.clear();
            }
        }
    }
    for(auto x : can_remove_close) removed[x] = 1;

    int cnt= 0 ;
    for(int i = 0; i < n; i++){
        if(removed[i] and cnt < k){
            cout << 1;
            cnt++;
        } else cout << 0;
    }
    cout << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}