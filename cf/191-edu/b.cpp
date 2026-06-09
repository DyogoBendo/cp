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

void fill_2(vector<int> &v, int x){
    v.push_back(x);
    v.push_back(x+1);
    v.push_back(x);
    v.push_back(x+1);
    v.push_back(x+1);
    v.push_back(x);
    v.push_back(x);
    v.push_back(x+1);
};

void fill_3(vector<int> &v, int x){
    v.push_back(x); 
    v.push_back(x);
    v.push_back(x+1);
    v.push_back(x);
    v.push_back(x+1);
    v.push_back(x+2);
    v.push_back(x);
    v.push_back(x+2);
    v.push_back(x+1);
    v.push_back(x+1);
    v.push_back(x+2);
    v.push_back(x+2);
};

void solve(){
    int n;
    cin >> n;

    vector<int> ans;
    if(n & 1){
        for(int i = 1; i < n - 2; i+=2) fill_2(ans, i);
        fill_3(ans, n-2);
    } else{
        for(int i = 1; i < n; i+=2) fill_2(ans, i);
    }

    for(auto x : ans) cout << x << " ";
    cout << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}