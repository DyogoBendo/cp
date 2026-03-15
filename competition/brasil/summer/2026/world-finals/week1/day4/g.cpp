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

    int x, b;
    cin >> x >> b;

    if(x >= b){
        cout << -1 << endl;
        return 0;
    }

    int q = b / x;
    int r = b % x;

    vector<int> used(b);

    vector<int> ans;

    dbg(q, r);

    if(r){                
        q++;
        for(int i = 1; i <= r - 1; i++) used[i] = 1;
        ans.push_back(r);
        used[r] = 1;
        
    } else{
        for(int i = 1; i < x; i++) used[i] = 1;    
        ans.push_back(x);
        used[x] = 1;
    }
    for(int i = 0; i < b and sz(ans) < q; i++){
        if(!used[i]) ans.push_back(i);
    }

    for(auto a : ans) cout << a << " ";
    cout << endl;
}