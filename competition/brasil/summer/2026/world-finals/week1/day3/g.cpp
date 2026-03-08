#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)(a).size())

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

void put(int x){
    cout << "put " << x << endl;    
}

int get(){
    int x;
    cout << "get" << endl;
    cin >> x;
    return x;
}

int cnt = 0;
void solve(){
    int x = 0;    
    while(x != -1 and cnt < 297){
        x = get();
        cnt++;
    }

    put(1);
    put(2);
    x = get();

    if(x == 1) cout << "queue" << endl;
    else cout << "stack" << endl;
}

signed main(){    
    int cases = 1;
    //cin >> cases;
    for (int i=0; i<cases; i++) solve();
}