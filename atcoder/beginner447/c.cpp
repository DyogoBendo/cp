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

    string s, t;
    cin >> s >> t;

    vector<int> cnt_s, cnt_t;    
    vector<char> ls, lt;

    int cnt = 0;
    for(int i = 0; i < sz(s); i++){
        if(s[i] == 'A') cnt++;
        else{
            cnt_s.push_back(cnt);
            cnt = 0;
            ls.push_back(s[i]);
        }
    }
    cnt_s.push_back(cnt);
    
    cnt = 0;
    
    for(int i = 0; i < sz(t); i++){
        if(t[i] == 'A') cnt++;
        else{
            cnt_t.push_back(cnt);
            cnt = 0;
            lt.push_back(t[i]);
        }
    }
    cnt_t.push_back(cnt);

    if(sz(cnt_s) != sz(cnt_t)){
        cout << -1 << endl;
        return 0;
    }

    for(int i = 0; i < sz(ls); i++){
        if(ls[i] != lt[i]){
            cout << -1 << endl;
            return 0;
        }
    }

    int diff = 0;
    for(int i = 0; i < sz(cnt_s); i++){
        diff += abs(cnt_s[i] - cnt_t[i]);
    }

    cout << diff << endl;
}