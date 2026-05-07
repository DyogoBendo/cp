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
    cin >> n >> k;
    vector<vector<int>> v(k);
    vector<int> colored(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;   
        b--;     
        v[b].push_back(a);
        colored[i] = b;
    }
    for(int i = 0; i < k; i++) sort(v[i].rbegin(), v[i].rend());

    bool can = true;
    for(int i = 0; i < n; i++){
        int c = colored[i];        
        if(v[c].back() != i+1) can = false;
        v[c].pop_back();
    }

    cout << (can ? "Y" : "N") << endl;
}