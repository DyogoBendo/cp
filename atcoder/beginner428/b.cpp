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
    int n, k;
    string s;
    cin >> n >> k >> s;


    int mx = 0;
    set<string> ans;
    for(int i = 0; i <= n - k; i++){
        string t = s.substr(i, k);

        int cnt= 0;
        for(int j = i; j <= n - k; j++){
            string x = s.substr(j, k);
            if(x == t) cnt++;
        }        
        if(cnt > mx){
            ans.clear();
            ans.insert(t);
            mx = cnt;
        } else if(cnt == mx) ans.insert(t);
    }

    cout << mx << endl;
    for(auto a : ans) cout << a << " ";
    cout << endl;
}