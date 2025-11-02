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


    vector<pair<string, string>> words;
    for(int i = 0; i <= n; i++){
        string s;
        getline(cin, s);
        if(i == 0) continue;

        string s2;
        bool found = false;
        for(int j = 0; j < sz(s); j++){
            if(s[j] >= 'A' and s[j] <= 'Z') found = true;
            if(found) s2 += s[j];
        }
        words.push_back({s2, s});
    }

    sort(words.begin(), words.end());

    for(auto [_, s] : words) cout << s << endl;
}