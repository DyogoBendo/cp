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
    pair<char, int> entries[3];
    int cnta = 0;
    for(int i = 0; i < 3; i++){
        cin >> entries[i].first >> entries[i].second;        
        entries[i].first -= 'A';        
        if(entries[i].first) cnta++;        
    }
    
    int cntb = 3 - cnta;    
    if (cnta < cntb){
        cnta = cntb;
        for(int i = 0; i < 3; i++) entries[i].first ^=1;
    }

    int st = 1;
    if(cnta == 2){
        st = 0;
        for(int i = 0; i < 3; i++) if(entries[i].first) entries[i].second--;
    }

    int odd = 0, even = 0, sum_even = 0, sum_odd = 0;
    for(int i = 0; i < 3; i++){
        if(entries[i].second & 1) odd++, sum_odd += entries[i].second;
        else even++, sum_even += entries[i].second;
        dbg(i, entries[i].second);
    }

    dbg(st, odd, even, sum_even, sum_odd);

    if(even == 3) st ^= 1;
    else if(odd == 1) st ^= (sum_odd > sum_even);

    cout << st << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}