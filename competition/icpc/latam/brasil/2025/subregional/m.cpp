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

int n, k;
bool check(vector<int> &v, int x){
    int r = n;

    bool possible = true;
    for(int i = 0; i < n; i++){
        if(v[i] < x){
            int diff = x - v[i];
            if(i > r) possible = false;
            if(diff > k) possible = false;
            r = min(i + k - diff, r);            
        }        
    }
    return possible;
}

signed main(){
    darvem;

    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];


    int lo = 0, hi = 2e9;

    while(lo < hi){
        int m = (hi - lo) / 2 + lo;
        if(check(v, m)) lo = m + 1;
        else hi = m;
    }
    cout << hi -1 << endl;
}